#ifndef LISTWIDGETMEDIAITEM_H
#define LISTWIDGETMEDIAITEM_H
#include <QListWidgetItem>
#include <QVector>
#include <QLabel>
#include <QSharedPointer>
#include "../modelloLogicoMedia/Media.h"

class ListWidgetMediaItem:public QListWidgetItem{
    private:
    QSharedPointer<Media> media;
    QString imagePath;

    QLabel* titleLabel;
    QLabel* authorLabel;
    QLabel* yearLabel;
    

    public:
    QWidget* buildGenericDesing(QWidget* parent=nullptr); 
    ListWidgetMediaItem(const Media&,const QString& ImagePath =":/icons/defaultImage",QListWidget * =nullptr);
    ListWidgetMediaItem(const ListWidgetMediaItem& item);
    ~ListWidgetMediaItem();
     ListWidgetMediaItem& operator=(const ListWidgetMediaItem& item);

    Media& operator*();
    const Media& operator*()const;
    Media* operator->();
    const Media* operator->()const;
    ListWidgetMediaItem* clone()const override;
    void refresh();

    QString getImagePath()const;
    void setImagePath(const QString&);

    bool operator==(const ListWidgetMediaItem&);
    bool operator!=(const ListWidgetMediaItem&);

    void refreshDesing();
};

#endif