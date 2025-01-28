#include "Query.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"

Query::Query(const QString& Text):text(Text.toLower()){}

QVector<Media*> Query::search(const QVector<Media*>& SearchList)const{
    QVector<Media*> results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}

QVector<Book*> Query::search(const QVector<Book*>& SearchList)const{
    QVector<Book*> results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}


QVector<Magazine*> Query::search(const QVector<Magazine*>& SearchList)const{
    QVector<Magazine*> results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}

QVector<MusicSingle*> Query::search(const QVector<MusicSingle*>& SearchList)const{
    QVector<MusicSingle*> results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}

QVector<Film*> Query::search(const QVector<Film*>& SearchList)const{
    QVector<Film*> results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}
