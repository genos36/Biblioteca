#ifndef LISTWIDGETMEDIA_H
#define LISTWIDGETMEDIA_H
#include <QListWidget>


class ListWidgetMediaItem;
class Media;

class ListWidgetMedia:public QListWidget{
    Q_OBJECT
    public:

    ListWidgetMedia(QWidget *parent = nullptr);

    void addItem(ListWidgetMediaItem* item);

    void addItem(const QString &label)=delete;
    void addItems(const QStringList &labels)=delete;

    ListWidgetMediaItem* currentItem()const;

    void insertItem(int row,ListWidgetMediaItem* item);

    void insertItem(int row,const QString &label)=delete;
    void insertItems(int row,const QStringList &labels)=delete;

    ListWidgetMediaItem* item(int row)const;
    ListWidgetMediaItem* itemAt(const QPoint &p)const;
    ListWidgetMediaItem* itemAt(int x,int y)const;
    ListWidgetMediaItem* itemFromIndex(const QModelIndex &index) const;
    ListWidgetMediaItem* takeItem(int row);

    void refresh();

    QVector<ListWidgetMediaItem*> getAllMediaItem()const;
    QVector<Media*> getAllMedia()const;

    void removeItem(ListWidgetMediaItem* item);
    void removeItemAndSync( ListWidgetMedia* l, ListWidgetMediaItem* item);

};



#endif