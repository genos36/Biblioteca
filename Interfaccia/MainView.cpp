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

    connect(saveModButton,&QPushButton::pressed,this,&MainView::propagateModNotification);
    connect(deleteButton,&QPushButton::pressed,this,&MainView::propagateModNotification);
    connect(createButton,&QPushButton::pressed,this,&MainView::propagateModNotification);
    //connect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);

    connect(saveModButton,&QPushButton::pressed,this,&MainView::saveAndSwitchToDetailview);
    //connect(createButton,&QPushButton::pressed,this,&MainView::createAndSwitchToDetailview);
    connect(editButton,&QPushButton::pressed,this,&MainView::switchToModView);
}

EditView* MainView::buildEditView(ListWidgetMediaItem* inputItem){
        EditVisitor editViewBuilder;
        (*inputItem)->accept(editViewBuilder);
        return editViewBuilder.getWidget();
}

DetailView* MainView::buildDetailView(ListWidgetMediaItem* inputItem){
        DetailVisitor detailViewBuilder;
        (*inputItem)->accept(detailViewBuilder);
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
    destroyEditView();
    editView=newEditView;

    if(editView){
        viewSelector->insertWidget(1,editView);
    }
}

void MainView::setDetailView(DetailView* newDetailView){
    destroyDetailView();
    detailView=newDetailView;
    connect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);

    if(detailView){
        viewSelector->insertWidget(1,detailView);
    }

}

void MainView::showDetailView(){
    if(detailView){
        viewSelector->setCurrentIndex(0);
    }
}

void MainView::showEditView(){
    if(editView){
        viewSelector->setCurrentIndex(1);
    }
    
}

void MainView::ChangeDetailview(ListWidgetMediaItem* newItem){


        destroyDetailView();
        setDetailView(buildDetailView(newItem));
        showDetailView();
        setButtonsForViewMod();
        currentMedia=newItem;
        /*        
        if(newItem){
            currentMedia=newItem;
            if(detailView){
                disconnect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);
                viewSelector->removeWidget(detailView);
                delete detailView;
                detailView=nullptr;
                }
           
            DetailVisitor detailViewBuilder;
            detailView=detailViewBuilder.getWidget();

        if(detailView){
            connect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);
            viewSelector->insertWidget(0,detailView);
            detailView->setImage(currentMedia->getImagePath());
            viewSelector->setCurrentIndex(0);

            buttonWrapper->setCurrentIndex(0);            
            }

        }
        */

        

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
        /*
        DetailVisitor detailViewBuilder;
        detailView=detailViewBuilder.getWidget();
        detailView->setImage(currentMedia->getImagePath());
        viewSelector->insertWidget(0,detailView);
        connect(detailView,&DetailView::propagateModNotification,this,&MainView::propagateModNotification);
        viewSelector->setCurrentIndex(0);
        editButton->setEnabled(true);

        */

    }
}




void MainView::switchToModView(){
    
    destroyEditView();
    setEditView(buildEditView(currentMedia));
    showEditView();
    setButtonsForModificationMod();
 
/*
 
        //se l'editView era già impostata la elimina e la sostituisce
        if(editView){
            viewSelector->removeWidget(editView);
            delete editView;
            editView=nullptr;
        ;}

    //sistema la pulsangtiera
        cancelButton->setEnabled(true);
        saveModButton->setEnabled(true);
        createButton->setEnabled(false);
        buttonWrapper->setCurrentIndex(1);

    //usa il visitor per genereare la editView appropriata
        EditVisitor editViewGenerator;
        (*currentMedia)->accept(editViewGenerator);
    //monta la edit view
        editView=editViewGenerator.getWidget();
    //imposta la visibilità sulla edit View, bisogna reinserirlo perche il vecchio puntatore non è più valido
        
        if(editView){
        viewSelector->insertWidget(1,editView);
        viewSelector->setCurrentIndex(1);
        }

*/

}


    void MainView::switchToCreateView(int index){


/*
    //se l'editView era già impostata la elimina e la sostituisce
        if(editView){
            viewSelector->removeWidget(editView);
            delete editView;
            editView=nullptr;
            }

*/
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

    setButtonsForCreationMod();
    showEditView();
    /*
    //sistema la pulsangtiera
        cancelButton->setEnabled(true);
        saveModButton->setEnabled(false);
        createButton->setEnabled(true);
        buttonWrapper->setCurrentIndex(2);

    //imposta la visibilità sulla edit View
        if(editView){
            viewSelector->insertWidget(1,editView);
            viewSelector->setCurrentIndex(1);
        }    
    */

    }

    void MainView::saveAndSwitchToDetailview(){
        if(currentMedia){
            if(editView){
                editView->applyMod(currentMedia);
            }

        setButtonsForViewMod();
        showDetailView();

/*
        cancelButton->setEnabled(true);
        saveModButton->setEnabled(false);
        createButton->setEnabled(false);
        editButton->setEnabled(true);
        buttonWrapper->setCurrentIndex(0);
        if(detailView){
            ChangeDetailview(currentMedia);
        }
        viewSelector->setCurrentIndex(0);
         
*/

        } 
    }

    ListWidgetMediaItem* MainView::createAndSwitchToDetailview(){
        ListWidgetMediaItem* newItem=nullptr;
        if(editView){
            newItem =editView->createNewMedia();
        }
        
        
        ChangeDetailview(newItem);


        return newItem;
    }

void MainView::cancelAndSwitchToDetailview(){


/*

            viewSelector->removeWidget(editView);
            delete editView;
            editView=nullptr;

*/

            destroyEditView();
            ChangeDetailview(currentMedia);

        }
