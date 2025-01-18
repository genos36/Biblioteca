#ifndef QUERY_H
#define QUERY_H

#include <QString>
#include <QVector>
class Media;
class Book;
class Magazine;
class SingleCD;
class Film;

class Query{
    private:
    QString text;
    public:

    Query()=default;
    Query(const QString&);

    virtual ~Query()=default;

    QVector<Media*>search(const QVector<Media*>&)const;
    QVector<Book*>search(const QVector<Book*>&)const;
    QVector<Magazine*>search(const QVector<Magazine*>&)const;
    QVector<SingleCD*>search(const QVector<SingleCD*>&)const;
    QVector<Film*>search(const QVector<Film*>&)const;

};

#endif