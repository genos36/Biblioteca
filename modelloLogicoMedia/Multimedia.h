#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include "Media.h"
#include "Duration.h"
class Multimedia: virtual public Media{
private:
Duration lenght;

public:
Multimedia();
Multimedia(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,const Duration& Lenght, int Total,
            int CurrentAvailability);



virtual Duration getLenght()const;
virtual void setLenght(const Duration&);

};


#endif