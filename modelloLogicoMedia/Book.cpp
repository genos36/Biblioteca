#include "Book.h"
#include "../Visitors/AbstractMediaVisitor.h"

Book::Book():PaperMedia::PaperMedia(),isbn("1234567890123"){}

//costruttore con genre come int
Book::Book(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description, 
            int Pages, const QString& Editor,const QString& Isbn,
            int Total, int CurrentAvailability):
            Media(Title,Author,Year,Genre,Description,Total,CurrentAvailability),
            PaperMedia(Title,Author,Year,Genre,Description,Pages,Editor,Total,CurrentAvailability),
            isbn(Isbn){}

//costruttore con genre come bookGenre, ne fornisco 2 versioni per permettere sia l'utilizzo di bookGenre::elemento sia un intero generico
Book::Book(const QString& Title,const QString& Author,int Year,
            const BookGenre& Genre, const QString& Description, 
            int Pages, const QString& Editor,const QString& Isbn,
            int Total, int CurrentAvailability):
            Book(Title,Author,Year,static_cast<int>(Genre),Description,Pages,Editor,Isbn,Total,CurrentAvailability){}


ISBN Book::getIsbn()const{
    return isbn;
}


void Book::setIsbn(const QString& Isbn){
isbn=Isbn;//costruttore di ISBN come convertitore di tipo, fa lui i controlli
}

//ritorna il genere del libro come stringa{}{}
QString Book::getGenreName()const{
    return intToBookGenre(getGenre());
}

//dato un intero ritorna il genere associato nell'enum BookGenre
QString Book::intToBookGenre(int g){
        switch(static_cast<BookGenre>(g)){
        case BookGenre::Fantasy: return "Fantasy";
        case BookGenre::Sci_fy: return "Fantascienza";
        case BookGenre::Thriller : return "Thriller";
        default: return "Altro";
    }
}

//incapsula la conversione da book genre BokkGenre::elemento a intero
//risparmiando un cast esplicito
int BookGenreToInt(const BookGenre& g){
    return static_cast<int>(g);
}


//desing pattern
void Book::accept(AbstractMediaVisitor& visitor){
    visitor.visitBook(*this);
}

//others
bool Book::matchString(const QString& match)const{
    return PaperMedia::matchString(match) ||isbn.startsWith(match,Qt::CaseInsensitive);
}

Book* Book::clone()const{
    return new Book(*this);
}