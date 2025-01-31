#ifndef BOOKEDITVIEW_H
#define BOOKEDITVIEW_H

#include "PaperMediaEditView.h"
#include "../modelloLogicoMedia/Book.h"
#include <QComboBox>
class Book;

class BookEditView:public PaperMediaEditView{
    private:
    QLineEdit* isbn;
    QComboBox* bookGenreSelector;

    public:

    static QComboBox* buildBookGenreSelector();


    BookEditView(Book&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    BookEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    ISBN getIsbn()const;
    int getGenre()const;

    public slots:
    virtual ListWidgetMediaItem* createNewMedia()const override;
    virtual void applyMod(ListWidgetMediaItem*)const override;
};

#endif