#ifndef MAINVIEW_H
#define MAINVIEW_H

#include<QWidget>
#include<QPushButton>
#include<QStackedWidget>
#include<QGridLayout>

class DetailView;
class EditView;
class ListWidgetMediaItem;

class MainView:public QWidget{
    Q_OBJECT
    private:
        QGridLayout* layout;
        QStackedWidget* viewSelector;
        DetailView* detailView;     //detailView è un visitor, bisogna eliminare, sia il detail view, sia detail view.getWidget() 
        EditView* editView;         //editView è un widget, è sufficiente eliminare editView
        ListWidgetMediaItem* currentMedia;

        QPushButton* editButton;
        QPushButton* cancelButton;
        QPushButton* saveModButton;
        QPushButton* createButton;
        QPushButton* deleteButton;
        QStackedWidget* buttonWrapper;

    public:
    
    MainView( QWidget* parent=nullptr);
    
    void setViews(ListWidgetMediaItem*);

    public slots:

    void switchToModView();
    void switchToCreateView(int );
    void saveAndSwitchToDetailview();

    ListWidgetMediaItem* createAndSwitchToDetailview();
    void cancelAndSwitchToDetailview();

    void ChangeDetailview(ListWidgetMediaItem*);

    signals:

    void propagateModNotification();
    void deleteItem(ListWidgetMediaItem* );





};

#endif