#ifndef QUERY_H
#define QUERY_H

#include <QString>
#include <QVector>
class Media;
class Book;
class Magazine;
class MusicSingle;
class Film;
//si considera come query neutra la stringa "" (stringa vuota)
//quindi "" darà matching su ogni elemento
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
    QVector<MusicSingle*>search(const QVector<MusicSingle*>&)const;
    QVector<Film*>search(const QVector<Film*>&)const;

    bool operator==(const Query&)const;
    bool operator!=(const Query&)const;
    bool hasMatch(const Media&)const;
};

#endif