#include "BibliotecaMainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

BibliotecaMainWindow::BibliotecaMainWindow(QWidget *parent)
:   QMainWindow(parent),
    toolBar(new MyToolBar(this)),
    mediaList(new QListWidget(this)),
    searchList(nullptr),                // inserire il costruttore quando lo avrò
    views(new QStackedWidget(this)),
    lists(new QStackedWidget(this)),
    searchInterface(new SearchInterface(this)),
    scrollArea(new QScrollArea(this)),
    addMedia(new QPushButton("Aggiungi ",this))
{   
    //aggiunge toolbar
    this->addToolBar(toolBar);

    //configuriamo il pulsante
    addMedia->setIcon(QIcon(":/icons/aggiungi"));


    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout * mainLayout(new QHBoxLayout(centralWidget));
    QVBoxLayout * searchLayout(new QVBoxLayout);

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(mediaList);

    //searchLayout->setMaximumSize(100, 300); // Larghezza massima: 400, altezza massima: 300

    mainLayout->addLayout(searchLayout);
    searchLayout->addWidget(searchInterface);
    searchLayout->addWidget(scrollArea);
    
    searchLayout->addWidget(addMedia);

    mainLayout->addWidget(views);

    setWindowTitle("Biblioteca");
    resize(800, 600);
}