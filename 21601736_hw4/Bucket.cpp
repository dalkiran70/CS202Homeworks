#include "Bucket.h"
#include "fstream"
#include "string"
#include <cstring>
#include "iostream"
#include <stdlib.h>
#include <sstream>
using namespace std;
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : bucket class for gathering FruitAndVagitable object and flags
*/
Bucket::Bucket()
{   setDeleted(false);
    setOccupied(false);
    setEmpty(true);

    //ctor
}

Bucket::~Bucket()
{
    //dtor
}

bool Bucket::getOccupied(){
    return occupied;
}
bool Bucket::getDeleted()
{
    return deleted;
}
bool Bucket::getEmpty()
{
    return emptya;
}
FruitsAndVegatables Bucket::getItem()
{
    return item;
}
void Bucket::setOccupied(bool bo)
{
    occupied = bo;
}
void Bucket::setDeleted(bool bo)
{
    deleted = bo;
}
void Bucket::setEmpty(bool bo)
{
    emptya = bo;
}
void Bucket::setItem(FruitsAndVegatables it){
    item = it;
}
