#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "AbstractMediaVisitor.h"
#include <QJsonObject>
class Media;

class JsonVisitor:public AbstractMediaVisitor{

    private:
    QJsonObject jsonObject;

    void saveGenericPart(Media&);
    void clearJsonObject();
    public:

    QJsonObject getJsonObject();

    void visitBook(Book& )override;
    void visitMagazine(Magazine& )override;
    void visitMusicSingle(MusicSingle& )override;
    void visitFilm(Film& )override;

};

#endif