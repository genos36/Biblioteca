#ifndef AUDIO_H
#define AUDIO_H
#include "Multimedia.h"
#include "Genre/AudioGenre.h"
class Audio:public Multimedia{
private:

public:
Audio();
Audio(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability);

Audio(const QString& Title,const QString& Author,int Year,
            const AudioGenre& Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability);

static QString intToAudioGenre(int); 
static  int AudioGenreToInt(const AudioGenre&); 
QString getGenreName()const override;

};

#endif