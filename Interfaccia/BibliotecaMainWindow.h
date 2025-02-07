#ifndef BIBLIOTECAMAINWINDOW_H
#define BIBLIOTECAMAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QScrollArea>
#include "MyToolBar.h"
#include "SearchInterface.h"
#include "MainView.h"
class SearchView;
class SearchInterface;

class BibliotecaMainWindow:public QMainWindow{
     Q_OBJECT
    private:
    MyToolBar* toolBar;
    SearchInterface* searchInterface;
    MainView* mainView;
    QHBoxLayout* mainLayout;
    QPushButton* addMedia;
    QComboBox* strictTypeSelector;

    static QComboBox* buildStrictTypeSelector();

    void setUpShortcuts();

    public:
    BibliotecaMainWindow(QWidget *parent =nullptr);

    
    
    protected:
    
    void closeEvent(QCloseEvent *event) override;
    
    public slots:
    void handleNewItemAdded(ListWidgetMediaItem*);
    void handleItemModified(ListWidgetMediaItem*);
    void handleItemDeleted(ListWidgetMediaItem*);
    void HandleItemSeleced(ListWidgetMediaItem*);

    void saveToJson();
    void openFromJson();

    signals:
    void propagateModNotification();
};

#endif