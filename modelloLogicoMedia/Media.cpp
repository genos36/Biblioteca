#include "Media.h"
#include "../Observers/AbstractMediaObserver.h"

Media::Media():title("Default title"),author("Default author"),
        year(2000),description("Default Description"),total(0),
        currentAvailability(0),genre(-1){}

Media::Media(const QString& Title,const QString& Author,int Year, 
        int Genre, const QString& Description, int Total,
        int CurrentAvailability):
    title(Title), author(Author),year(Year>0?Year:0),description(Description),
    total(Total>0?Total:0),
    currentAvailability((CurrentAvailability>0&&CurrentAvailability<=total)?CurrentAvailability:0),
    genre(Genre){
        
    }

QString Media::getTitle()const{
    return title;
}

QString Media::getAuthor()const{
    return author;
}

int Media::getYear()const{
    return year;
}

QString Media::getDescription()const{
    return description;
}

int Media::getTotal()const{
    return total;
}

int Media::getCurrentAvailability()const{
    return currentAvailability;
}

int Media::getGenre()const{
    return genre;
}

void Media::setTitle(const QString& Title){
    title=Title;
}

void Media::setAuthor(const QString& Author){
    author=Author;
}

void Media::setYear(int Year){
    year=Year;
}

void Media::setDescription(const QString& Description){
    description=Description;
}

void Media::setTotal(int Total){
    if(Total>0){
        total=Total;
        }
    if(currentAvailability>total){
        currentAvailability=total;
    }
}

void Media::setCurrentAvailability(int CurrentAvailability){
    if(CurrentAvailability>0 && CurrentAvailability<=total){
        currentAvailability=CurrentAvailability;
    }
}

void Media::setGenre(int Genre){
    genre=Genre;
}
//incrementi e decrementi di total e currentAvailability
void Media::addToTotal(int add){
    total+=add;
    currentAvailability+=add;
}

void Media::addToCurrentAvailability(int add){
    if((currentAvailability+add) <=total )currentAvailability+=add;
}

void Media::RemoveFromTotal(int rem){
    setTotal(total-rem);
    setCurrentAvailability(currentAvailability-rem);
}

void Media::RemoveFromCurrentAvailability(int rem){
    setCurrentAvailability(currentAvailability-rem);
}

//Desing pattern




void Media::addObserver(AbstractMediaObserver * obs){
    observers.push_back(obs);
}

void Media::notify(AbstractMediaObserver* obs){
    obs->update(*this);


}

void Media::notifyAll(){
    for(AbstractMediaObserver* obs :observers){
        notify(obs);
    }
}


