#include "WidgetVisitor.h"

QWidget* WidgetVisitor::getWidget()const{
    return widget;
}

void WidgetVisitor::setWidget(QWidget* newWidget){
    widget=newWidget;
}
    WidgetVisitor::WidgetVisitor():widget(nullptr){}


//WidgetVisitor::WidgetVisitor(QWidget* parent):widget(new QWidget(parent)){}
/*
    WidgetVisitor::~WidgetVisitor(){
        delete widget;
    }


    WidgetVisitor::WidgetVisitor(const WidgetVisitor& other):widget(other.widget){}

    WidgetVisitor& WidgetVisitor::operator=(const WidgetVisitor& other){
        if(this!=&other){
            widget=other.widget;
        }
        return *this;
    }
    
*/


