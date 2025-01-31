#include "BookEditView.h"

    BookEditView::BookEditView(Book& book,QWidget* parent,const QString& ImagePath )
    :PaperMediaEditView(book,parent,ImagePath),isbn(new QLineEdit),
    bookGenreSelector(buildBookGenreSelector()){


    QGridLayout* layout(new QGridLayout());

    //creiamo la label e la spinBox per l'ISBN
    QLabel* newLabel=new QLabel();
    newLabel->setText("ISBN:");
    layout->addWidget(newLabel,0,1,1,1);
    
    isbn->setText(book.getIsbn());
    layout->addWidget(isbn,0,2,1,1); 

    //creiamo la label e posizionimo il selettore del genere
    newLabel=new QLabel();
    newLabel->setText("Genere:");
    layout->addWidget(newLabel,1,1,1,1);
    
    bookGenreSelector->setCurrentIndex(book.getGenre());
    layout->addWidget(bookGenreSelector,1,2,1,1); 
    addLayout(layout);
    }

    BookEditView::BookEditView(QWidget* parent,const QString& ImagePath )
    :PaperMediaEditView(parent,ImagePath),isbn(new QLineEdit),
    bookGenreSelector(buildBookGenreSelector()){


    QGridLayout* layout(new QGridLayout());

    //creiamo la label e la spinBox per l'ISBN
    QLabel* newLabel=new QLabel();
    newLabel->setText("ISBN:");
    layout->addWidget(newLabel,0,1,1,1);
    
    isbn->setText("");
    layout->addWidget(isbn,0,2,1,1); 

    //creiamo la label e posizionimo il selettore del genere
    newLabel=new QLabel();
    newLabel->setText("Genere:");
    layout->addWidget(newLabel,1,1,1,1);
    
    bookGenreSelector->setCurrentIndex(-1);
    layout->addWidget(bookGenreSelector,1,2,1,1); 
    addLayout(layout);
    }

    ListWidgetMediaItem* BookEditView::createNewMedia()const{
        return new ListWidgetMediaItem(Book(getTitle(),getAuthor(),getYear(),getGenre(),getDescription(),getPages(),getEditor(),getIsbn(),getTotal(),getCurrent()),getImagePath());
    }

    void BookEditView::applyMod(ListWidgetMediaItem* targetItem)const{
        if(targetItem ){//controllo nullptr
             if( Book* book=dynamic_cast<Book*>(targetItem->operator->())){//controllo che sia un libro
                book->setTitle(getTitle());
                book->setAuthor(getAuthor());
                book->setYear(getYear());
                book->setGenre(getGenre());
                book->setDescription(getDescription());
                book->setPages(getPages());
                book->setEditor(getEditor());
                book->setIsbn(getIsbn());
                book->setTotal(getTotal());
                book->setCurrentAvailability(getCurrent());
             }

        }
        
    }


    QComboBox* BookEditView::buildBookGenreSelector(){
        QComboBox* BookGenreSelector(new QComboBox());
        BookGenreSelector->insertItem(0,Book::intToBookGenre(0));
        BookGenreSelector->insertItem(1,Book::intToBookGenre(1));
        BookGenreSelector->insertItem(2,Book::intToBookGenre(2));
        BookGenreSelector->insertItem(3,Book::intToBookGenre(3));

        return BookGenreSelector;
    }

    ISBN BookEditView::getIsbn()const{
        return isbn->text();
    }
    int BookEditView::getGenre()const{
        return bookGenreSelector->currentIndex();
    }