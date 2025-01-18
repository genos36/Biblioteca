#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "PaperMedia.h"
#include "Genre/MagazineGenre.h"
    
    enum class Frequency{
        no_data=-1,
        settimanale,
        mensile
    };
class Magazine:virtual public PaperMedia{
    private:
    Frequency frequency;
    int nEdition;

    public:

    static QString intToMagazineGenre(int);
    static int MagazineGenreToInt(const MagazineGenre&); 

    static QString FrequencytoString(const Frequency&);
    static int FrequencyToInt(const Frequency&);

    Magazine();
    Magazine(const QString& Title,const QString& Author,
            int Year,int Genre, const QString& Description, 
            int Pages, QString Editor,const Frequency& freq,
            int NEdition, 
            int Total, int CurrentAvailability);
    Magazine(const QString& Title,const QString& Author,
            int Year,const MagazineGenre& Genre, const QString& Description, 
            int Pages, QString Editor,const Frequency& freq,
            int NEdition, 
            int Total, int CurrentAvailability);

    int getNEdition()const;
    void setNEdition(int);

    Frequency getFrequency()const;
    QString getFrequencyString()const;

    void setFrequency(const Frequency&);

    QString getGenreName()const override; 

    void accept(AbstractMediaVisitor&) override;


};

#endif