#include "AudioEditView.h"
#include "../modelloLogicoMedia/Audio.h"



    AudioEditView::AudioEditView(Audio& audio,QWidget* parent,const QString& ImagePath ):
    MultimediaEditView(audio,parent,ImagePath), audioGenreSelector(buildAudioGenreSelector()){
        QLabel* newLabel=new QLabel();
        QGridLayout* layout=new QGridLayout();

        newLabel->setText("Genere:");
        layout->addWidget(newLabel,0,0,1,1);

        audioGenreSelector->setCurrentIndex(audio.getGenre());
        layout->addWidget(audioGenreSelector,0,1,1,1);

        addLayout(layout);
    }


    AudioEditView::AudioEditView(QWidget* parent,const QString& ImagePath ):
    MultimediaEditView(parent,ImagePath), audioGenreSelector(buildAudioGenreSelector()){
        QLabel* newLabel=new QLabel();
        QGridLayout* layout=new QGridLayout();

        newLabel->setText("Genere:");
        layout->addWidget(newLabel,0,0,1,1);

        audioGenreSelector->setCurrentIndex(0);
        layout->addWidget(audioGenreSelector,0,1,1,1);

        addLayout(layout);
    }

    int AudioEditView::getAudioGenre()const{
        return audioGenreSelector->currentIndex();
    }

    QComboBox* AudioEditView::buildAudioGenreSelector(){
    
    QComboBox* AudioGenreSelector=new QComboBox();

    AudioGenreSelector->insertItem(0,Audio::intToAudioGenre(0));
    AudioGenreSelector->insertItem(1,Audio::intToAudioGenre(1));
    AudioGenreSelector->insertItem(2,Audio::intToAudioGenre(2));
    AudioGenreSelector->insertItem(3,Audio::intToAudioGenre(3));
    AudioGenreSelector->insertItem(4,Audio::intToAudioGenre(4));

    return AudioGenreSelector;
    }