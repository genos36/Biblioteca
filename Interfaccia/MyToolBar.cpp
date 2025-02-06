#include "MyToolBar.h"
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
MyToolBar::MyToolBar(QWidget *parent):
        QToolBar(parent),
        open(new QPushButton("Open",this)),
        save(new QPushButton("Save",this)),
        saveAs(new QPushButton("Save as",this)),
        filePath(""),
        isSaved(true)
            {   
                this->addWidget(open);
                this->addWidget(save);
                this->addWidget(saveAs);
                save->setEnabled(false);
                connect(save,&QPushButton::pressed,this,&MyToolBar::onSave);
                connect(saveAs,&QPushButton::pressed,this,&MyToolBar::onSaveAs);
                connect(open,&QPushButton::pressed,this,&MyToolBar::onOpen);
                
                }



//se il file è già stato salvato una volta invia il segnale di salvataggio, altrimenti inizia la procedura di salvataggio con nome
    void MyToolBar::onSave(){
        qDebug()<<"inizio il salvataggio del file";
        
        if(!filePath.isEmpty()){
        save->setEnabled(false);

        qDebug()<<"emetto il segnale per salvarlo";
        emit onSavePressed();
        isSaved=true;
        }
        else{
            onSaveAs();
        }
        

    }

//imposta il nuovo filePath e invia il segnale salva il file con nome, se tutto è andato bene
    void MyToolBar::onSaveAs(){

    QString newFilePath=QFileDialog::getSaveFileName(this, "Seleziona come vuoi salvare il file", "", "Json (*.json )");

    if(!newFilePath.isEmpty()){
    
        filePath=newFilePath;
        emit onSavePressed();
        save->setEnabled(false);     
        isSaved=true;   
    }

}

void MyToolBar::onOpen(){
    if(!isSaved){
        switch(displayMessageBox(parentWidget())){
        case QMessageBox::Save:
        //save was Pressed
            onSave();
        break;
        case QMessageBox::Discard:
            // nothing to do
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            return;
            //interrupt the opening of a newFile
            break;
        default:
              QMessageBox::warning(this,"Errore","qualcosa è andato storto");
            break;
        }        
    }

//fa scegliere all'utente il nuovo file da aprire, se il vecchio file
    QString newFilePath=QFileDialog::getOpenFileName(this, "Seleziona file da aprire", "", "Json (*.json )");
            if(!newFilePath.isEmpty()){
                filePath=newFilePath;
                isSaved=true;
                save->setEnabled(false);
                emit onOpenPressed();
            }
            /*
            else{
                QMessageBox::warning(this,"Errore","qualcosa è andato storto nell'apertura del file");
            }
            */


    } 


    void MyToolBar::onModDetected(){
        isSaved=false;
        save->setEnabled(true);
    }


    QString MyToolBar::getFilePath(){
        return filePath;
    }

    bool MyToolBar::isFileSaved(){
        return isSaved;
    }


    int MyToolBar::displayMessageBox(QWidget* parent){
        QMessageBox msgBox(parent);

        msgBox.setText("Il documento è stato modificato.");
        msgBox.setInformativeText("Vuoi salvare le modifiche?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        
        return msgBox.exec();
}

/*

    void MyToolBar::useMessageBox(){
            switch(displayMessageBox()){
                  case QMessageBox::Save:
          // Save was clicked
        break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        default:
              QMessageBox::warning(this,"Errore","qualcosa è andato storto");
            break;
        }

    }

*/