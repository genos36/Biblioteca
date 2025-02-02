#ifndef MULTIMEDIAEDITVIEW_H
#define MULTIMEDIAEDITVIEW_H

#include "EditView.h"
#include "DurationSlider.h"

class Multimedia;

class MultimediaEditView:public EditView{
    Q_OBJECT
private:
    DurationSlider* duration;
public:

    MultimediaEditView(Multimedia&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    MultimediaEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    Duration getDuration()const;



};



#endif