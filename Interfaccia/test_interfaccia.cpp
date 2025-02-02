#include <QApplication>
#include "BibliotecaMainWindow.h"
#include "SearchListWidgetMedia.h"
#include "BookEditView.h"
#include "MagazineEditView.h"
#include "MusicSingleEditView.h"
#include "FilmEditView.h"

#include "../Visitors/DetailView.h"
#include "EditView.h"
#include "DurationSlider.h"
#include "SearchInterface.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BibliotecaMainWindow prova;
    //prova.show();    

    Book prova1("Appunti di programmazione ad oggetti","Francesco Ranzato", 2023,BookGenre::Sci_fy ,"libro del corso di programmazione ad oggetti",379,"libreria progetto","9788831901710",10,10);
    Book prova2("test","john doe", -100,100 ,"descrizione",-379,"tw","m",-100,-1);

    Magazine rivista1("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,1,5,5);
    Magazine rivista2("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,2,5,5);
    Magazine rivista3("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,-23,5,5);
    Magazine rivista4("Il satiro sientifico","BarbascuraX",2020,MagazineGenre::scientific,"Preparatevi a essere divulgati male",251,"mondadori",Frequency::no_data,4,5,5);

    MusicSingle CD1("Barbagianni","Nanowar of Steel",2016,AudioGenre::Metal,"Barbagianni Barbagianni Barbagianni Barbagianni",Duration(6),"Napalm Records",-20,45);
    MusicSingle CD2("you're gonna go far kid","The offspring",2008,AudioGenre::Punk,"album half turism",Duration(4000),"non lo so",-20,45);
    MusicSingle CD3("Paperella gay","SPJokey",2008,AudioGenre::Unknown,"sei l'uccello che vorrei",Duration(4000),"non lo so",-20,45);

    Film film1("interstellar","christofer nolan",2008,VideoGenre::Sci_fy,"buchi neri",Duration(4000000),"Mattew mcconagaughy",10,-1);
    Film film2("tenet","christofer nolan",2008,VideoGenre::Sci_fy,"buchi neri",Duration(4000000),"john david washington",10,-1);

    QVector<Media*> genericVector;
    genericVector.push_back(&prova1);
    genericVector.push_back(&prova2);
    genericVector.push_back(&rivista1);
    genericVector.push_back(&rivista2);
    genericVector.push_back(&rivista3);
    genericVector.push_back(&rivista4);
    genericVector.push_back(&CD1);
    genericVector.push_back(&CD2);
    genericVector.push_back(&CD3);
    genericVector.push_back(&film1);
    genericVector.push_back(&film2);

    ListWidgetMedia* provListaGenerica=new ListWidgetMedia();
    //SearchListWidgetMedia* provListaRicerca=new SearchListWidgetMedia("");

    for(auto it=genericVector.begin();it!=genericVector.end();++it){
        ListWidgetMediaItem* item = new ListWidgetMediaItem(**it);
        provListaGenerica->addItem(item);

    }
    /*
    //provListaGenerica->show();

    provListaRicerca->setQuery(Query("Fantascienza"));
    provListaRicerca->createBasicSearch(*provListaGenerica);
    //provListaRicerca->show();

    (*(provListaRicerca->item(1)))->setTitle("un pollllllllllllllllllloS");

    provListaGenerica->refresh();
    provListaRicerca->refresh();
    DetailView provaVistaLibro(prova1);
    DetailView provaVistaRivista(rivista4);
    DetailView provaVistaMusica(CD1);
    DetailView provaVistaFilm(film1);
    (provaVistaLibro.getWidget())->show();
    (provaVistaRivista.getWidget())->show();
    (provaVistaMusica.getWidget())->show();
    (provaVistaFilm.getWidget())->show();

    qDebug()<<rivista4.getEditor();
*/
BookEditView provaEdit(prova1);
provaEdit.show();

/*
MagazineEditView provaEditMag(rivista1);
provaEditMag.show();
    //DurationSlider provaSlider(Duration(1));
    //provaSlider.show();

    MusicSingleEditView provaCd(CD1);
    provaCd.show();

FilmEditView provaFilm(film1);
provaFilm.show();
    qDebug()<<film1.getLenght()<<Duration(1);

*/

    SearchInterface provaSI;
    provaSI.show();


    return app.exec();
}


//RESOURCES += resources.qrc