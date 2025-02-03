#ifndef DETAILVISITOR_H
#define DETAILVISITOR_H

#include "../Interfaccia/DetailView.h"
#include "WidgetVisitor.h"




class DetailVisitor :  public WidgetVisitor{
    public:

    void visitBook(Book&)override;
    void visitMagazine(Magazine&)override;
    void visitMusicSingle(MusicSingle&)override;
    void visitFilm(Film&)override;

    DetailView* getWidget();

};

#endif