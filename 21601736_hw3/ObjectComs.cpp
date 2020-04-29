#include "ObjectComs.h"
#include "heap.h"
#include "ObjectReq.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
/**
*Title : Heaps & AVL Trees
*Author: Muhammed Naci Dalkýran
*ID: 21601736
*Section: 01
*Assignment: 3
*Description: ObjectComs.cpp part
*/
ObjectComs::ObjectComs(int counter)
{  totalWait = 0;
     this->counter = counter;
    computers = new ObjectCom[counter];

    //ctor
}

ObjectComs::~ObjectComs()
{
    //dtor
}
bool ObjectComs::AvAllOfthem(){
    bool cont = true;
    int i = 0;
    while(i < counter){
        if( !computers[i].IsAvailable){
            cont = false;
        }
        ++i;
    }
    return cont;
}
bool ObjectComs::busyAllOfthem(){
    bool cont = true;
    int i = 0;
    while(i < counter){
        if( computers[i].IsAvailable){
            cont = false;
        }
        ++i;
    }
    return cont;
}
int ObjectComs:: getTotalWait(){
    return totalWait;
}
void ObjectComs::progress(ObjectReq* objreq, int current,string& display){

    bool cont = false;
    int i = 0;
    while(i < counter && !cont){
        if( computers[i].IsAvailable){
            display += "Computer " + to_string(i) + " takes request "
                    + to_string( objreq->getId()) + " at ms " + to_string( current)
                    + " (wait: " +to_string( current - objreq->getStart() )
                    + " ms)\n";
            computers[i].IsAvailable = false;
            computers[i].leftingTime = objreq ->getTime();
            totalWait += current - objreq->getStart();
            cont = true;
        }
        ++i;
    }
}
void ObjectComs:: update(){
    int i = 0;
    while(i < counter){
        if( !computers[i].IsAvailable && --computers[i].leftingTime <= 0){
            computers[i].leftingTime = 0;
            computers[i].IsAvailable = true;
        }
        ++i;
    }
}
