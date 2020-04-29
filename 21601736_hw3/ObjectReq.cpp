#include "ObjectReq.h"
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
*Description: ObjectReq.cpp part
*/
ObjectReq::ObjectReq()
{
    id = 0;
    priority = 0;
    start = 0;
    time = 0;
    //ctor
}

ObjectReq::~ObjectReq()
{
    //dtor
}

int ObjectReq::getPri() const{
    return priority;
}
int ObjectReq::getTime() const{
    return time;
}
int ObjectReq::getStart() const{
    return start;
}
int ObjectReq::getId() const{
    return id;
}
void ObjectReq::setId( int id ){
    this->id = id;
}
void ObjectReq::setStart( int start )
{

    this->start = start;
}
void ObjectReq::setTime( int time ){
    this->time = time;
}
void ObjectReq::setPri( int priority){
    this->priority = priority;
}
