#ifndef OBJECTCOMS_H
#define OBJECTCOMS_H
#include "ObjectCom.h"
#include "heap.h"
#include "iostream"
#include "ObjectReq.h"
using namespace std;
/**
*Title : Heaps & AVL Trees
*Author: Muhammed Naci Dalkýran
*ID: 21601736
*Section: 01
*Assignment: 3
*Description: ObjectComs.h part
*/

class ObjectComs
{
    public:
        ObjectComs(int counter);
        virtual ~ObjectComs();
        bool AvAllOfthem();
        bool busyAllOfthem();
        int getTotalWait();
        void progress(ObjectReq* objreq, int current,string& display);
        void update();

    protected:

    private:
        int counter;
        ObjectCom* computers;
        int totalWait;
};

#endif // OBJECTCOMS_H
