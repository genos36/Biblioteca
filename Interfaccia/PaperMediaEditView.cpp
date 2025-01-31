#include "PaperMediaEditView.h"
#include "../modelloLogicoMedia/PaperMedia.h"

PaperMediaEditView::PaperMediaEditView(PaperMedia& media,QWidget* parent,const QString& ImagePath):
EditView(media,parent,ImagePath),editor(new QLineEdit()),pages(new QSpinBox()){
    QGridLayout* layout=new QGridLayout();

    //creiamo la label e la spinBox per la disponibilità attuale
    QLabel* newLabel=new QLabel();
    newLabel->setText("Pagine:");
    layout->addWidget(newLabel,0,1,1,1);
    
    pages->setRange(0,std::numeric_limits<int>::max());
    pages->setValue(media.getPages());
    layout->addWidget(pages,0,2,1,1); 

    //creiamo la label e la spinBox per la disponibilità attuale
    newLabel=new QLabel();
    newLabel->setText("Editore:");
    layout->addWidget(newLabel,1,1,1,1);
    
    editor->setText(media.getEditor());
    layout->addWidget(editor,1,2,1,1); 

    addLayout(layout);

}

PaperMediaEditView::PaperMediaEditView(QWidget* parent,const QString& ImagePath):
EditView(parent,ImagePath),editor(new QLineEdit()),pages(new QSpinBox()){
    QGridLayout* layout=new QGridLayout();

    //creiamo la label e la spinBox per le pagine
    QLabel* newLabel=new QLabel();
    newLabel->setText("Pagine:");
    layout->addWidget(newLabel,0,1,1,1);
    
    pages->setRange(0,std::numeric_limits<int>::max());
    pages->setValue(0);
    layout->addWidget(pages,0,2,1,1); 

    //creiamo la label e la spinBox per l'editore
    newLabel=new QLabel();
    newLabel->setText("Editore:");
    layout->addWidget(newLabel,1,1,1,1);
    
    editor->setText("");
    layout->addWidget(editor,1,2,1,1); 

    addLayout(layout);

}

    int PaperMediaEditView::getPages()const{
        return pages->value();
    }
    QString PaperMediaEditView::getEditor()const{
        return editor->text();
    }
