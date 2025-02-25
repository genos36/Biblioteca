

#include <QScrollArea>
#include <QTextEdit>
#include "DetailView.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"

    void DetailView::BuildView(Media& media, const QString& ImagePath){
    layout=new QGridLayout(this);
    image=new QLabel();
    availability=new QLabel();
    incrementAvailability=new QPushButton();
    decrementAvailability=new QPushButton();

    QPixmap pixmap(ImagePath);
    if (!pixmap.isNull()) {
    image->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else{
    image->setPixmap(QPixmap(":/icons/defaultImage").scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));  
    }
    layout->addWidget(image,0,0,1,3);

    //crea e inserisce la label del titolo
    QLabel* newLabel=new QLabel();
    newLabel->setText("Titolo:");
    layout->addWidget(newLabel,0,1,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(media.getTitle());
    layout->addWidget(newLabel,0,2,1,1);

    //crea e inserisce la label dell'autore
    newLabel=new QLabel();
    newLabel->setText("Autore:");
    layout->addWidget(newLabel,1,1,1,1);

    newLabel=new QLabel();
    newLabel->setText(media.getAuthor());
    layout->addWidget(newLabel,1,2,1,1);

    //crea e inserisce la label dell'anno
    newLabel=new QLabel();
    newLabel->setText("Anno:");
    layout->addWidget(newLabel,2,1,1,1);

    newLabel=new QLabel();
    newLabel->setNum(media.getYear());
    layout->addWidget(newLabel,2,2,1,1);

    //crea e inserisce la label del genere
    newLabel=new QLabel();
    newLabel->setText("Genere:");
    layout->addWidget(newLabel,3,0,1,1);

    newLabel=new QLabel();
    newLabel->setText(media.getGenreName());
    layout->addWidget(newLabel,3,1,1,2);
    

    //crea e inserisce la label della descrizione
    newLabel=new QLabel();
    newLabel->setText("Descrizione:");
    layout->addWidget(newLabel,4,0,1,1);
    newLabel->setAlignment(Qt::AlignTop);

    newLabel=new QLabel();
    newLabel->setText(media.getDescription());
    newLabel->setWordWrap(true);
    newLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);


    QTextEdit* descriptionLabel=new QTextEdit();
    descriptionLabel->setText(media.getDescription());
    descriptionLabel->setReadOnly(true);  // Disabilita la modifica del testo
    descriptionLabel->setWordWrapMode(QTextOption::WordWrap);  // Abilita il ritorno a capo del testo
    descriptionLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    layout->addWidget(descriptionLabel,4,1,1,2);

    //crea e inserisce la label della disponibilità
    newLabel=new QLabel();
    newLabel->setText("Disponibilità:");
    layout->addWidget(newLabel,5,0,1,1);

    availability=new QLabel();
    availability->setNum(media.getCurrentAvailability());
    layout->addWidget(availability,5,1,1,1);

    newLabel=new QLabel();
    newLabel->setText("su "+QString::number(media.getTotal()));
    layout->addWidget(newLabel,5,2,1,1);

    //inserisce i pulsanti

    decrementAvailability->setText("-");
    incrementAvailability->setText("+");

    layout->addWidget(decrementAvailability,6,1,1,1);
    layout->addWidget(incrementAvailability,6,2,1,1);


    connect(incrementAvailability, &QPushButton::pressed, this, [this, &media]() {
    availability->setNum(media.addToCurrentAvailability(1)); // addToCurrentAvailability incrementa la disponibilità totale(facendo i controlli) e ritorna il nuovo valore
});

    connect(decrementAvailability, &QPushButton::pressed, this, [this, &media]() {
    availability->setNum(media.RemoveFromCurrentAvailability(1)); 
});

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(incrementAvailability,&QPushButton::pressed,this,&DetailView::propagateModNotification);
    connect(decrementAvailability,&QPushButton::pressed,this,&DetailView::propagateModNotification);

}


DetailView::DetailView(Book & book,QWidget* parent,const QString& ImagePath ):
QWidget(parent),layout(new QGridLayout()),image(new QLabel()),
availability(new QLabel()),incrementAvailability(new QPushButton()),
decrementAvailability(new QPushButton()){
    BuildView(book,ImagePath);

        //crea e inserisce la label dell'editore
    QLabel* newLabel=new QLabel();
    int rows=layout->rowCount()+1;

    newLabel->setText("Editore:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(book.getEditor());
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;
    //crea e inserisce la label del numero di pagine
    newLabel=new QLabel();
    newLabel->setText("Pagine:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(QString::number(book.getPages()));
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;
    //crea e inserisce la label dell'isbn
    newLabel=new QLabel();
    newLabel->setText("ISBN:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(book.getIsbn());
    layout->addWidget(newLabel,rows,1,1,2);


}



DetailView::DetailView(Magazine& magazine,QWidget* parent,const QString& ImagePath ):
QWidget(parent),layout(new QGridLayout()),image(new QLabel()),
availability(new QLabel()),incrementAvailability(new QPushButton()),
decrementAvailability(new QPushButton()){
    BuildView(magazine,ImagePath);
//crea e inserisce la label dell'editore
    QLabel* newLabel=new QLabel();
    int rows=layout->rowCount()+1;

    newLabel->setText("Editore:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(magazine.getEditor());
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;

    //crea e inserisce la label del numero di pagine
    newLabel=new QLabel();
    newLabel->setText("Pagine:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(QString::number(magazine.getPages()));
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;

    //crea e inserisce la label della frequenza di pubblicazione
    newLabel=new QLabel();
    newLabel->setText("Frequenza:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(magazine.getFrequencyString());
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;

    //crea e inserisce la label dell'edizione
    newLabel=new QLabel();
    newLabel->setText("Edizione numero:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(QString::number(magazine.getNEdition()));
    layout->addWidget(newLabel,rows,1,1,2);

}


DetailView::DetailView(MusicSingle& musicSingle,QWidget* parent,const QString& ImagePath ):
QWidget(parent),layout(new QGridLayout()),image(new QLabel()),
availability(new QLabel()),incrementAvailability(new QPushButton()),
decrementAvailability(new QPushButton()){

    BuildView(musicSingle,ImagePath);

    //crea e inserisce la label della durata
    QLabel* newLabel=new QLabel();
    int rows=layout->rowCount()+1;
    newLabel->setText("Durata:");
    layout->addWidget(newLabel,rows,0,1,1);
    newLabel=new QLabel();
    newLabel->setText(musicSingle.getLenght());
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;

    //crea e inserisce la label della etichetta discografica
    newLabel=new QLabel();
    newLabel->setText("Etichetta discografica:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(musicSingle.getRecordLabel());
    layout->addWidget(newLabel,rows,1,1,2);

}




DetailView::DetailView(Film& film,QWidget* parent,const QString& ImagePath ):
QWidget(parent),layout(new QGridLayout()),image(new QLabel()),
availability(new QLabel()),incrementAvailability(new QPushButton()),
decrementAvailability(new QPushButton()){
    
    BuildView(film,ImagePath);

    //crea e inserisce la label della durata
    QLabel* newLabel=new QLabel();
    int rows=layout->rowCount()+1;
    newLabel->setText("Durata:");
    layout->addWidget(newLabel,rows,0,1,1);
    newLabel=new QLabel();
    newLabel->setText(film.getLenght());
    layout->addWidget(newLabel,rows,1,1,2);
    ++rows;

    //crea e inserisce la label dell'attore protagonista
    newLabel=new QLabel();
    newLabel->setText("Etichetta discografica:");
    layout->addWidget(newLabel,rows,0,1,1);
    
    newLabel=new QLabel();
    newLabel->setText(film.getMainActor());
    layout->addWidget(newLabel,rows,1,1,2);

}

void DetailView::setImage(const QString& ImagePath){
    QPixmap pixmap(ImagePath);
    if (!pixmap.isNull()) {
    image->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else{
    image->setPixmap(QPixmap(":/icons/defaultImage").scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));  
    }
    //layout->addWidget(image,0,0,1,3);

}