#include "DetailVisitor.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"


void DetailVisitor::visitBook(Book &book){
    setWidget(new DetailView(book));
}
void DetailVisitor::visitMagazine(Magazine &magazine){
    setWidget(new DetailView(magazine));
}

void DetailVisitor::visitMusicSingle(MusicSingle &musicSingle){
    setWidget(new DetailView(musicSingle));
}

void DetailVisitor::visitFilm(Film &film){
    setWidget(new DetailView(film));
}
DetailView* DetailVisitor::getWidget(){
    return dynamic_cast<DetailView*>(WidgetVisitor::getWidget());
}