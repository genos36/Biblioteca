#include "PaperMedia.h"

PaperMedia::PaperMedia():pages(0),editor("Default editor"){}

PaperMedia::PaperMedia(const QString& Title,const QString& Author,int Year,
            int Genre, const QString& Description, 
            int Pages, const QString& Editor,
            int Total, int CurrentAvailability):
            Media::Media(Title,Author,Year,Genre,Description,Total,CurrentAvailability),
            pages(Pages>0?Pages:0),editor(Editor){}

int PaperMedia::getPages()const{
    return pages;
}

QString PaperMedia::getEditor()const{
    return editor;
}

void PaperMedia::setPages(int Pages){
    if(Pages>0){
        pages=Pages;
    }
}

void PaperMedia::setEditor(const QString& Editor){
    editor=Editor;
}

bool PaperMedia::matchString(const QString & match)const{
    return Media::matchString(match)||editor.startsWith(match,Qt::CaseInsensitive);
}