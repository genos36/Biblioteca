#include "Film.h"
#include "../Visitors/AbstractMediaVisitor.h"

Film::Film():Video(),mainActor("Default main actor"){}

Film::Film(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,
            const Duration& Lenght,const QString& MainActor ,int Total,
            int CurrentAvailability):
            Media(Title,Author,Year,Genre,Description,Total,CurrentAvailability),
            Video(Title,Author,Year,Genre,Description,Lenght,Total,CurrentAvailability),
            mainActor(MainActor){}

Film::Film(const QString& Title,const QString& Author,int Year,
            const VideoGenre& Genre, const QString& Description,
            const Duration& Lenght,const QString& MainActor ,int Total,
            int CurrentAvailability):
            Film(Title,Author,Year,VideoGenreToInt(Genre),Description,Lenght,MainActor,Total,CurrentAvailability){}

QString Film::getMainActor()const{
    return mainActor;
}

void Film::setMainActor(const QString& MainActor){
    mainActor=MainActor;
}

void Film::accept(AbstractMediaVisitor& visitor){
    visitor.visitFilm(*this);
}

bool Film::matchString(const QString& match)const{
    return Media::matchString(match)||mainActor.startsWith(match,Qt::CaseInsensitive)||mainActor.endsWith(match,Qt::CaseInsensitive)||mainActor.contains(" "+match+" ",Qt::CaseInsensitive);
}

Film* Film::clone()const{
    return new Film(*this);
}

