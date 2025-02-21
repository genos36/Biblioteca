#include "WidgetVisitor.h"

QWidget* WidgetVisitor::getWidget()const{
    return widget;
}

void WidgetVisitor::setWidget(QWidget* newWidget){
    widget=newWidget;
}
    WidgetVisitor::WidgetVisitor():widget(nullptr){}


