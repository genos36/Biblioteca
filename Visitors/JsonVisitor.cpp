#include "JsonVisitor.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"

QJsonObject JsonVisitor::getJsonObject(){
    return jsonObject;
}


void JsonVisitor::clearJsonObject(){
    jsonObject=QJsonObject();
}


void JsonVisitor::saveGenericPart(Media& media){
    jsonObject["title"]=media.getTitle();
    jsonObject["author"]=media.getAuthor();
    jsonObject["year"]=media.getYear();
    jsonObject["description"]=media.getDescription();
    jsonObject["genre"]=media.getGenre();
    jsonObject["totalAv"]=media.getTotal();//av sta per Availability
    jsonObject["currentAv"]=media.getCurrentAvailability();
}


void JsonVisitor::visitBook(Book& book){
    clearJsonObject();

    saveGenericPart(book);
    
    jsonObject["type"]="book";
    jsonObject["pages"]=book.getPages();
    jsonObject["editor"]=book.getEditor();

    jsonObject["isbn"]=book.getIsbn();


}



void JsonVisitor::visitMagazine(Magazine& magazine){
    clearJsonObject();

    saveGenericPart(magazine);
    
    jsonObject["type"]="magazine";
    jsonObject["pages"]=magazine.getPages();
    jsonObject["editor"]=magazine.getEditor();

    jsonObject["frequency"]=Magazine::FrequencyToInt(magazine.getFrequency());
    jsonObject["nEdition"]=magazine.getNEdition();

    }

void JsonVisitor::visitMusicSingle(MusicSingle& musicSingle){
    clearJsonObject();

    saveGenericPart(musicSingle);
    
    jsonObject["type"]="musicSingle";
    jsonObject["hour"]=musicSingle.getLenght().ore();
    jsonObject["minutes"]=musicSingle.getLenght().minuti();
    jsonObject["second"]=musicSingle.getLenght().secondi();
    jsonObject["recordLabel"]=musicSingle.getRecordLabel();
        
    }

void JsonVisitor::visitFilm(Film& film){
    clearJsonObject();

    saveGenericPart(film);
    
    jsonObject["type"]="film";
    jsonObject["hour"]=film.getLenght().ore();
    jsonObject["minutes"]=film.getLenght().minuti();
    jsonObject["second"]=film.getLenght().secondi();
    jsonObject["mainActor"]=film.getMainActor();
        
}
