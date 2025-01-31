#ifndef DETAILVIEW_H
#define DETAILVIEW_H
#include "WidgetVisitor.h"
#include<QGridLayout>
#include<QPushButton>
#include <QLabel>
class Media;
class DetailView:public WidgetVisitor{
    private:
    QGridLayout* layout;
    QLabel* image;
    QLabel* availability;
    QPushButton* incrementAvailability;
    QPushButton* decrementAvailability;
    void BuildView(Media & media,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    
    public:
    DetailView(Media & media,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    void visitBook(Book&)override;
    void visitMagazine(Magazine&)override;
    void visitMusicSingle(MusicSingle&)override;
    void visitFilm(Film&)override;
};

#endif