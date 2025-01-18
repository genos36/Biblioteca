#ifndef ABSTRACTMEDIAOBSERVER_H
#define ABSTRACTMEDIAOBSERVER_H
class Media;
class AbstractMediaObserver{
    public:
    
    virtual void update(Media&)=0;

    virtual ~AbstractMediaObserver()=default;



};




#endif
