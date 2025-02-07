#include "SearchInterface.h"
#include "ListWidgetMedia.h"
#include "SearchListWidgetMedia.h"
#include <QGridLayout>
#include <QLabel>

QComboBox* SearchInterface::buildTypeSelector(){
    QComboBox* box( new QComboBox());
    box->addItem("All");
    box->addItem(QIcon(":/icons/book.png"),"Libri");
    box->addItem(QIcon(":/icons/magazine.png"),"Riviste");
    box->addItem(QIcon(":/icons/CD.png"),"CD");
    box->addItem(QIcon(":/icons/film.png"),"Film");


    return box;
}


SearchInterface::SearchInterface(QWidget *parent):
QWidget(parent),
text(new QLineEdit(this)),typeSelector(buildTypeSelector()),
cancelSearchButton(new QPushButton("Annulla",this)),
scrollArea(new QScrollArea()),viewSelector(new QStackedWidget(scrollArea)),
genericList(new ListWidgetMedia(viewSelector)),searchList(new SearchListWidgetMedia(Query(""),viewSelector)),
isSearchOn(false)
{   
    QVBoxLayout* mainLayout=new QVBoxLayout(this);

    QGridLayout* layout=new QGridLayout();
    layout->addWidget(new QLabel("Cerca: ",this),0,0,1,1);
    layout->addWidget(text,0,1,1,2);
    layout->addWidget(new QLabel("Filtra per tipo: ",this),1,0,1,1);
    layout->addWidget(typeSelector,1,1,1,2);
    cancelSearchButton->setEnabled(false);
    layout->addWidget(cancelSearchButton,2,1,1,1);

    viewSelector->insertWidget(0,genericList);
    viewSelector->insertWidget(1,searchList);

    scrollArea->setWidget(viewSelector);


    mainLayout->addLayout(layout);

    mainLayout->addWidget(scrollArea);

    //aggiustamenti alla taglia
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    





    connect(text,&QLineEdit::textChanged,this,&SearchInterface::startSearch);
    connect(typeSelector,&QComboBox::currentIndexChanged,this,&SearchInterface::startSearch);
    //connect(text,&QLineEdit::textChanged,searchList,&SearchListWidgetMedia::setQuery);
    connect(cancelSearchButton,&QPushButton::pressed,this,&SearchInterface::cancelSearch);

    connect(genericList,&ListWidgetMedia::mediaItemPressed,this,&SearchInterface::itemPressed);
    connect(searchList,&ListWidgetMedia::mediaItemPressed,this,&SearchInterface::itemPressed);
     
    connect(typeSelector,&QComboBox::currentIndexChanged,this,&SearchInterface::onChangeViewPressed);
    connect(text,&QLineEdit::textChanged,this,&SearchInterface::onChangeViewPressed);
    connect(cancelSearchButton,&QPushButton::pressed,this,&SearchInterface::onChangeViewPressed);

}

void SearchInterface::startSearch(){
    if(text->text()!=""||typeSelector->currentIndex()!=0){
    isSearchOn=true;

    genericList->clearSelection();

    cancelSearchButton->setEnabled(true);
    searchList->setQuery(Query(text->text()));
    searchList->clear();

    viewSelector->setCurrentIndex(1);
    //è importante che il cambio di indice del Stacked Widget rimanga prima della crazione della lista di ricerca
    //in caso contrario si verificano glitch grafici
    searchList->createFilterSearch(*genericList,typeSelector->currentIndex());
      
    }
    else{
        cancelSearch();
    }

}


void SearchInterface::cancelSearch(){
    isSearchOn=false;

    searchList->clearSelection();

    cancelSearchButton->setEnabled(false);
    text->setText("");
    searchList->clear();
    viewSelector->setCurrentIndex(0);
    typeSelector->setCurrentIndex(0);
    
}

void SearchInterface::removeItem(ListWidgetMediaItem* item){
        if(genericList&&searchList&&item){
            if(!isSearchOn){
                genericList->removeItemAndSync(searchList,item);
                genericList->clearSelection();
            }
            else {
                searchList->removeItemAndSync(genericList,item);
                searchList->clearSelection();
                }
        }
    }

void SearchInterface::addItem(ListWidgetMediaItem* newItem){
    //l'aggiunta di widget a una lista non visibile causa glitch grafici
    if(viewSelector->currentIndex()==viewSelector->indexOf(searchList)){
        //spostiamo momentaneamente la visibilità sulla lista generica per evitare problemi nel layout
        viewSelector->setCurrentIndex(0);
        if(newItem)genericList->addItem(newItem);
        viewSelector->setCurrentIndex(1);
        startSearch();
        searchList->clearSelection();
        
    }
    else{
        if(newItem)genericList->addItem(newItem);
        genericList->clearSelection();
    }
    
}


    QVector<ListWidgetMediaItem*> SearchInterface::getAllItem(){
        QVector<ListWidgetMediaItem*> result;
        for(int i=0;i<genericList->count();++i){
            result.push_back(genericList->item(i));
        }
        return result;
    }
    
    void SearchInterface::removeAllItem(){
        genericList->clear();
        searchList->clear();
    }
    
//serve a sincronizzare l'imagePath dell'item, le modifiche a media avvengono direttamente essendo media SmartPointer condiviso
    void SearchInterface::syncronizeModOnItem(ListWidgetMediaItem* modifiedItem){
        qDebug()<<"siamo dentro la funzione che dovrebbe fixare l'imagepath"; 

        if(isSearchOn){
            qDebug()<<"siamo dentro l'if della funzione che dovrebbe fixare l'imagepath"; 

            searchList->syncronizeModOnItem(modifiedItem,genericList);
        }
    }

    void SearchInterface::setSelectedItemOnSearchList(ListWidgetMediaItem* item){
        qDebug()<<"siamo dentro la funzione che dovrebbe manteenere coerenti mainview e search";

        if(isSearchOn){
        qDebug()<<"siamo dentro il primo if della funzione che dovrebbe manteenere coerenti mainview e search";
            for(int i=0;i<searchList->count();++i){
                qDebug()<<"siamo dentro il for della della funzione che dovrebbe manteenere coerenti mainview e search";
                if(*item==*(searchList->item(i))){
                    qDebug()<<"stiamo provando a mantenere la coerenza";
                    searchList->setCurrentItem( searchList->item(i),QItemSelectionModel::SelectCurrent);
                    emit itemPressed(searchList->item(i));
                }
                else{
                    qDebug()<<"non è l'item giusto";

                }
            }
        }

    }

    bool SearchInterface::IsSearchOn(){
        return isSearchOn;
    }

    ListWidgetMediaItem* SearchInterface::searchContainsAnItemEqualTo(ListWidgetMediaItem* targetItem){
        return searchList->containsAnItemEqualTo(targetItem);
    }
