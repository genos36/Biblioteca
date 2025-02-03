#include "BibliotecaMainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

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


    

    mainLayout->addWidget(mainView);

    setWindowTitle("Biblioteca");
    resize(800, 600);

    connect(mainView,&MainView::propagateModNotification,this,&BibliotecaMainWindow::propagateModNotification);
    connect(searchInterface,&SearchInterface::propagateModNotification,this,&BibliotecaMainWindow::propagateModNotification);


    connect(addMedia,&QPushButton::pressed,mainView,[this](){
        mainView->switchToCreateView(strictTypeSelector->currentIndex());
    });

    connect(mainView,&MainView::onDeleteItemPressed,searchInterface,&SearchInterface::removeItem);
    connect(mainView,&MainView::newItemCreated,searchInterface,&SearchInterface::addItem);
    connect(searchInterface,&SearchInterface::itemPressed,mainView,&MainView::ChangeDetailview);
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