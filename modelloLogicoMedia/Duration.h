#ifndef DURATION_H
#define DURATION_H
#include <QTextStream>
class Duration{
private:
    int sec;

public:
    Duration();
    Duration(int);

    int secondi()const;
    int minuti()const;
    int ore()const;

};

QTextStream& operator<<(QTextStream&,const Duration&);

#endif