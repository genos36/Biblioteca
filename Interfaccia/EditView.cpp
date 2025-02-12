#include "EditView.h"
#include "../modelloLogicoMedia/Media.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QCoreApplication>
#include <QMessageBox>
#include <limits>


EditView::EditView(Media& media,QWidget* parent,const QString& ImagePath):
    QWidget(parent),mainLayout(new QVBoxLayout(this)),
    image(new QLabel()),changeImage(new QPushButton()),
    title(new QLineEdit()),author(new QLineEdit()),
    year(new QSpinBox()),description(new QTextEdit()),total(new QSpinBox()),
    current(new QSpinBox()),cancel(new QPushButton()),confirm(new QPushButton()),
    imagePath(ImagePath){

    QGridLayout* secondLayout=new QGridLayout();


    //Creiamo la label dell'immagine
    setImagePath(ImagePath);
    secondLayout->addWidget(image,0,0,1,3);
    //creiamo il pulsante per la modifica
    changeImage->setText("Cambia Immagine");
    secondLayout->addWidget(changeImage,2,0,1,1);

    //Creaiamo la label e la line edit  per il titolo
    QLabel* newLabel=new QLabel();
    newLabel->setText("Titolo:");
    secondLayout->addWidget(newLabel,0,1,1,1);
    
    title->setText(media.getTitle());
    secondLayout->addWidget(title,0,2,1,1); 

    //creiamo la label e la line edit per l'autore
    newLabel=new QLabel();
    newLabel->setText("Autore:");
    secondLayout->addWidget(newLabel,1,1,1,1);
    
    author->setText(media.getAuthor());
    secondLayout->addWidget(author,1,2,1,1); 

    //creiamo la label e la spinBox per l'anno
    newLabel=new QLabel();
    newLabel->setText("Anno:");
    secondLayout->addWidget(newLabel,2,1,1,1);
    
    year->setRange(0,3000);
    year->setValue(media.getYear());
    secondLayout->addWidget(year,2,2,1,1); 

    //creiamo la label e la line edit per la descrizione
    newLabel=new QLabel();
    newLabel->setText("Descrizione:");
    secondLayout->addWidget(newLabel,3,0,1,1);
    
    description->setText(media.getDescription());
    secondLayout->addWidget(description,3,1,1,2); 


    //creiamo la label e la spinBox per la disponibilità totale
    newLabel=new QLabel();
    newLabel->setText("Totale:");
    secondLayout->addWidget(newLabel,4,1,1,1);
    
    total->setRange(0,std::numeric_limits<int>::max());
    total->setValue(media.getTotal());
    secondLayout->addWidget(total,4,2,1,1); 

    //creiamo la label e la spinBox per la disponibilità attuale
    newLabel=new QLabel();
    newLabel->setText("Disponibili:");
    secondLayout->addWidget(newLabel,5,1,1,1);
    
    current->setRange(0,std::numeric_limits<int>::max());
    current->setValue(media.getCurrentAvailability());
    secondLayout->addWidget(current,5,2,1,1); 

    mainLayout->addLayout(secondLayout);


    connect(changeImage,&QPushButton::pressed,this,&EditView::changeImageSlot);

}


EditView::EditView(QWidget* parent,const QString& ImagePath):
    QWidget(parent),mainLayout(new QVBoxLayout(this)),
    image(new QLabel()),changeImage(new QPushButton()),
    title(new QLineEdit()),author(new QLineEdit()),
    year(new QSpinBox()),description(new QTextEdit()),total(new QSpinBox()),
    current(new QSpinBox()),cancel(new QPushButton()),confirm(new QPushButton()),
    imagePath(ImagePath){

    QGridLayout* secondLayout=new QGridLayout();


    //Creiamo la label dell'immagine
    setImagePath(ImagePath);
    secondLayout->addWidget(image,0,0,1,3);

    //creiamo il pulsante per la modifica
    changeImage->setText("Cambia Immagine");
    secondLayout->addWidget(changeImage,2,0,1,1);

    //Creaiamo la label e la line edit  per il titolo
    QLabel* newLabel=new QLabel();
    newLabel->setText("Titolo:");
    secondLayout->addWidget(newLabel,0,1,1,1);
    
    title->setText("");
    secondLayout->addWidget(title,0,2,1,1); 

    //creiamo la label e la line edit per l'autore
    newLabel=new QLabel();
    newLabel->setText("Autore:");
    secondLayout->addWidget(newLabel,1,1,1,1);
    
    author->setText("");
    secondLayout->addWidget(author,1,2,1,1); 

    //creiamo la label e la spinBox per l'anno
    newLabel=new QLabel();
    newLabel->setText("Anno:");
    secondLayout->addWidget(newLabel,2,1,1,1);
    
    year->setRange(0,3000);
    year->setValue(0);
    secondLayout->addWidget(year,2,2,1,1); 

    //creiamo la label e la line edit per la descrizione
    newLabel=new QLabel();
    newLabel->setText("Descrizione:");
    secondLayout->addWidget(newLabel,3,0,1,1);
    
    description->setText("");
    secondLayout->addWidget(description,3,1,1,2); 


    //creiamo la label e la spinBox per la disponibilità totale
    newLabel=new QLabel();
    newLabel->setText("Totale:");
    secondLayout->addWidget(newLabel,4,1,1,1);
    
    total->setRange(0,std::numeric_limits<int>::max());
    total->setValue(0);
    secondLayout->addWidget(total,4,2,1,1); 

    //creiamo la label e la spinBox per la disponibilità attuale
    newLabel=new QLabel();
    newLabel->setText("Disponibili:");
    secondLayout->addWidget(newLabel,5,1,1,1);
    
    current->setRange(0,std::numeric_limits<int>::max());
    current->setValue(0);
    secondLayout->addWidget(current,5,2,1,1); 

    mainLayout->addLayout(secondLayout);


    connect(changeImage,&QPushButton::pressed,this,&EditView::changeImageSlot);

}









    QString EditView::getTitle()const{
        return title->text();
    }

    QString EditView::getAuthor()const{
        return author->text();
    }
    int EditView::getYear()const{
        return year->value();
    }
    QString EditView::getDescription()const{
        return description->toPlainText();
    }
    int EditView::getTotal()const{
        return total->value();
    }
    int EditView::getCurrent()const{
        return total->value()>=current->value()?current->value():total->value();
    }

    QString EditView::getImagePath()const{
        return imagePath;
    }

    void EditView::setImagePath(const QString& newImagePath){
        imagePath=newImagePath;
        QPixmap pixmap(imagePath);
        if(!pixmap.isNull()){
            image->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else{
            image->setPixmap(QPixmap(":/icons/defaultImage").scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

    void EditView::addWidget(QWidget* newWidget){
        mainLayout->addWidget(newWidget);
    }

    void EditView::addLayout(QLayout* newLayout){
        mainLayout->addLayout(newLayout);
    }

    void EditView::changeImageSlot(){
        QString filePath=QFileDialog::getOpenFileName(this, "Seleziona Immagine", "", "Images (*.png *.jpg *.jpeg )");
    
        if(!filePath.isEmpty()){
            //selezione del file
            QString fileName = QFileInfo(filePath).fileName();
            //attuale directory di lavoro
            QString destinationPath = QCoreApplication::applicationDirPath() + "/images/" + fileName;
            //copio l'immagine per potermi riferire ad essa usando dei path relativi
            
            if(filePath!=destinationPath){
                //si assicura che il percorso delfile che stiamo caricando e quello che vogliamo caricare siano distinti 
                if(QFile::exists(destinationPath)){
                    //se esiste già un file con lo stesso nome lo rimuove così da poterlo sostituire<
                    QFile::remove(destinationPath);
                }

                if(QFile::copy(filePath, destinationPath)){
                    //imposta la nuova immagine
                    setImagePath("./images/" + fileName);
                }
                else{
                QMessageBox::warning(this,"Errore","qualcosa è andato storto ne l caricamento dell'immagine");
                }

            }
            else{
                //se l'immagine è già presente in images si limita a impostarla
                setImagePath("./images/" + fileName);
            }


        }
    
    }