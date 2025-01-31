#include "DurationSlider.h"
#include <QHBoxLayout>
#include <QLabel>

    DurationSlider::DurationSlider(const Duration& duration,QWidget* parent):
    QWidget(parent),hour(new QSpinBox()),minute(new QSpinBox()),second(new QSpinBox()){

        hour->setRange(0,std::numeric_limits<int>::max());
        hour->setValue(duration.ore());

        minute->setRange(0,59);
        minute->setValue(duration.minuti());
        
        second->setRange(0,59);
        second->setValue(duration.secondi());
        
        QHBoxLayout* layout=new QHBoxLayout(this);
        QLabel* tempLabel=new QLabel();        

        layout->addWidget(hour);

        tempLabel->setText(":");
        layout->addWidget(tempLabel);

        layout->addWidget(minute);

        tempLabel=new QLabel(); 
        tempLabel->setText(":");
        layout->addWidget(tempLabel);

        layout->addWidget(second);

    }

    Duration DurationSlider::getDuration()const{
        return Duration(hour->value(),minute->value(),second->value());
    }
    void DurationSlider::setDuration(const Duration& duration){
        hour->setValue(duration.ore());
        minute->setValue(duration.minuti());
        second->setValue(duration.secondi());
    }