#ifndef LISTWIDGETMEDIAITEM_H
#define LISTWIDGETMEDIAITEM_H
#include <QListWidgetItem>
#include <QVector>
#include <QSharedPointer>
#include "../modelloLogicoMedia/Media.h"

class ListWidgetMediaItem:public QListWidgetItem{
    
    private:
    QSharedPointer<Media> media;
    QString imagePath;

    ListWidgetMediaItem(const ListWidgetMediaItem&)=default;
    ListWidgetMediaItem& operator=(const ListWidgetMediaItem &)=default;

    public:
    ListWidgetMediaItem(const Media&,const QString& ImagePath =":/icons/defaultImage",QListWidget * =nullptr);

    Media& operator*();
    const Media& operator*()const;
    Media* operator->();
    const Media* operator->()const;
    ListWidgetMediaItem* clone()const override;
    void refresh();

    QString getImagePath()const;
    void setImagePath(const QString&);

};

#endif