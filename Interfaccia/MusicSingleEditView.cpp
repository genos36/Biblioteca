#include "MusicSingleEditView.h"
#include "../modelloLogicoMedia/MusicSingle.h"

    MusicSingleEditView::MusicSingleEditView(MusicSingle& musicSingle,QWidget* parent,const QString& ImagePath ):
    AudioEditView(musicSingle,parent,ImagePath),recordLabel(new QLineEdit()){
    QGridLayout* layout(new QGridLayout());

    //creiamo la label e la spinBox per l'ISBN
        QLabel* newLabel=new QLabel();
        newLabel->setText("Etichetta discografica:");
        layout->addWidget(newLabel,0,0,1,1);
    
        recordLabel->setText(musicSingle.getRecordLabel());
        layout->addWidget(recordLabel,0,1,1,1); 

        addLayout(layout);
    }


    MusicSingleEditView::MusicSingleEditView(QWidget* parent,const QString& ImagePath ):
    AudioEditView(parent,ImagePath),recordLabel(new QLineEdit()){
    QGridLayout* layout(new QGridLayout());

    //creiamo la label e la spinBox per l'ISBN
        QLabel* newLabel=new QLabel();
        newLabel->setText("Etichetta discografica:");
        layout->addWidget(newLabel,0,0,1,1);
    
        recordLabel->setText("");
        layout->addWidget(recordLabel,0,1,1,1); 

        addLayout(layout);
    }

    QString MusicSingleEditView::getRecordLabel()const{
        return recordLabel->text();
    }


    ListWidgetMediaItem* MusicSingleEditView::createNewMedia()const{
        return new ListWidgetMediaItem(MusicSingle(getTitle(),getAuthor(),getYear(),getAudioGenre(),getDescription(),getDuration(),getRecordLabel(),getTotal(),getCurrent()),getImagePath());
    }


    void MusicSingleEditView::applyMod(ListWidgetMediaItem* targetItem)const{
        if(targetItem ){//controllo nullptr
             if( MusicSingle* musicSingle=dynamic_cast<MusicSingle*>(targetItem->operator->())){//controllo che sia un libro
                musicSingle->setTitle(getTitle());
                musicSingle->setAuthor(getAuthor());
                musicSingle->setYear(getYear());
                musicSingle->setGenre(getAudioGenre());
                musicSingle->setDescription(getDescription());
                musicSingle->setLenght(getDuration());
                musicSingle->setRecordLabel(getRecordLabel());
                musicSingle->setTotal(getTotal());
                musicSingle->setCurrentAvailability(getCurrent());

                targetItem->setImagePath(getImagePath());
                targetItem->refreshDesing();
             }

        }
        
    }
