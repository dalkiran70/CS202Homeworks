#ifndef OBJECTREQ_H
#define OBJECTREQ_H
#include <string>
#include "fstream"

#include "iostream"
using namespace std;
/**
*Title : Heaps & AVL Trees
*Author: Muhammed Naci Dalkýran
*ID: 21601736
*Section: 01
*Assignment: 3
*Description: ObjectReq.h part
*/

class ObjectReq
{
    public:
        ObjectReq();
        virtual ~ObjectReq();
        int getPri() const;
        int getTime() const;
        int getStart() const;
        int getId() const;
        void setId( int id );
        void setStart( int start );
        void setTime( int time );
        void setPri( int priority);
    protected:

    private:
   int id;
   int priority;
   int start;
   int time;
};

#endif // OBJECTREQ_H
