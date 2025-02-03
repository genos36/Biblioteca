#include "MagazineEditView.h"

    MagazineEditView::MagazineEditView(Magazine& magazine,QWidget* parent,const QString& ImagePath )
    :PaperMediaEditView(magazine,parent,ImagePath),nEdition(new QSpinBox()),
    frequencySelector( buildFrequencySelector()),magazineGenreSelector(buildMagazineGenreSelector()){

        QGridLayout* layout=new QGridLayout();
        //inseriamo la label e la line edit  per il titolo
        QLabel* newLabel=new QLabel();
        newLabel->setText("Numero dell'edizione:");
        layout->addWidget(newLabel,0,1,1,1);
    
        nEdition->setValue(magazine.getNEdition());
        layout->addWidget(nEdition,0,2,1,1); 

        //Creaiamo la label e la line edit  per la frequenza di uscita
        newLabel=new QLabel();
        newLabel->setText("Periodicità:");
        layout->addWidget(newLabel,1,1,1,1);
    
        frequencySelector->setCurrentIndex(Magazine::FrequencyToInt(magazine.getFrequency()));
        layout->addWidget(frequencySelector,1,2,1,1); 

        //Creaiamo la label e la line edit per il genere
        newLabel=new QLabel();
        newLabel->setText("Genere:");
        layout->addWidget(newLabel,2,1,1,1);
    
        magazineGenreSelector->setCurrentIndex(magazine.getGenre());
        layout->addWidget(magazineGenreSelector,2,2,1,1); 


        addLayout(layout);

    }

    MagazineEditView::MagazineEditView(QWidget* parent,const QString& ImagePath )
    :PaperMediaEditView(parent,ImagePath),nEdition(new QSpinBox()),
    frequencySelector( buildFrequencySelector()),magazineGenreSelector(buildMagazineGenreSelector()){

        QGridLayout* layout=new QGridLayout();
        //inseriamo la label e la line edit  per il titolo
        QLabel* newLabel=new QLabel();
        newLabel->setText("Numero dell'edizione:");
        layout->addWidget(newLabel,0,1,1,1);
    
        nEdition->setValue(1);
        layout->addWidget(nEdition,0,2,1,1); 

        //Creaiamo la label e la line edit  per la frequenza di uscita
        newLabel=new QLabel();
        newLabel->setText("Periodicità:");
        layout->addWidget(newLabel,1,1,1,1);
    
        frequencySelector->setCurrentIndex(0);
        layout->addWidget(frequencySelector,1,2,1,1); 

        //Creaiamo la label e la line edit per il genere
        newLabel=new QLabel();
        newLabel->setText("Genere:");
        layout->addWidget(newLabel,2,1,1,1);
    
        magazineGenreSelector->setCurrentIndex(0);
        layout->addWidget(magazineGenreSelector,2,2,1,1); 


        addLayout(layout);

    }

    QComboBox* MagazineEditView::buildMagazineGenreSelector(){
        QComboBox* MagazineGenreSelector(new QComboBox());
        MagazineGenreSelector->insertItem(0,Magazine::intToMagazineGenre(0));
        MagazineGenreSelector->insertItem(1,Magazine::intToMagazineGenre(1));
        MagazineGenreSelector->insertItem(2,Magazine::intToMagazineGenre(2));
        return MagazineGenreSelector;
    }
    QComboBox* MagazineEditView::buildFrequencySelector(){
        QComboBox* FrequencySelector(new QComboBox());
        FrequencySelector->insertItem(0,Magazine::FrequencytoString(Frequency::no_data));
        FrequencySelector->insertItem(1, Magazine::FrequencytoString(Frequency::settimanale));
        FrequencySelector->insertItem(2, Magazine::FrequencytoString(Frequency::mensile));        
        
        return FrequencySelector;
    }

    ListWidgetMediaItem* MagazineEditView::createNewMedia()const{
        return new ListWidgetMediaItem(Magazine(getTitle(),getAuthor(),getYear(),getGenre(),getDescription(),getPages(),getEditor(),getFrequency(),getEdition(),getTotal(),getCurrent()),getImagePath());
    }

    void MagazineEditView::applyMod(ListWidgetMediaItem* targetItem)const{
                if(targetItem ){//controllo nullptr
             if( Magazine* magazine=dynamic_cast<Magazine*>(targetItem->operator->())){//controllo che sia un libro
                magazine->setTitle(getTitle());
                magazine->setAuthor(getAuthor());
                magazine->setYear(getYear());
                magazine->setGenre(getGenre());
                magazine->setDescription(getDescription());
                magazine->setPages(getPages());
                magazine->setEditor(getEditor());
                magazine->setFrequency(getFrequency());
                magazine->setNEdition(getEdition());
                magazine->setTotal(getTotal());
                magazine->setCurrentAvailability(getCurrent());

                targetItem->setImagePath(getImagePath());
             }

        }
    }

    int MagazineEditView::getEdition()const{
        return nEdition->value();
    }

    int MagazineEditView::getGenre()const{
        return magazineGenreSelector->currentIndex();
    }

    Frequency MagazineEditView::getFrequency()const{
        return static_cast<Frequency>(frequencySelector->currentIndex());
    }