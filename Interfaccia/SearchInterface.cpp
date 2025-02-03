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
startSearchButton(new QPushButton("Cerca",this)),cancelSearchButton(new QPushButton("Annulla",this)),
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
    layout->addWidget(startSearchButton,2,2,1,1);
    cancelSearchButton->setEnabled(false);
    layout->addWidget(cancelSearchButton,2,1,1,1);

    viewSelector->insertWidget(0,genericList);
    viewSelector->insertWidget(1,searchList);

    scrollArea->setWidget(viewSelector);


    mainLayout->addLayout(layout);

    mainLayout->addWidget(scrollArea);

    connect(startSearchButton,&QPushButton::pressed,this,&SearchInterface::startSearch);
    connect(cancelSearchButton,&QPushButton::pressed,this,&SearchInterface::cancelSearch);

    connect(genericList,&ListWidgetMedia::mediaItemPressed,this,&SearchInterface::itemPressed);
    connect(searchList,&ListWidgetMedia::mediaItemPressed,this,&SearchInterface::itemPressed);
     

}

void SearchInterface::startSearch(){
    if(text->text()!=""||typeSelector->currentIndex()!=0){
    isSearchOn=true;
    cancelSearchButton->setEnabled(true);
    searchList->setQuery(Query(text->text()));
    searchList->clear();
    searchList->createFilterSearch(*genericList,typeSelector->currentIndex());
    viewSelector->setCurrentIndex(1);  
    }

}


void SearchInterface::cancelSearch(){
    isSearchOn=false;
    cancelSearchButton->setEnabled(false);
    text->setText("");
    searchList->clear();
    viewSelector->setCurrentIndex(0);
    typeSelector->setCurrentIndex(0);
}

void SearchInterface::removeItem(ListWidgetMediaItem* item){
        if(genericList&&searchList&&item){
            genericList->removeItemAndSync(searchList,item);
        }
    }

void SearchInterface::addItem(ListWidgetMediaItem* newItem){
    if(newItem)genericList->addItem(newItem);
}