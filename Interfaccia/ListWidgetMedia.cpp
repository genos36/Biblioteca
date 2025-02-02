#include "ListWidgetMedia.h"
#include "ListWidgetMediaItem.h"

    ListWidgetMedia::ListWidgetMedia(QWidget *parent ):
    QListWidget(parent){}

    void ListWidgetMedia::addItem(ListWidgetMediaItem* item){
        QListWidget::addItem(item);
    }

    ListWidgetMediaItem* ListWidgetMedia::currentItem()const{
        return dynamic_cast<ListWidgetMediaItem*>(QListWidget::currentItem());
    }

    void ListWidgetMedia::insertItem(int row,ListWidgetMediaItem* item){
        QListWidget::insertItem(row,item);
    }

    ListWidgetMediaItem* ListWidgetMedia::item(int row)const{
        return dynamic_cast<ListWidgetMediaItem*>(QListWidget::item(row));
    }

    ListWidgetMediaItem* ListWidgetMedia::itemAt(const QPoint &p)const{
        return dynamic_cast<ListWidgetMediaItem*>(QListWidget::itemAt(p));
    }

    ListWidgetMediaItem* ListWidgetMedia::itemAt(int x,int y)const{
        return dynamic_cast<ListWidgetMediaItem*>(QListWidget::itemAt(x,y));
    }

    ListWidgetMediaItem* ListWidgetMedia::itemFromIndex(const QModelIndex &index)const{
        return dynamic_cast<ListWidgetMediaItem*>(QListWidget::itemFromIndex(index));
    }

    ListWidgetMediaItem* ListWidgetMedia::takeItem(int row){
        return dynamic_cast<ListWidgetMediaItem*>(QListWidget::takeItem(row));
    }


    QVector<ListWidgetMediaItem*> ListWidgetMedia::getAllMediaItem()const{
        QVector<ListWidgetMediaItem*> result;
        for(int i=0;i<count();++i){
            result.push_back(item(i));
        }
        return result;
    }

    QVector<Media*> ListWidgetMedia::getAllMedia()const{
        QVector<Media*> result;
        for(int i=0;i<count();++i){
            result.push_back(item(i)->operator->());
        }
        return result;
    }

    void ListWidgetMedia::refresh(){
        for(int i=0;i<count();++i){
            item(i)->refresh();
        }
    }


    void ListWidgetMedia::removeItemAndSync(ListWidgetMedia* l, ListWidgetMediaItem* item){
        if(item&& row(item)!=-1){
            delete takeItem(row(item));
        }
        if(l){
        for (int i = 0; i < l->count(); ++i) {
            auto* listItem = dynamic_cast<ListWidgetMediaItem*>(l->item(i));
            if (listItem && *listItem == *item) {  
            // Usa un confronto sui contenuti
                delete l->takeItem(i);
            }
        }
    }
    }

    void ListWidgetMedia::removeItem(ListWidgetMediaItem* item){
        if(item&& row(item)!=-1){
            delete takeItem(row(item));            
        }
    }

    void ListWidgetMedia::addItemAndSync( ListWidgetMedia* l, ListWidgetMediaItem* item){
        if(item&& row(item)==-1){
            addItem(item);
        }
        if(l){
            bool guard=false;
            for(int i=0;!guard&&i<l->count();++i){
                if(item==l->item(i)){
                    guard=true;
                }
            }
            if(guard)l->addItem(item->clone());
        }
    }
