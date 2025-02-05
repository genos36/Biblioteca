#include "ListWidgetMediaItem.h"
#include <QVBoxLayout>
#include <QLabel>
    /*ridefinizione del costruttore, richiede un media passato per riferimento costante
    invece che con puntatore così da non dover gestire il nullptr , usa il metodo clone di media
    per eseguire la costruzione di copia polimorfa da m, il media di input,
    il parametro 1001 serve a QlistWidgetItem per capire che è un tipo definito da utente*/
    ListWidgetMediaItem::ListWidgetMediaItem(const Media& m,const QString& ImagePath ,QListWidget * parent):
    QListWidgetItem(parent,1001),media(m.clone()),imagePath(ImagePath),
    titleLabel(new QLabel()),authorLabel(new QLabel()),yearLabel(new QLabel()){}


    //oveloading di operator* per l'accesso a media
    Media& ListWidgetMediaItem::operator*(){
        return *media;
    }
    Media* ListWidgetMediaItem::operator->(){
        return media.operator->();
    }
    //oveloading di operator-> per l'accesso a media
    const Media& ListWidgetMediaItem::operator*()const{
        return *media;
    }
    const Media* ListWidgetMediaItem::operator->()const{
        return media.operator->();
    }

    ListWidgetMediaItem* ListWidgetMediaItem::clone()const{
        return new ListWidgetMediaItem(*this);
    }

        void ListWidgetMediaItem::refresh(){
            setText(media->getTitle());
    }

    
    QString ListWidgetMediaItem::getImagePath()const{
        return imagePath;
    }
    void ListWidgetMediaItem::setImagePath(const QString& ImagePath){
        imagePath=ImagePath;
    }

    bool ListWidgetMediaItem::operator==(const ListWidgetMediaItem& item){
        return media==item.media;
    }

    bool ListWidgetMediaItem::operator!=(const ListWidgetMediaItem& item){
        return media!=item.media;
    }

    QWidget* ListWidgetMediaItem::buildGenericDesing(QWidget* parent){
        QWidget* newDesing =new QWidget(parent);
        newDesing->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        QVBoxLayout* layout=new QVBoxLayout(newDesing);
        titleLabel->setText(media->getTitle());
        authorLabel->setText(media->getAuthor());
        yearLabel->setText(QString::number(media->getYear()));

        titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        authorLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        yearLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        layout->addWidget(titleLabel);
        layout->addWidget(authorLabel);
        layout->addWidget(yearLabel);


        newDesing->setLayout(layout);
        newDesing->adjustSize();
        newDesing->setStyleSheet("QWidget { border: 1px solid blue; } QLabel { border: none; }");
        

        return newDesing;
    }


    void ListWidgetMediaItem::refreshDesing(){
        if(media){    
            titleLabel->setText(media->getTitle());
            authorLabel->setText(media->getAuthor());
            yearLabel->setText(QString::number(media->getYear()));


        }

    }