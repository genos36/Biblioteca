#include "FilmEditView.h"
#include "../modelloLogicoMedia/Film.h"
    
    FilmEditView::FilmEditView(Film& film,QWidget* parent,const QString& ImagePath):
    VideoEditView(film,parent,ImagePath),mainActor(new QLineEdit()){
        
        QLabel* newLabel=new QLabel();
        QGridLayout* layout=new QGridLayout();
    
        newLabel->setText("Attore principale:");
        layout->addWidget(newLabel,0,0,1,1);
    
        mainActor->setText(film.getMainActor());
        layout->addWidget(mainActor,0,1,1,1);
    
        addLayout(layout);
    
    }
    
    FilmEditView::FilmEditView(QWidget* parent,const QString& ImagePath):
    VideoEditView(parent,ImagePath),mainActor(new QLineEdit()){
        
        QLabel* newLabel=new QLabel();
        QGridLayout* layout=new QGridLayout();
    
        newLabel->setText("Attore principale:");
        layout->addWidget(newLabel,0,0,1,1);
    
        mainActor->setText("");
        layout->addWidget(mainActor,0,1,1,1);
    
        addLayout(layout);
    
    }
    
    QString FilmEditView::getMainActor()const{
        return mainActor->text();
    }
    
    ListWidgetMediaItem* FilmEditView::createNewMedia()const{
            return new ListWidgetMediaItem(Film(getTitle(),getAuthor(),getYear(),getVideoGenre(),getDescription(),getDuration(),getMainActor(),getTotal(),getCurrent()),getImagePath());
        }
    
    void FilmEditView::applyMod(ListWidgetMediaItem* targetItem)const{

        if(targetItem ){//controllo nullptr
             if( Film* film=dynamic_cast<Film*>(targetItem->operator->())){//controllo che sia un libro
                film->setTitle(getTitle());
                film->setAuthor(getAuthor());
                film->setYear(getYear());
                film->setGenre(getVideoGenre());
                film->setDescription(getDescription());
                film->setLenght(getDuration());
                film->setMainActor(getMainActor());
                film->setTotal(getTotal());
                film->setCurrentAvailability(getCurrent());

                targetItem->setImagePath(getImagePath());
                targetItem->refreshDesing();
             }

        }
    }