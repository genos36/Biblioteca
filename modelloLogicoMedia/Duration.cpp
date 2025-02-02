#include "Duration.h"
Duration::Duration(int h,int m,int s):sec((h>=0?h:0)*3600+((m>=0&&m<60)?m:0)*60+((s>=0&&s<60)?s:0)){}

int Duration::ore()const{
    return sec/3600;
}

int Duration::minuti()const{
    return (sec/60)%60;
}

int Duration::secondi()const{
    return sec%60;
}

 Duration::operator QString()const{
    return QString::number(ore())+":"+QString::number(minuti())+":"+QString::number(secondi());
 }

QTextStream& operator<<(QTextStream& os,const Duration& d){
    return os<<d.ore()<<":"<<d.minuti()<<":"<<d.secondi();
}


