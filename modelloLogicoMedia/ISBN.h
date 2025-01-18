#ifndef ISBN_H
#define ISBN_H

#include <QString>
#include <QTextStream>

class ISBN:public QString{
    public:
    static QString sanify(const QString&);
    ISBN()=default;
    ISBN(const QString&);
    
    //operator QString();



};
    QTextStream& operator<<(QTextStream& os, const ISBN&);

#endif