#include "Query.h"
#include "../modelloLogicoMedia/Book.h"
#include "../modelloLogicoMedia/Magazine.h"
#include "../modelloLogicoMedia/MusicSingle.h"
#include "../modelloLogicoMedia/Film.h"

Query::Query(const QString& Text):text(Text.toLower()){}




    bool Query::operator==(const Query& q)const{
        return text==q.text;
    }

        bool Query::operator!=(const Query& q)const{
        return text!=q.text;
    }

    bool Query::hasMatch(const Media& media)const{
        return text==""||media.matchString(text);
    }


    Query* Query::clone()const{
        return new Query(text);
    }