#ifndef MYTOOLBAR_H
#define MYTOOLBAR_H

#include <QToolBar>
#include <QPushButton>
#include "../Observers/AbstractMediaObserver.h"

class MyToolBar:public QToolBar{
    Q_OBJECT

private:
    QPushButton* open;
    QPushButton* save;
    QPushButton* saveAs;
    QString filePath;
    bool isSaved;

public:
    MyToolBar(QWidget *parent = nullptr);
    
    QString getFilePath();
    bool isFileSaved();

    static int displayMessageBox();
    
    void useMessageBox();

public slots:
    void onOpen(); 
    void onSave();
    void onSaveAs();
    
    void onModDetected();

signals:
    void onOpenPressed();
    void onSavePressed();
    //void onSaveAsPressed();
};

#endif