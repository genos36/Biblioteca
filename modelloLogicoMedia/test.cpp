#include "Book.h"
#include "Magazine.h"
#include "SingleCD.h"
#include "Film.h"
#include "../Visitors/Query.h"
#include "../Visitors/FilterVisitor.h"

#include<QString>
#include<QDebug>

void StampaLibro(const Book&);
int main(){
    Book provaD;

    Book prova1("Appunti di programmazione ad oggetti","Francesco Ranzato", 2023,BookGenre::Sci_fy ,"libro del corso di programmazione ad oggetti",379,"libreria progetto","9788831901710",10,10);
    Book prova2("test","john doe", -100,100 ,"descrizione",-379,"tw","m",-100,-1);

    Magazine rivista1("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,1,5,5);
    Magazine rivista2("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,2,5,5);
    Magazine rivista3("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,-23,5,5);
    Magazine rivista4("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,4,5,5);

    SingleCD CD1("Barbagianni","Nanowar of Steel",2016,AudioGenre::Metal,"Barbagianni Barbagianni Barbagianni Barbagianni",-1,"Napalm Records",-20,45);
    SingleCD CD2("you're gonna go far kid","The offspring",2008,AudioGenre::Punk,"album half turism",4000,"non lo so",-20,45);
    SingleCD CD3("Paperella gay","SPJokey",2008,AudioGenre::Unknown,"sei l'uccello che vorrei",4000,"non lo so",-20,45);

    Film film1("interstellar","christofer nolan",2008,VideoGenre::Sci_fy,"buchi neri",4000000,"Mattew mcconagaughy",10,-1);
    Film film2("tenet","christofer nolan",2008,VideoGenre::Sci_fy,"buchi neri",4000000,"john david washington",10,-1);

    QVector<Media*> genericList;
    genericList.push_back(&provaD);
    genericList.push_back(&prova1);
    genericList.push_back(&prova2);
    genericList.push_back(&rivista1);
    genericList.push_back(&rivista2);
    genericList.push_back(&rivista3);
    genericList.push_back(&rivista4);
    genericList.push_back(&CD1);
    genericList.push_back(&CD2);
    genericList.push_back(&CD3);
    genericList.push_back(&film1);
    genericList.push_back(&film2);

    Query QueryProva("Fantascienza");

    FilterVisitor filtro;

    filtro.addMedia(genericList);
/*
    for(auto it=genericList.begin();it!=genericList.end();++it){
        filtro.addMedia(**it);
    }
*/
    QVector<Media*> risultatiGenerici(QueryProva.search(genericList));
    
    for(auto it=risultatiGenerici.begin();it!=risultatiGenerici.end();++it){
        qDebug()<<(*it)->getTitle()<<Qt::endl;
    }

    QueryProva=Query("Tenet");
    QVector<Film*> risultatiFilm(QueryProva.search(filtro.getfilms()));

    for(auto it=risultatiFilm.begin();it!=risultatiFilm.end();++it){
        qDebug()<<(*it)->getTitle()<<Qt::endl;
        qDebug()<<(*it)->getMainActor()<<Qt::endl;
        qDebug()<<(*it)->getGenreName()<<Qt::endl;
        

    }
/*
    StampaLibro(provaD);
   StampaLibro(prova1);
    StampaLibro(prova2);

    Media * p=&prova1;

    qDebug()<<Qt::endl<<Qt::endl <<p->getGenreName()<<Qt::endl;
*/

}


void StampaLibro(const Book& b){
    QTextStream cout(stdout);
    cout<<"titolo: "<<b.getTitle()<<Qt::endl
    <<" autore: "<<b.getAuthor()<<Qt::endl
    <<" year: "<<b.getYear()<<Qt::endl
    <<" genere: "<<b.getGenreName()<<Qt::endl
    <<" descrizione "<<b.getDescription()<<Qt::endl
    <<" pagine: "<<b.getPages()<<Qt::endl
    <<" editore: "<<b.getEditor()<<Qt::endl
    <<" ISBN: "<<b.getIsbn()<<Qt::endl
    <<"copie disponibili: "<<b.getCurrentAvailability()<<"/"<<b.getTotal()<<Qt::endl;
}
