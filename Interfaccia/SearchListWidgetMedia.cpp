#include "SearchListWidgetMedia.h"
#include <QDebug>
#include "../modelloLogicoMedia/Media.h"

SearchListWidgetMedia::SearchListWidgetMedia(const QString& inputText,QWidget* parent):
ListWidgetMedia(parent),query(inputText){}

void SearchListWidgetMedia::clearSearchList(){
    while(count()>0){
       takeItem(0); 
    }
}

void SearchListWidgetMedia::setQuery(const Query& q){
    if(query!=q){
        query=q;
        clear();
    }
}

    void SearchListWidgetMedia::createBasicSearch(const QVector<ListWidgetMediaItem*>& v){
        clear();
        for(auto cit=v.cbegin();cit!=v.cend();++cit){
            if((*cit)&&query.hasMatch((*cit)->operator*())){//richiamo esplicitamente l'overloading di operator* per leggibilità
                addItem(*cit);
            }
        }
    }

    void SearchListWidgetMedia::createBasicSearch(const ListWidgetMedia& l){
        if(&l!=this){
        clear();
        for(int i=0;i<l.count();++i){
            if(auto item=l.item(i)){
                if(query.hasMatch(**item)){
                    addItem(item->clone());
                    qDebug()<<"Ho inserito l'item"<<(**item).getTitle();
                }
            }
        }
    }
    }



    void SearchListWidgetMedia::createFilterSearch(const ListWidgetMedia& l,int i){
        switch (i)
        {
        case 0:
            createFilteredlist<Book>(l);
        break;
        case 1:
            createFilteredlist<Magazine>(l);
        break;
        case 2:
            createFilteredlist<MusicSingle>(l);
        break;
        case 3:
            createFilteredlist<Film>(l);
        break;
        
        default:
            break;
        }
    }


