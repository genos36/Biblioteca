#include "Magazine.h"
#include "../Visitors/AbstractMediaVisitor.h"

Magazine::Magazine():PaperMedia(),frequency(Frequency::no_data),nEdition(1){}

Magazine::Magazine(const QString& Title,const QString& Author,
            int Year,int Genre, const QString& Description, 
            int Pages, QString Editor,const Frequency& freq,
            int NEdition, 
            int Total, int CurrentAvailability):
            PaperMedia(Title,Author,Year,Genre,Description,Pages,Editor,Total,CurrentAvailability),
            frequency(freq),nEdition(NEdition>0?NEdition:0){}

Magazine::Magazine(const QString& Title,const QString& Author,
            int Year,const MagazineGenre& Genre, const QString& Description, 
            int Pages, QString Editor,const Frequency& freq,
            int NEdition, 
            int Total, int CurrentAvailability):
            PaperMedia(Title,Author,Year,MagazineGenreToInt(Genre),Description,Pages,Editor,Total,CurrentAvailability),
            frequency(freq),nEdition(NEdition>0?NEdition:0){}


QString Magazine::intToMagazineGenre(int g){
    switch(static_cast<MagazineGenre>(g)){
        case MagazineGenre::currentAffairs : return "Attualità";
        case MagazineGenre::scientific : return "Scientifica";
        default :return "Altri";
    }
}

int Magazine::MagazineGenreToInt(const MagazineGenre& g){
    return static_cast<int>(g);
}

QString Magazine::FrequencytoString(const Frequency& f){
        switch(f){
        case Frequency::settimanale : return "Settimanale";
        case Frequency::mensile : return "Mensile";
        default :return "Altro";
    }
}

int Magazine::FrequencyToInt(const Frequency& f){
    return static_cast<int>(f);
}

int Magazine::getNEdition()const{
    return nEdition;
}

void Magazine::setNEdition(int NEdition){
    nEdition=NEdition;
}

Frequency Magazine::getFrequency()const{
    return frequency;
}

QString Magazine::getFrequencyString()const{
    return FrequencytoString(getFrequency());
}

void Magazine::setFrequency(const Frequency& freq){
    frequency=freq;
}

QString Magazine::getGenreName()const{
    return intToMagazineGenre(getGenre());
}

void Magazine::accept(AbstractMediaVisitor& visitor){
    visitor.visitMagazine(*this);
}