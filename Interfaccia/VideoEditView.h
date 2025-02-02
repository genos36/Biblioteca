#ifndef VIDEOEDITVIEW
#define VIDEOEDITVIEW

#include "MultimediaEditView.h"
#include <QComboBox>

class Video;

class VideoEditView:public MultimediaEditView{
    Q_OBJECT
    private:
        QComboBox* videoGenreSelector;
    public:
    static QComboBox* buildVideoGenreSelector();

    VideoEditView(Video&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    VideoEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    int getVideoGenre()const;

};

#endif