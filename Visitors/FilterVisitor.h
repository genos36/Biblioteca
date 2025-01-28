#ifndef FILTERVISITOR_H
#define FILTERVISITOR_H
#include "AbstractMediaVisitor.h"
#include <QVector>

class Media;


class FilterVisitor:public AbstractMediaVisitor{
    private:
    QVector<Book*> books;
    QVector<Magazine*> magazines;
    QVector<MusicSingle*> MusicSingles;
    QVector<Film*> films; 

    public:

    void visitBook(Book&) override;
    void visitMagazine(Magazine&) override;
    void visitMusicSingle(MusicSingle&) override;
    void visitFilm(Film&) override;

    QVector<Book*> getBooks()const;
    QVector<Magazine*> getmagazines()const;
    QVector<MusicSingle*> getMusicSingles()const;
    QVector<Film*> getfilms()const;

    void addMedia(Media&);
    void addMedia(Media*);
    void addMedia(const QVector<Media*>&);
    //void addMedia(const QVector<Media&>&);
    void clean();

    

};



#endif