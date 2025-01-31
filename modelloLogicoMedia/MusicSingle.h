#ifndef MUSICSINGLE_H
#define MUSICSINGLE_H

#include "Audio.h"

class MusicSingle:public virtual Audio{
private:
    QString recordLable;

public:
    MusicSingle();
    MusicSingle(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability);
    MusicSingle(const QString& Title,const QString& Author,int Year,
            const AudioGenre& Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability);
    QString getRecordLabel()const;

    void accept(AbstractMediaVisitor&)override;

    void setRecordLabel(const QString&);
    //others
    bool matchString(const QString&)const override;
    MusicSingle* clone()const override;

};


#endif