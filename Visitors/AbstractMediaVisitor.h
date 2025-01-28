#ifndef ABSTRACTMEDIAVISITOR_H
#define ABSTRACTMEDIAVISITOR_H

class Book;
class Magazine;
class MusicSingle;
class Film;

class AbstractMediaVisitor{
    public:

    virtual void visitBook(Book&)=0;
    virtual void visitMagazine(Magazine&)=0;
    virtual void visitMusicSingle(MusicSingle&)=0;
    virtual void visitFilm(Film&)=0;
    
    virtual ~AbstractMediaVisitor()=default;

};

#endif