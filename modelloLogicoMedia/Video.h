#ifndef VIDEO_H
#define VIDEO_H
#include "Multimedia.h"
#include "Genre/VideoGenre.h"


class Video:public Multimedia{
    private:

    public:
    Video();
    Video(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability);


    static QString intToVideoGenre(int);
    static int VideoGenreToInt(const VideoGenre&);
    QString getGenreName()const override;

};

#endif