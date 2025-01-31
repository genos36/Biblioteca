#ifndef SEARCHLISTWIDGETMEDIA_H
#define SEARCHLISTWIDGETMEDIA_H
#include "ListWidgetMedia.h"
#include "ListWidgetMediaItem.h"
#include "../Visitors/Query.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"

class SearchListWidgetMedia:public ListWidgetMedia{
private:
    Query query;

    template<class T>
    void createFilteredlist(const ListWidgetMedia& l);
    

public:
    SearchListWidgetMedia(const QString& inputText,QWidget* parent=nullptr);

    void setQuery(const Query& q);
    
    void clearSearchList();//rimuove gli oggetti dalla lista SENZA DEALLOCARLI 

    void createBasicSearch(const QVector<ListWidgetMediaItem*>&);
    void createBasicSearch(const ListWidgetMedia& l);

    
    void createFilterSearch(const ListWidgetMedia& l,int);



};

template<class T>
void SearchListWidgetMedia::createFilteredlist(const ListWidgetMedia& l){
    if(this!=&l){
        clearSearchList();
        for(int i=0;i<l.count();++i){
            if(auto item=l.item(i)){
                if(dynamic_cast<const T*>(item->operator->()) &&query.hasMatch(**item))addItem(item->clone());
            }
        }
    }
}




#endif