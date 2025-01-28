#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"
#include "FilterVisitor.h"


//filtra un elemento
void FilterVisitor::addMedia(Media& media){
    media.accept(*this);
}
/*
//overloading per filtrare array di riferimenti
void FilterVisitor::addMedia(const QVector<Media&>& media){
    for(auto cit=media.cbegin();cit!=media.cend();++cit){
        (*cit).accept(*this);
    }
}
*/
//oveloading, filtra elemeti passandoli come puntatori, scarta i puntatori nulli
void FilterVisitor::addMedia(Media* media){
    if(media)media->accept(*this);
}

//overloading per filtrare array di puntatori, scarta i puntatori nulli
void FilterVisitor::addMedia(const QVector<Media*>& media){
    for(auto cit=media.cbegin();cit!=media.cend();++cit){
        if(*cit) (*cit)->accept(*this);
    }
}

void FilterVisitor::visitBook(Book& book){
    books.push_back(&book);
}

void FilterVisitor::visitMagazine(Magazine& magazine){
    magazines.push_back(&magazine);
}

void FilterVisitor::visitMusicSingle(MusicSingle& MusicSingle){
    MusicSingles.push_back(&MusicSingle);
}

void FilterVisitor::visitFilm(Film& film){
    films.push_back(&film);
}

QVector<Book*> FilterVisitor::getBooks()const{
    return books;
}

QVector<Magazine*> FilterVisitor::getmagazines()const{
    return magazines;
}

QVector<MusicSingle*>  FilterVisitor::getMusicSingles()const{
    return MusicSingles;
}

QVector<Film*> FilterVisitor::getfilms()const{
    return films;
}
//non dealloca i puntatori contenuti nei vettori
void FilterVisitor::clean(){
    books=QVector<Book*>();
    magazines=QVector<Magazine*>();
    MusicSingles=QVector<MusicSingle*>();
    films=QVector<Film*>();
}