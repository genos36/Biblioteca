#include "MyToolBar.h"
#include <QString>
MyToolBar::MyToolBar(QWidget *parent):
        QToolBar(parent),
        open(new QPushButton("Open",this)),
        save(new QPushButton("Save",this)),
        saveAs(new QPushButton("Save as",this))
            {   
                this->addWidget(open);
                this->addWidget(save);
                this->addWidget(saveAs);
                save->setEnabled(false);
                saveAs->setEnabled(false);

                connect(save,&QPushButton::pressed,this,&MyToolBar::onSave);
                connect(saveAs,&QPushButton::pressed,this,&MyToolBar::onSaveAs);
                }

MyToolBar::~MyToolBar(){
    delete saveAs;
    delete save;
    delete open;
}

/*
sfrutta observer per sapere quando sono avvenute modifiche all'interno dell'app
serve a evitare una lunga serie di connect
purtoppo il paramentro passato non viene utilizzato
*/

void MyToolBar::update(Media& media){
        save->setEnabled(true);
        saveAs->setEnabled(true); 
    }

void MyToolBar::onSave(){
    /*
    aggiungi il salvataggio dei file
    */
        save->setEnabled(false);
        saveAs->setEnabled(false);
}

void MyToolBar::onSaveAs(){
    /*
    aggiungi il salvataggio dei file
    */
        save->setEnabled(false);
        saveAs->setEnabled(false);
}