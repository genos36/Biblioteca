#include "Query.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/SingleCD.h"
#include "../modelloLogicoMedia/Film.h"

Query::Query(const QString& Text):text(Text.toLower()){}

QVector<Media*> Query::search(const QVector<Media*>& SearchList)const{
    QVector<Media*> Results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->getTitle().toLower()==text){
           Results.push_back(*cit);
        }
        else if((*cit)->getAuthor().toLower()==text){
                Results.push_back(*cit);
                }
            else if((*cit)->getGenreName().toLower()==text){
                    Results.push_back(*cit);
                    }
                    else if(QString::number((*cit)->getYear())==text){
                      Results.push_back(*cit);  
                    }
               
        
    }
    return Results;
}


QVector<Book*> Query::search(const QVector<Book*>& SearchList)const{
    QVector<Book*> Results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->getTitle().toLower()==text){
           Results.push_back(*cit);
        }
        else if((*cit)->getAuthor().toLower()==text){
                Results.push_back(*cit);
                }
            else if((*cit)->getGenreName().toLower()==text){
                    Results.push_back(*cit);
                    }
                    else if(QString::number((*cit)->getYear())==text){
                      Results.push_back(*cit);  
                        }
                        else if((*cit)->getIsbn().toLower()==text){
                            Results.push_back(*cit);  
                        }
                            else if((*cit)->getEditor().toLower()==text){
                                Results.push_back(*cit);
                            }
    }
    return Results;
}


QVector<Magazine*> Query::search(const QVector<Magazine*>& SearchList)const{
    QVector<Magazine*> Results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->getTitle().toLower()==text){
           Results.push_back(*cit);
        }
        else if((*cit)->getAuthor().toLower()==text){
                Results.push_back(*cit);
                }
            else if((*cit)->getGenreName().toLower()==text){
                    Results.push_back(*cit);
                    }
                    else if(QString::number((*cit)->getYear())==text){
                      Results.push_back(*cit);  
                    }
                        else if((*cit)->getEditor().toLower()==text){
                                    Results.push_back(*cit);
                                }
               
        
    }
    return Results;
}

QVector<SingleCD*> Query::search(const QVector<SingleCD*>& SearchList)const{
    QVector<SingleCD*> Results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->getTitle().toLower()==text){
           Results.push_back(*cit);
        }
        else if((*cit)->getAuthor().toLower()==text){
                Results.push_back(*cit);
                }
            else if((*cit)->getGenreName().toLower()==text){
                    Results.push_back(*cit);
                    }
                    else if(QString::number((*cit)->getYear())==text){
                      Results.push_back(*cit);  
                    }
                        else if((*cit)->getRecordLabel()==text){
                            Results.push_back(*cit);  
                        }                    
               
        
    }
    return Results;
}

QVector<Film*> Query::search(const QVector<Film*>& SearchList)const{
    QVector<Film*> Results;

    for(auto cit=SearchList.cbegin();cit!=SearchList.cend();++cit){
        if((*cit)->getTitle().toLower()==text){
           Results.push_back(*cit);
        }
        else if((*cit)->getAuthor().toLower()==text){
                Results.push_back(*cit);
                }
            else if((*cit)->getGenreName().toLower()==text){
                    Results.push_back(*cit);
                    }
                    else if(QString::number((*cit)->getYear())==text){
                      Results.push_back(*cit);  
                    }
                        else if((*cit)->getMainActor().toLower()==text){

                        }
               
        
    }
    return Results;
}


