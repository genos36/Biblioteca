#ifndef MEDIA_H
#define MEDIA_H

#include<QString>
#include<QVector>

class AbstractMediaObserver;
class AbstractMediaVisitor;


class Media{
    private:
        QString title;
        QString author;
        int year;
        QString description;
        int total;                      //copie totali(disponibili+prestate)
        int currentAvailability;        //copie disponibili
        int genre;                      //un intero che specifica il genere
        QVector<AbstractMediaObserver *> observers;

    public:
        //costruttori e distruttore
        Media();
        Media(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description, int Total,
            int CurrentAvailability);

        virtual ~Media()=default;

        //getter
        QString getTitle()const;
        QString getAuthor()const;
        int getYear()const;
        QString getDescription()const;
        virtual int getTotal()const;
        virtual int getCurrentAvailability()const;
        int getGenre()const;
        virtual QString getGenreName()const=0;

        //setter
        void setTitle(const QString&);
        void setAuthor(const QString&);
        void setYear(int);
        void setDescription(const QString&);

        virtual void setTotal(int);
        virtual void addToTotal(int);                   //aumenta le copie totali
        virtual void RemoveFromTotal(int);              //riduce le copie totali

        virtual void setCurrentAvailability(int);
        virtual void addToCurrentAvailability(int);     //aumenta le copie disponibili
        virtual void RemoveFromCurrentAvailability(int);//riduce le copie disponibili

        void setGenre(int);


        //desing pattern
        virtual void accept(AbstractMediaVisitor&)=0;
        void addObserver(AbstractMediaObserver*);
        void notify(AbstractMediaObserver*);
        void notifyAll();

        //others
        virtual bool matchString(const QString&)const;

};



#endif