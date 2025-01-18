#ifndef SINGLECD_H
#define SINGLECD_H

#include "Audio.h"

class SingleCD:public virtual Audio{
private:
    QString recordLable;

public:
    SingleCD();
    SingleCD(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability);
    SingleCD(const QString& Title,const QString& Author,int Year,
            const AudioGenre& Genre, const QString& Description,
            const Duration& Lenght,const QString& RecordLabel,
            int Total,
            int CurrentAvailability);
    QString getRecordLabel()const;

    void accept(AbstractMediaVisitor&)override;

    void setRecordLabel(const QString&);

};


#endif