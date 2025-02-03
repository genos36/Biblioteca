#ifndef SEARCHINTERFACE_H
#define SEARCHINTERFACE_H

#include <QLineEdit>
#include <QScrollArea>
#include <QComboBox>
#include <QStackedWidget>
#include <QPushButton>
#include "SearchListWidgetMedia.h"



class SearchInterface:public QWidget{
     Q_OBJECT
    private:
    QLineEdit* text;
    QComboBox* typeSelector;
    QPushButton* startSearchButton;
    QPushButton* cancelSearchButton;
    QScrollArea* scrollArea;
    QStackedWidget* viewSelector;
    ListWidgetMedia* genericList;
    SearchListWidgetMedia* searchList;  
    bool isSearchOn;

    public:

    static QComboBox* buildTypeSelector();

    SearchInterface(QWidget *parent=nullptr);

    public slots:
    void startSearch();
    void cancelSearch();
    void addItem(ListWidgetMediaItem*);
    void removeItem(ListWidgetMediaItem*);

    signals:

    void propagateModNotification();

    void itemPressed(ListWidgetMediaItem*);

    

};

#endif