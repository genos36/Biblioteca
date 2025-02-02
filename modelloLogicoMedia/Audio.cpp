#include "Audio.h"


Audio::Audio():Multimedia(){}

Audio::Audio(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability):
            Multimedia(Title,Author,Year,Genre,Description,Lenght,Total,CurrentAvailability){}

Audio::Audio(const QString& Title,const QString& Author,int Year,
            const AudioGenre& Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability):
            Multimedia(Title,Author,Year,AudioGenreToInt(Genre),Description,Lenght,Total,CurrentAvailability){}

 QString Audio::intToAudioGenre(int g){
    switch(static_cast<AudioGenre>(g)){
        case AudioGenre::Rock :return "Rock";        
        case AudioGenre::Pop :return "Pop";        
        case AudioGenre::Punk :return "Punk";        
        case AudioGenre::Metal :return "Metal";
        default: return "Altro";     
    }
}
 int  Audio::AudioGenreToInt(const AudioGenre& g){
    return static_cast< int>(g);
}  

QString Audio::getGenreName()const{
    return intToAudioGenre(getGenre());
}