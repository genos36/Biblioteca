#ifndef SEARCHINTERFACE_H
#define SEARCHINTERFACE_H

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>


class SearchInterface:public QWidget{
     Q_OBJECT
    private:
    QLineEdit* text;
    QComboBox* typeSelector;
    QPushButton* startSearch;

    QComboBox* buildTypeSelector();

    public:
    SearchInterface(QWidget *parent=nullptr);


    

};

//     /home/pao/Progetto/icon

#endif