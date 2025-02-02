#include "Query.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"

Query::Query(const QString& Text):text(Text.toLower()){}

QVector<Media*> Query::search(const QVector<Media*>& SearchList)const{
    QVector<Media*> results;
    if(text=="")return results=SearchList;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}

QVector<Book*> Query::search(const QVector<Book*>& SearchList)const{
    QVector<Book*> results;
    if(text=="")return results=SearchList;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}


QVector<Magazine*> Query::search(const QVector<Magazine*>& SearchList)const{
    QVector<Magazine*> results;
    if(text=="")return results=SearchList;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}

QVector<MusicSingle*> Query::search(const QVector<MusicSingle*>& SearchList)const{
    QVector<MusicSingle*> results;
    if(text=="")return results=SearchList;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}

QVector<Film*> Query::search(const QVector<Film*>& SearchList)const{
    QVector<Film*> results;
    if(text=="")return results=SearchList;
    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->matchString(text)){
                   results.push_back(*cit); 
               }      
    }
    return results;
}


    bool Query::operator==(const Query& q)const{
        return text==q.text;
    }

        bool Query::operator!=(const Query& q)const{
        return text!=q.text;
    }

    bool Query::hasMatch(const Media& media)const{
        return text==""||media.matchString(text);
    }


    Query* Query::clone()const{
        return new Query(text);
    }