#ifndef PAPERMEDIAEDITVIEW_H
#define PAPERMEDIAEDITVIEW_H
#include "EditView.h"
class PaperMedia;
class PaperMediaEditView:public EditView{
    private:
    QLineEdit* editor;
    QSpinBox* pages;

    public:
    PaperMediaEditView(PaperMedia&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    PaperMediaEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    int getPages()const;
    QString getEditor()const;

};

#endif