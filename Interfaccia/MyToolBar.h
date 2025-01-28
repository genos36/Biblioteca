#ifndef MYTOOLBAR_H
#define MYTOOLBAR_H

#include <QToolBar>
#include <QPushButton>
#include "../Observers/AbstractMediaObserver.h"

class MyToolBar:public QToolBar,public AbstractMediaObserver{
    Q_OBJECT

private:
    QPushButton* open;
    QPushButton* save;
    QPushButton* saveAs;
public:
    MyToolBar(QWidget *parent = nullptr);
    
    void update(Media&)override;
    ~MyToolBar();

public slots:
    void onSave();
    void onSaveAs();
};

#endif