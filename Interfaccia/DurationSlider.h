#ifndef DURATIONSLIDER_H
#define DURATIONSLIDER_H
#include <QWidget>
#include <QSpinBox>
#include "../modelloLogicoMedia/Duration.h"

class DurationSlider:public QWidget{
    Q_OBJECT
    private:
    QSpinBox* hour;
    QSpinBox* minute;
    QSpinBox* second;

    public:
    DurationSlider(const Duration& =0,QWidget* parent=nullptr);
    Duration getDuration()const;
    void setDuration(const Duration&);

};

#endif