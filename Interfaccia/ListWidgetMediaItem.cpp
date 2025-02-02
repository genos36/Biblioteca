#include "ListWidgetMediaItem.h"

    /*ridefinizione del costruttore, richiede un media passato per riferimento costante
    invece che con puntatore così da non dover gestire il nullptr , usa il metodo clone di media
    per eseguire la costruzione di copia polimorfa da m, il media di input,
    il parametro 1001 serve a QlistWidgetItem per capire che è un tipo definito da utente*/
    ListWidgetMediaItem::ListWidgetMediaItem(const Media& m,const QString& ImagePath ,QListWidget * parent):
    QListWidgetItem(m.getTitle(),parent,1001),media(m.clone()),imagePath(ImagePath){}


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
