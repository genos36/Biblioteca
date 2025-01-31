#ifndef EDITVIEW_H
#define EDITVIEW_H
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "ListWidgetMediaItem.h"
class Media;
class Book;
class Magazine;
class MusicSingle;
class Film;

class EditView:public QWidget{
    private:
    //void buildGenericEdit(Media&,const QString& ImagePath =":/icons/defaultImage");
    QVBoxLayout* mainLayout;
    QLabel* image; 
    QPushButton* changeImage;
    QLineEdit* title;
    QLineEdit* author;
    QSpinBox* year;
    QLineEdit* description;
    QSpinBox* total;
    QSpinBox* current;

    

    QPushButton* cancel;
    QPushButton* confirm;
    QString imagePath;
    
    public:
    
    static int addImagePathToResourceFile();

    EditView(Media&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    EditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    QString getTitle()const;
    QString getAuthor()const;
    int getYear()const;
    QString getDescription()const;
    int getTotal()const;
    int getCurrent()const;

    QString getImagePath()const;
    void setImagePath(const QString&);


    public slots:
    void changeImageSlot();
    virtual ListWidgetMediaItem* createNewMedia()const=0;
    virtual void applyMod(ListWidgetMediaItem)const=0;

};


#endif