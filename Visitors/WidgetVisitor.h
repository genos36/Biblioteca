#ifndef WIDGETVISITOR_H
#define WIDGETVISITOR_H
#include "AbstractMediaVisitor.h"
#include <QWidget>

/*
Widget visitor non si occupa direttamente di creare il visitor,
il widget viene creato solo e soltanto dopo che il visitor viene usato come parametro
di un accept 
*/

class WidgetVisitor:public AbstractMediaVisitor{
    private:
    QWidget* widget;
    protected:
    //WidgetVisitor(QWidget* =nullptr);

    WidgetVisitor();
    
    //~WidgetVisitor();
    WidgetVisitor(const WidgetVisitor&)=delete;
    WidgetVisitor& operator=(const WidgetVisitor&)=delete;
    
    void setWidget(QWidget*);
    public:
    
    QWidget* getWidget()const;

};


#endif