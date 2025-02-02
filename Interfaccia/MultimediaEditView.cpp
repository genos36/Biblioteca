#include "MultimediaEditView.h"
#include "../modelloLogicoMedia/Multimedia.h"
    MultimediaEditView::MultimediaEditView(Multimedia & media,QWidget* parent,const QString& ImagePath ):
    EditView(media,parent,ImagePath),duration(new DurationSlider(media.getLenght())){
        QGridLayout* layout=new QGridLayout();
        QLabel* newLabel=new QLabel();
        newLabel->setText("Durata:");
        layout->addWidget(newLabel,0,0,1,1);
        duration->setDuration(media.getLenght());
        layout->addWidget(duration,0,1,1,2);


        addLayout(layout);
    }
    
    
    
    MultimediaEditView::MultimediaEditView(QWidget* parent,const QString& ImagePath):
    EditView(parent,ImagePath),duration(new DurationSlider(Duration())){
        QGridLayout* layout=new QGridLayout();
        QLabel* newLabel=new QLabel();
        newLabel->setText("Durata:");
        layout->addWidget(newLabel,0,0,1,1);
        layout->addWidget(duration,0,1,1,2);


        addLayout(layout);
    }


    Duration MultimediaEditView::getDuration()const{
        return Duration(duration->getDuration());
    }