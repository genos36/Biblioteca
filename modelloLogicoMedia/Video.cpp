#include "Video.h"

Video::Video():Multimedia(){}

Video::Video(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability):
            Multimedia(Title,Author,Year,Genre,Description,Lenght,Total,CurrentAvailability){}

Video::Video(const QString& Title,const QString& Author,int Year,
            const VideoGenre& Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability):
            Multimedia(Title,Author,Year,VideoGenreToInt(Genre),Description,Lenght,Total,CurrentAvailability){}

QString Video::intToVideoGenre(int g){
    switch(static_cast<VideoGenre>(g)){
        case VideoGenre::Action :return "Action";
        case VideoGenre::Sci_fy :return "Fantascienza";
        case VideoGenre::Horror :return "Horror";
        default: return "Altro";

    }
}

int Video::VideoGenreToInt(const VideoGenre& g){
    return static_cast<int>(g);
}

QString Video::getGenreName()const{
    return intToVideoGenre(getGenre());
}