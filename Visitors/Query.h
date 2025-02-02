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
//nota:query è polimorfa, quindi permette di creare nuove sottoclassi query per realizzare ricerche con criteri diversi
//inizialmente volevo creare una sottoclasse di query che realizzasse una ricerca più fine, cercare match anche su singole parole
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

    virtual bool operator==(const Query&)const;
    virtual bool operator!=(const Query&)const;
    virtual bool hasMatch(const Media&)const;
    virtual Query* clone()const;

};

#endif