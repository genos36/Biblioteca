#ifndef MULTIMEDIAEDITVIEW_H
#define MULTIMEDIAEDITVIEW_H

#include "EditView.h"
#include "DurationSlider.h"

class MultimediaEditView:public {
private:
    DurationSlider* duration;
public:
    MultimediaEditView();
};

MultimediaEditView::MultimediaEditView(/* args */)
{
}

MultimediaEditView::~MultimediaEditView()
{
}



#endif