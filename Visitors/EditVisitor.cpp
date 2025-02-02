#include "EditVisitor.h"
#include "../Interfaccia/BookEditView.h"
#include "../Interfaccia/MagazineEditView.h"
#include "../Interfaccia/MusicSingleEditView.h"
#include "../Interfaccia/FilmEditView.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"


void EditVisitor::visitBook(Book& book){
    setWidget(new BookEditView(book));
}

void EditVisitor::visitMagazine(Magazine& magazine){
    setWidget(new MagazineEditView(magazine));
}

void EditVisitor::visitMusicSingle(MusicSingle& musicSingle){
    setWidget(new MusicSingleEditView(musicSingle));
}

void EditVisitor::visitFilm(Film& film){
    setWidget(new FilmEditView(film));
}

EditView* EditVisitor::getWidget()const{
    return dynamic_cast<EditView*>(WidgetVisitor::getWidget());
}