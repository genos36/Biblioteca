#ifndef FILMEDITVIEW
#define FILMEDITVIEW
#include "VideoEditView.h"

class Film;

class FilmEditView:public VideoEditView{
    Q_OBJECT
    private:
    QLineEdit* mainActor;
    public:

    FilmEditView(Film&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    FilmEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");


    QString getMainActor()const;


    public slots:
    virtual ListWidgetMediaItem* createNewMedia()const override;
    virtual void applyMod(ListWidgetMediaItem*)const override;
};







#endif