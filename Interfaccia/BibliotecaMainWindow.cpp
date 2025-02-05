#include "BibliotecaMainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QCloseEvent>
#include <QShortcut>
#include "../Visitors/JsonVisitor.h"

BibliotecaMainWindow::BibliotecaMainWindow(QWidget *parent)
:   QMainWindow(parent),
    toolBar(new MyToolBar(this)),
    searchInterface(new SearchInterface()),
    mainView(new MainView()),
    mainLayout(new QHBoxLayout()),
    addMedia(new QPushButton("Aggiungi ",this)),
    strictTypeSelector(buildStrictTypeSelector())
{   
    //aggiunge toolbar
    this->addToolBar(toolBar);

    //configuriamo il pulsante
    addMedia->setIcon(QIcon(":/icons/aggiungi"));


    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout * mainLayout(new QHBoxLayout(centralWidget));
    QVBoxLayout * secondLayout(new QVBoxLayout());

    secondLayout->addWidget(searchInterface);
    secondLayout->addWidget(strictTypeSelector);
    secondLayout->addWidget(addMedia);

    mainLayout->addLayout(secondLayout);
    
    searchInterface->setFixedWidth(300);
    strictTypeSelector->setFixedWidth(300);
    addMedia->setFixedWidth(300);


    

    mainLayout->addWidget(mainView);

    setWindowTitle("Biblioteca");
    resize(800, 600);

    //connect relative alle modifiche
    connect(mainView,&MainView::propagateModNotification,this,&BibliotecaMainWindow::propagateModNotification);
    connect(searchInterface,&SearchInterface::propagateModNotification,this,&BibliotecaMainWindow::propagateModNotification);


    //connect per il funzionamento dell'interfaccia
    connect(addMedia,&QPushButton::pressed,mainView,[this](){
        mainView->switchToCreateView(strictTypeSelector->currentIndex());
    });

    connect(mainView,&MainView::onDeleteItemPressed,searchInterface,&SearchInterface::removeItem);
    connect(mainView,&MainView::newItemCreated,searchInterface,&SearchInterface::addItem);
    connect(searchInterface,&SearchInterface::itemPressed,mainView,&MainView::ChangeDetailview);

    //connect per il salvataggio file
    connect(this,&BibliotecaMainWindow::propagateModNotification,toolBar,&MyToolBar::onModDetected);
    connect(toolBar,&MyToolBar::onSavePressed,this,&BibliotecaMainWindow::saveToJson);
    connect(toolBar,&MyToolBar::onOpenPressed,this,&BibliotecaMainWindow::openFromJson);

    //shortcut salvataggio dati
    setUpShortcuts();

}

QComboBox* BibliotecaMainWindow::buildStrictTypeSelector(){
    QComboBox* newTypeselector=new QComboBox();

    newTypeselector->insertItem(0,"Libro");
    newTypeselector->insertItem(1,"Rivista");
    newTypeselector->insertItem(2,"Singolo musicale");
    newTypeselector->insertItem(3,"Film");
    newTypeselector->setCurrentIndex(0);

    return newTypeselector;
}


    void BibliotecaMainWindow::saveToJson(){
        QJsonArray mediaArray;
        QVector<ListWidgetMediaItem*> currentMediaList=searchInterface->getAllItem();

        for(auto it=currentMediaList.begin();it!=currentMediaList.end();++it){
            JsonVisitor jsonVisitor;
            QJsonObject media;
            (**it)->accept(jsonVisitor);
            media=jsonVisitor.getJsonObject();
            media["imagePath"]=(**it).getImagePath();

            mediaArray.push_back(media);
        }

        QJsonDocument doc(mediaArray);
        QFile file(toolBar->getFilePath());

        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            qWarning() << "Impossibile salvare i dati nel file JSON.";
            return; 
        }

        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();



    }

    void BibliotecaMainWindow::openFromJson(){
        QFile file(toolBar->getFilePath());

        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
            qWarning() << "Impossibile aprire il file JSON.";
            return;        
        }

        QByteArray Jsonstring =file.readAll();
        file.close();

        QJsonDocument doc=QJsonDocument::fromJson(Jsonstring);

        if (doc.isNull() || !doc.isArray()) {
            qWarning() << "Errore nel parsing del file JSON.";
            return;
        }

        QJsonArray jsonArray=doc.array();

        searchInterface->removeAllItem();
        mainView->clearViews();

        for(const QJsonValue& value:jsonArray){
            if(value.isObject()){
                QJsonObject  mediaObject=value.toObject();

                if(mediaObject.value("type").toString()=="book"){
                    searchInterface->addItem(
                        new ListWidgetMediaItem(
                            Book(
                                mediaObject.value("title").toString(),
                                mediaObject.value("author").toString(),
                                mediaObject.value("year").toInt(),
                                mediaObject.value("genre").toInt(),
                                mediaObject.value("description").toString(),
                                mediaObject.value("pages").toInt(),
                                mediaObject.value("editor").toString(),
                                mediaObject.value("isbn").toString(),
                                mediaObject.value("totalAv").toInt(),
                                mediaObject.value("currentAv").toInt()
                            )           //chiude il costruttore di libro
                            ,mediaObject.value("imagePath").toString()
                        )               //chiude il costruttore di ListWidgetMediaItem
                    );                  //lo aggiunge alla lista
                }
                else if(mediaObject.value("type").toString()=="magazine"){
                    searchInterface->addItem(
                        new ListWidgetMediaItem(
                            Magazine(
                                mediaObject.value("title").toString(),
                                mediaObject.value("author").toString(),
                                mediaObject.value("year").toInt(),
                                mediaObject.value("genre").toInt(),
                                mediaObject.value("description").toString(),
                                mediaObject.value("pages").toInt(),
                                mediaObject.value("editor").toString(),
                                static_cast<Frequency>(mediaObject.value("frequency").toInt()),
                                mediaObject.value("nEdition").toInt(),
                                mediaObject.value("totalAv").toInt(),
                                mediaObject.value("currentAv").toInt()
                            )           //chiude il costruttore di libro
                            ,mediaObject.value("imagePath").toString()
                        )               //chiude il costruttore di ListWidgetMediaItem
                    );                  //lo aggiunge alla lista                    
                }
                else if(mediaObject.value("type").toString()=="musicSingle"){
                    searchInterface->addItem(
                        new ListWidgetMediaItem(
                            MusicSingle(
                                mediaObject.value("title").toString(),
                                mediaObject.value("author").toString(),
                                mediaObject.value("year").toInt(),
                                mediaObject.value("genre").toInt(),
                                mediaObject.value("description").toString(),
                                Duration(mediaObject.value("hour").toInt(),mediaObject.value("minutes").toInt(),mediaObject.value("second").toInt()),
                                mediaObject.value("recordLabel").toString(),
                                mediaObject.value("totalAv").toInt(),
                                mediaObject.value("currentAv").toInt()
                            )           //chiude il costruttore di libro
                            ,mediaObject.value("imagePath").toString()
                        )               //chiude il costruttore di ListWidgetMediaItem
                    );                  //lo aggiunge alla lista                    
                }
                else if(mediaObject.value("type").toString()=="film"){
                    searchInterface->addItem(
                        new ListWidgetMediaItem(
                            Film(
                                mediaObject.value("title").toString(),
                                mediaObject.value("author").toString(),
                                mediaObject.value("year").toInt(),
                                mediaObject.value("genre").toInt(),
                                mediaObject.value("description").toString(),
                                Duration(mediaObject.value("hour").toInt(),mediaObject.value("minutes").toInt(),mediaObject.value("second").toInt()),
                                mediaObject.value("mainActor").toString(),
                                mediaObject.value("totalAv").toInt(),
                                mediaObject.value("currentAv").toInt()
                            )           //chiude il costruttore di libro
                            ,mediaObject.value("imagePath").toString()
                        )               //chiude il costruttore di ListWidgetMediaItem
                    );                  //lo aggiunge alla lista                    
                }

            }
        }    




    }



    void BibliotecaMainWindow::closeEvent(QCloseEvent *event){

        if(!toolBar->isFileSaved()){
            switch(MyToolBar::displayMessageBox()){
                case QMessageBox::Save:
                //save was Pressed
                    toolBar->onSave();
                break;
                case QMessageBox::Discard:
                    // nothing to do
                    event->accept();
                    break;
                case QMessageBox::Cancel:
                    // Cancel was clicked
                    event->ignore();
                    //interrupt the opening of a newFile
                    break;
                default:
                      QMessageBox::warning(this,"Errore","qualcosa è andato storto");
                    break;        

        }            
        }
        else{
            event->accept();
        }

    }



    void BibliotecaMainWindow::setUpShortcuts(){
            QShortcut* saveShortcut = new QShortcut(QKeySequence("Ctrl+s"), this);
            connect(saveShortcut,&QShortcut::activated,toolBar,&MyToolBar::onSave);
    }