#include "FruitsAndVegatables.h"
#include "fstream"
#include "string"
#include <cstring>
#include "iostream"
#include <stdlib.h>
#include <sstream>
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : Object of our Fruit and Vegatables and its amount
*/
using namespace std;
FruitsAndVegatables::FruitsAndVegatables()
{
    //ctor
}

FruitsAndVegatables::~FruitsAndVegatables()
{
    //dtor
}
void FruitsAndVegatables::setName(string n){
    name = n;
}
void FruitsAndVegatables::setValue(string v){
    value = v;
}
string FruitsAndVegatables::getname(){
    return name;
}
string FruitsAndVegatables::getvalue(){
    return value;
}
