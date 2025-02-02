#ifndef EDITVISITOR_H
#define EDITVISITOR_H
#include "WidgetVisitor.h"

class EditView;

class EditVisitor:public WidgetVisitor{
    public:

    void visitBook(Book&)override;
    void visitMagazine(Magazine&)override;
    void visitMusicSingle(MusicSingle&)override;
    void visitFilm(Film&)override;

    EditView* getWidget()const;
};

#endif