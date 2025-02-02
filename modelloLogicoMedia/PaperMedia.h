#ifndef PAPERMEDIA_H
#define PAPERMEDIA_H

#include "Media.h"

class PaperMedia: virtual public Media{
    private:
        int pages;
        QString editor;

    public:
    PaperMedia();
    PaperMedia(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description, 
            int Pages, QString Editor,
            int Total, int CurrentAvailability);

    int getPages()const;
    QString getEditor()const;
    
    void setPages(int);
    void setEditor(const QString&);

    bool matchString(const QString &)const override;

};






#endif