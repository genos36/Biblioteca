#ifndef FILM_H
#define FILM_H
#include "Video.h"

class Film:public virtual Video{
    private:
    QString mainActor;

    public:
    Film();
    Film(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,
            const Duration& Lenght,const QString& MainActor ,int Total,
            int CurrentAvailability);

        Film(const QString& Title,const QString& Author,int Year,
            const VideoGenre& Genre, const QString& Description,
            const Duration& Lenght,const QString& MainActor ,int Total,
            int CurrentAvailability);

    QString getMainActor()const;
    void setMainActor(const QString&);
    void accept(AbstractMediaVisitor&)override;
    //others
    bool matchString(const QString& )const override;
    Film* clone()const override;
};

#endif