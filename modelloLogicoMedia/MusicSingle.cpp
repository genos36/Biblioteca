#include "MusicSingle.h"
#include "../Visitors/AbstractMediaVisitor.h"

MusicSingle::MusicSingle():Audio(),recordLable("Default"){}

MusicSingle::MusicSingle(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability):
            Media(Title,Author,Year,Genre,Description,Total,CurrentAvailability),
            Audio(Title,Author,Year,Genre,Description,Lenght,Total,CurrentAvailability),
            recordLable(RecordLabel){}

MusicSingle::MusicSingle(const QString& Title,const QString& Author,int Year,
            const AudioGenre& Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability):
            MusicSingle(Title,Author,Year,AudioGenreToInt(Genre),Description,Lenght,RecordLabel,Total,CurrentAvailability){}



QString MusicSingle::getRecordLabel()const{
    return recordLable;
}

void MusicSingle::setRecordLabel(const QString& RecordLabel){
    recordLable=RecordLabel;
}

void MusicSingle::accept(AbstractMediaVisitor& visitor){
    visitor.visitMusicSingle(*this);
}

//others
bool MusicSingle::matchString(const QString& match)const{
    return Media::matchString(match)||recordLable.startsWith(match,Qt::CaseInsensitive);
}

MusicSingle* MusicSingle::clone()const{
    return new MusicSingle(*this);
}