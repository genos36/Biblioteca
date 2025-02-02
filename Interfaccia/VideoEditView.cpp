#include "VideoEditView.h"
#include "../modelloLogicoMedia/Video.h"

    VideoEditView::VideoEditView(Video& video,QWidget* parent,const QString& ImagePath):
    MultimediaEditView(video,parent,ImagePath),videoGenreSelector(buildVideoGenreSelector()){
        QLabel* newLabel=new QLabel();
        QGridLayout* layout=new QGridLayout();

        newLabel->setText("Genere:");
        layout->addWidget(newLabel,0,0,1,1);

        videoGenreSelector->setCurrentIndex(video.getGenre());
        layout->addWidget(videoGenreSelector,0,1,1,1);

        addLayout(layout);
    }

    VideoEditView::VideoEditView(QWidget* parent,const QString& ImagePath):
    MultimediaEditView(parent,ImagePath),videoGenreSelector(buildVideoGenreSelector()){
        QLabel* newLabel=new QLabel();
        QGridLayout* layout=new QGridLayout();

        newLabel->setText("Genere:");
        layout->addWidget(newLabel,0,0,1,1);

        videoGenreSelector->setCurrentIndex(0);
        layout->addWidget(videoGenreSelector,0,1,1,1);

        addLayout(layout);
    }

    int VideoEditView::getVideoGenre()const{
        return videoGenreSelector->currentIndex();
    }

    QComboBox* VideoEditView::buildVideoGenreSelector(){
    QComboBox* AudioGenreSelector=new QComboBox();

    AudioGenreSelector->insertItem(0,Video::intToVideoGenre(0));
    AudioGenreSelector->insertItem(1,Video::intToVideoGenre(1));
    AudioGenreSelector->insertItem(2,Video::intToVideoGenre(2));
    AudioGenreSelector->insertItem(3,Video::intToVideoGenre(3));
    return AudioGenreSelector;
    }