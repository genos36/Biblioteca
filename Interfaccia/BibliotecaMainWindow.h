#ifndef BIBLIOTECAMAINWINDOW_H
#define BIBLIOTECAMAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QScrollArea>
#include "MyToolBar.h"
#include "SearchInterface.h"
class SearchView;
class SearchInterface;

class BibliotecaMainWindow:public QMainWindow{
     Q_OBJECT
    private:
    MyToolBar* toolBar;
    QListWidget* mediaList;
    SearchView* searchList;
    QStackedWidget* views;
    QStackedWidget* lists;
    SearchInterface* searchInterface;
    QScrollArea* scrollArea;
    QPushButton* addMedia;

    public:
    BibliotecaMainWindow(QWidget *parent =nullptr);
    BibliotecaMainWindow(const BibliotecaMainWindow&)=delete;
    const BibliotecaMainWindow& operator=(const BibliotecaMainWindow&)=delete;
};

#endif