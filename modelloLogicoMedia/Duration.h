#ifndef DURATION_H
#define DURATION_H
#include <QTextStream>
#include <QString>

class Duration{
private:
    int sec;

public:
    Duration();
    Duration(int);

    int secondi()const;
    int minuti()const;
    int ore()const;
    operator QString()const;
};

QTextStream& operator<<(QTextStream&,const Duration&);

#endif