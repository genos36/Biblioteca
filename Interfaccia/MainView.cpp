#include "MainView.h"
#include "ListWidgetMediaItem.h"
#include "BookEditView.h"
#include "MagazineEditView.h"
#include "MusicSingleEditView.h"
#include "FilmEditView.h"
#include "../Visitors/EditVisitor.h"
#include "../Visitors/DetailVisitor.h"
#include "DetailView.h"
#include "MainView.h"
#include<QMessageBox>




MainView::MainView( QWidget* parent):
QWidget(parent),layout(new QGridLayout(this)),viewSelector(new QStackedWidget()),
detailView(nullptr),editView(nullptr),
currentMedia(nullptr),editButton(new QPushButton("Modifica")),
cancelButton(new QPushButton("Annulla")),saveModButton(new QPushButton("Conferma")),
createButton(new QPushButton("Crea")),deleteButton(new QPushButton("Elimina")),
buttonWrapper(new QStackedWidget()){
    //QVBoxLayout* mainLayout=new QVBoxLayout(this);

    layout->addWidget(viewSelector,0,0,1,2);
    editButton->setEnabled(false);
    cancelButton->setEnabled(false);
    saveModButton->setEnabled(false);
    createButton->setEnabled(false);

    buttonWrapper->insertWidget(0,editButton);
    buttonWrapper->insertWidget(1,saveModButton);
    buttonWrapper->insertWidget(2,createButton);
    buttonWrapper->setCurrentIndex(0);

    layout->addWidget(cancelButton,1,0,1,1);
    layout->addWidget(buttonWrapper,1,1,1,1);
    layout->addWidget(deleteButton,3,1,1,1);

    viewSelector->setMinimumSize(viewSelector->size());

    connect(saveModButton,&QPushButton::pressed,this,&MainView::propagateModNotification);
    connect(deleteButton,&QPushButton::pressed,this,&MainView::propagateModNotification);
    connect(createButton,&QPushButton::pressed,this,&MainView::propagateModNotification);
    //connect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);

    connect(saveModButton,&QPushButton::pressed,this,&MainView::saveAndSwitchToDetailview);
    //connect(createButton,&QPushButton::pressed,this,&MainView::createAndSwitchToDetailview);
    connect(editButton,&QPushButton::pressed,this,&MainView::switchToModView);
    connect(cancelButton,&QPushButton::pressed,this,&MainView::cancelAndSwitchToDetailview);
    connect(createButton,&QPushButton::pressed,this,&MainView::createAndSwitchToDetailview);

    connect(deleteButton,&QPushButton::pressed,this,[this](){
        destroyDetailView();
        destroyEditView();
        emit onDeleteItemPressed(currentMedia);
    });

}

EditView* MainView::buildEditView(ListWidgetMediaItem* inputItem){
        EditVisitor editViewBuilder;
        (*inputItem)->accept(editViewBuilder);
        (editViewBuilder.getWidget())->setImagePath(inputItem->getImagePath());
        return editViewBuilder.getWidget();
}

DetailView* MainView::buildDetailView(ListWidgetMediaItem* inputItem){
        DetailVisitor detailViewBuilder;
        (*inputItem)->accept(detailViewBuilder);
        (detailViewBuilder.getWidget())->setImage(inputItem->getImagePath());
        return detailViewBuilder.getWidget();
}

void MainView::destroyEditView(){
    if(editView){
        viewSelector->removeWidget(editView);
        delete editView;
        editView=nullptr;

    }
        
    }

void MainView::destroyDetailView(){
    if(detailView){
        disconnect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);
        viewSelector->removeWidget(detailView);
        delete detailView;
        detailView=nullptr;
        }

    }



void MainView::setEditView(EditView* newEditView){
    //destroyEditView();
    editView=newEditView;

    if(editView){
        viewSelector->insertWidget(viewSelector->count(),editView);
    }
}

void MainView::setDetailView(DetailView* newDetailView){
    destroyDetailView();
    detailView=newDetailView;
    connect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);

    if(detailView){
        viewSelector->insertWidget(viewSelector->count(),detailView);
    }

}

void MainView::showDetailView(){
    if(detailView){
        viewSelector->setCurrentIndex(viewSelector->indexOf(detailView));
    }
}

void MainView::showEditView(){
    if(editView){
        viewSelector->setCurrentIndex(viewSelector->indexOf(editView));
    }
    
}

void MainView::ChangeDetailview(ListWidgetMediaItem* newItem){


        destroyDetailView();
        setDetailView(buildDetailView(newItem));
        showDetailView();
        setButtonsForViewMod();
        //if(currentMedia!=newItem)currentMedia=newItem;
        currentMedia=newItem;

    }


    void MainView::refreshDetailView(){
            ChangeDetailview(currentMedia);
       }


    void MainView::setButtonsForViewMod(){
        editButton->setEnabled(true);
        deleteButton->setEnabled(true);    

        cancelButton->setEnabled(false);
        createButton->setEnabled(false);
        saveModButton->setEnabled(false);

        buttonWrapper->setCurrentIndex(0);

    }

    void MainView::setButtonsForModificationMod(){
        cancelButton->setEnabled(true);
        deleteButton->setEnabled(true);    
        saveModButton->setEnabled(true);

        createButton->setEnabled(false);
        editButton->setEnabled(false);

        buttonWrapper->setCurrentIndex(1);        
    }    

    void MainView::setButtonsForCreationMod(){

        cancelButton->setEnabled(true);
        createButton->setEnabled(true);

        editButton->setEnabled(false);
        deleteButton->setEnabled(false);    
        saveModButton->setEnabled(false);

        buttonWrapper->setCurrentIndex(2);

    }


void MainView::setViews(ListWidgetMediaItem* inputItem){
    if(inputItem&&inputItem!=currentMedia){
        currentMedia=inputItem;
        
        ChangeDetailview(currentMedia);

    }
}




void MainView::switchToModView(){
    
    destroyEditView();
    setEditView(buildEditView(currentMedia));
    showEditView();
    setButtonsForModificationMod();
 


}


    void MainView::switchToCreateView(int index){


    destroyEditView();

    //prevedo di connetterlo usando una QComboBox per scegliare cosa creare (libro,rivista,...)
        switch(index){
            case 0:
                editView=new BookEditView();
                break;
            case 1:
                editView=new MagazineEditView();
                break;
            case 2:
                editView=new MusicSingleEditView();
                break;
            case 3:
                editView=new FilmEditView();
                break;
            default:
                QMessageBox::warning(this,"Errore","qualcosa è andato storto nell'inizializzazione del costruttore");
                viewSelector->setCurrentIndex(0);
                cancelButton->setEnabled(false);
                saveModButton->setEnabled(false);
                createButton->setEnabled(false);
                }
    qDebug()<<"edit view creata con successo";
    setEditView(editView);
    qDebug()<<"edit view montata con successo";
    setButtonsForCreationMod();
    qDebug()<<"pulsantiera impostata con successo";
    showEditView();
        qDebug()<<"stiamo mostrando il widget";

    }

    void MainView::saveAndSwitchToDetailview(){
        
        if(currentMedia){
        
            if(editView){
            qDebug()<<"inizio salvataggio";     
                editView->applyMod(currentMedia);
                
            }
        if(!currentMedia)qDebug()<<"il puntatore current media è nullo dopo le operazioni su detail view";
        //viewSelector->removeWidget(editView);
        ChangeDetailview(currentMedia);
        //viewSelector->insertWidget(viewSelector->count(),editView);
/*
        
        setButtonsForViewMod();
        showDetailView();
        
*/      
        } 

    }

    ListWidgetMediaItem* MainView::createAndSwitchToDetailview(){
        ListWidgetMediaItem* newItem=nullptr;
        if(editView){
            newItem =editView->createNewMedia();
            emit newItemCreated(newItem);
        }
        
        viewSelector->removeWidget(editView);
        ChangeDetailview(newItem);
        viewSelector->insertWidget(viewSelector->count(),editView);


        return newItem;
    }

void MainView::cancelAndSwitchToDetailview(){
            destroyEditView();
            if(currentMedia)ChangeDetailview(currentMedia);

        }
