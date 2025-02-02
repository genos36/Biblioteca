#ifndef AUDIOEDITVIEW_H
#define AUDIOEDITVIEW_H
#include "MultimediaEditView.h"
#include "QComboBox"
class Audio;
class AudioEditView:public MultimediaEditView{
    Q_OBJECT
private:
    QComboBox* audioGenreSelector;
public:

    static QComboBox* buildAudioGenreSelector();

    AudioEditView(Audio&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    AudioEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    int getAudioGenre()const;

};



#endif