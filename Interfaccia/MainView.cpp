#include "MainView.h"
#include "ListWidgetMediaItem.h"
#include "BookEditView.h"
#include "MagazineEditView.h"
#include "MusicSingleEditView.h"
#include "FilmEditView.h"
#include "../Visitors/EditVisitor.h"
#include "../Visitors/DetailView.h"
#include "MainView.h"
#include<QMessageBox>



MainView::MainView( QWidget* parent):
QWidget(parent),layout(new QGridLayout(this)),viewSelector(new QStackedWidget()),detailView(nullptr),editView(nullptr),
currentMedia(nullptr),editButton(new QPushButton("Modifica")),
cancelButton(new QPushButton("Annulla")),saveModButton(new QPushButton("Conferma")),
createButton(new QPushButton("Crea")),deleteButton(new QPushButton("Elimina")),buttonWrapper(new QStackedWidget()){
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

}


void MainView::setViews(ListWidgetMediaItem* inputItem){
    if(inputItem&&inputItem!=currentMedia){
        currentMedia=inputItem;
        detailView=new DetailView(**inputItem);
        viewSelector->insertWidget(0,detailView->getWidget());
        viewSelector->setCurrentIndex(0);
        editButton->setEnabled(true);

    }
}

void MainView::switchToModView(){
        //se l'editView era già impostata la elimina e la sostituisce
        if(editView)delete editView;

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
        viewSelector->insertWidget(1,editView);
        viewSelector->setCurrentIndex(1);
}


    void MainView::switchToCreateView(int index){

    //se l'editView era già impostata la elimina e la sostituisce
        if(editView)delete editView;

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
    //sistema la pulsangtiera
        cancelButton->setEnabled(true);
        saveModButton->setEnabled(false);
        createButton->setEnabled(true);
        buttonWrapper->setCurrentIndex(2);

    //imposta la visibilità sulla edit View
        viewSelector->insertWidget(1,editView);
        viewSelector->setCurrentIndex(1);
    }

    void MainView::saveAndSwitchToDetailview(){
        if(currentMedia){
            if(editView){
                editView->applyMod(currentMedia);
            }

        cancelButton->setEnabled(true);
        saveModButton->setEnabled(false);
        createButton->setEnabled(false);
        editButton->setEnabled(true);
        buttonWrapper->setCurrentIndex(0);
        if(detailView){
            delete detailView->getWidget();
            delete detailView;
            detailView=new DetailView(**currentMedia);
            viewSelector->insertWidget(0,detailView->getWidget());
        }
        viewSelector->setCurrentIndex(0);
        }
    }

    void MainView::ChangeDetailview(ListWidgetMediaItem* newItem){
        if(currentMedia!=newItem){
            currentMedia=newItem;
            delete detailView->getWidget();
            delete detailView;
            detailView=new DetailView(**newItem);            
            viewSelector->insertWidget(0,detailView->getWidget());
        }
        viewSelector->setCurrentIndex(0);

        buttonWrapper->setCurrentIndex(0);
    }


    ListWidgetMediaItem* MainView::createAndSwitchToDetailview(){
        
        ListWidgetMediaItem* newItem =editView->createNewMedia();
        
        ChangeDetailview(newItem);


        return newItem;
    }

        void MainView::cancelAndSwitchToDetailview(){
            delete editView;
            editView=nullptr;

            ChangeDetailview(currentMedia);

        }
