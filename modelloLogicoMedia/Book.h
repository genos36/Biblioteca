#ifndef BOOK_H
#define BOOK_H

#include "PaperMedia.h"
#include "ISBN.h"
#include "Genre/BookGenre.h"

class Book:public virtual PaperMedia{
    private:

    ISBN isbn;

    public:
    static int BookGenreToInt(const BookGenre&);
    static QString intToBookGenre(int);
    

    Book();
    Book(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description, 
            int Pages, const QString& Editor,const QString& Isbn,
            int Total, int CurrentAvailability);

    Book(const QString& Title,const QString& Author,int Year,
            const BookGenre& Genre, const QString& Description, 
            int Pages, const QString& Editor,const QString& Isbn,
            int Total, int CurrentAvailability);

    ISBN getIsbn()const;
    QString getGenreName()const override;

    void accept(AbstractMediaVisitor&) override;

    void setIsbn(const QString&);

    bool matchString(const QString &)const override;






};

#endif
