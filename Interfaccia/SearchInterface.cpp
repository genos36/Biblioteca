#include "SearchInterface.h"
#include <QGridLayout>
#include <QLabel>

QComboBox* SearchInterface::buildTypeSelector(){
    QComboBox* box( new QComboBox(this));
    box->addItem("All");
    box->addItem(QIcon(":/icons/book.png"),"Libri");
    box->addItem(QIcon(":/icons/magazine.png"),"Riviste");
    box->addItem(QIcon(":/icons/CD.png"),"CD");
    box->addItem(QIcon(":/icons/film.png"),"Film");


    return box;
}


SearchInterface::SearchInterface(QWidget *parent):
QWidget(parent),
text(new QLineEdit(this)),typeSelector(buildTypeSelector()),startSearch(new QPushButton("Cerca",this))
{
    QGridLayout* layout=new QGridLayout(this);
    layout->addWidget(new QLabel("Cerca: ",this),0,0,1,1);
    layout->addWidget(text,0,1,1,2);
    layout->addWidget(new QLabel("Filtra per tipo: ",this),1,0,1,1);
    layout->addWidget(typeSelector,1,1,1,2);
    layout->addWidget(startSearch,2,1,1,2);




}

