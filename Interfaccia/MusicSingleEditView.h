#ifndef MUSICSINGLEEDITVIEW_H
#define MUSICSINGLEEDITVIEW_H

#include "AudioEditView.h"

class MusicSingle;

class MusicSingleEditView:public AudioEditView{
    Q_OBJECT
    private:
    QLineEdit* recordLabel;
    public:

    MusicSingleEditView(MusicSingle&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    MusicSingleEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    QString getRecordLabel()const;

    public slots:

    virtual ListWidgetMediaItem* createNewMedia()const override;
    virtual void applyMod(ListWidgetMediaItem*)const override;

};

#endif