#include "ISBN.h"

ISBN::ISBN(const QString& code):QString(sanify(code)){}

//funzione statica che data una stringa restituisce una stringa lunga 13
QString ISBN::sanify(const QString& code){
    if(code.length()==13)return code;

    QString sanifiedCode(code);
    if(sanifiedCode.length()>13){
        sanifiedCode=sanifiedCode.left(13);
    }
    else{
        if(sanifiedCode.length()<13){
            sanifiedCode=QString("0").repeated(13-sanifiedCode.length())+sanifiedCode;
        }
    }
    return sanifiedCode;
}

QTextStream& operator<<(QTextStream& os, const ISBN& Isbn){
    if(Isbn.length()==13)return os<<Isbn.mid(0,3)+"-"+Isbn.mid(3,2)+"-"+Isbn.mid(5,5)+"-"+Isbn.mid(10,2)+"-"+Isbn.mid(12,1);
    else return os<<"qualcosa è andato storto, l'ISBN non è di 13 caratteri";
}
/*
ISBN::operator QString(){
    return isbn_13;
}

*/
