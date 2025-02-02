#ifndef MAGAZINEEDITVIEW_H
#define MAGAZINEEDITVIEW_H

#include "PaperMediaEditView.h"
#include <QComboBox>
#include "../modelloLogicoMedia/Magazine.h"

class MagazineEditView:public PaperMediaEditView{
    Q_OBJECT
private:
    QSpinBox* nEdition;
    QComboBox* frequencySelector;
    QComboBox* magazineGenreSelector;

public:
    static QComboBox* buildFrequencySelector();
    static QComboBox* buildMagazineGenreSelector();

    MagazineEditView(Magazine&,QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");
    MagazineEditView(QWidget* parent=nullptr,const QString& ImagePath =":/icons/defaultImage");

    int getEdition()const;
    int getGenre()const;
    Frequency getFrequency()const;

    public slots:
    virtual ListWidgetMediaItem* createNewMedia()const override;
    virtual void applyMod(ListWidgetMediaItem*)const override;

};



#endif