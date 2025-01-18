#include "Duration.h"
Duration::Duration():sec(0){}
Duration::Duration(int s):sec(s>=0?s:0){}

int Duration::ore()const{
    return sec/3600;
}

int Duration::minuti()const{
    return (sec/60)%60;
}

int Duration::secondi()const{
    return sec%60;
}

QTextStream& operator<<(QTextStream& os,const Duration& d){
    return os<<d.ore()<<":"<<d.minuti()<<":"<<d.secondi();
}


