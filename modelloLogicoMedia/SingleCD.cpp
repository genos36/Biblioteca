#include "SingleCD.h"
#include "../Visitors/AbstractMediaVisitor.h"

SingleCD::SingleCD():Audio(),recordLable("Default"){}

SingleCD::SingleCD(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability):Audio(Title,Author,Year,Genre,Description,Lenght,Total,CurrentAvailability),
            recordLable(RecordLabel){}

SingleCD::SingleCD(const QString& Title,const QString& Author,int Year,
            const AudioGenre& Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability):Audio(Title,Author,Year,AudioGenreToInt(Genre),Description,Lenght,Total,CurrentAvailability),
            recordLable(RecordLabel){}



QString SingleCD::getRecordLabel()const{
    return recordLable;
}

void SingleCD::setRecordLabel(const QString& RecordLabel){
    recordLable=RecordLabel;
}

void SingleCD::accept(AbstractMediaVisitor& visitor){
    visitor.visitSingleCD(*this);
}