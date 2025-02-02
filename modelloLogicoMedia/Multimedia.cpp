#include "Multimedia.h"

Multimedia::Multimedia():Media(),lenght(){}

Multimedia::Multimedia(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description, const Duration& Lenght,int Total,
            int CurrentAvailability):
            Media(Title,Author,Year,Genre,Description,Total,CurrentAvailability),
            lenght(Lenght){}

Duration Multimedia::getLenght()const{
    return lenght;
}

void Multimedia::setLenght(const Duration& Lenght){
    lenght=Lenght;
}
