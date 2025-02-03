#ifndef DETAILVIEW_H
#define DETAILVIEW_H
#include<QGridLayout>
#include<QPushButton>
#include <QLabel>
class Media;
class Book;
class Magazine;
class MusicSingle;
class Film;
class DetailView:public QWidget{
        Q_OBJECT

    private:
    QGridLayout* layout;
    QLabel* image;
    QLabel* availability;
    QPushButton* incrementAvailability;
    QPushButton* decrementAvailability;
    void BuildView(Media& media,const QString& ImagePath =":/icons/defaultImage");
    
    public:
    DetailView(Book& book,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    DetailView(Magazine& magazine,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    DetailView(MusicSingle& musicSingle,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    DetailView(Film& film,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    void setImage(const QString& ImagePath);

    signals:
    void propagateModNotification();
};

#endif