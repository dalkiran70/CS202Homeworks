#ifndef FRUITSANDVEGATABLES_H
#define FRUITSANDVEGATABLES_H
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
* Description : Object of our Fruit and Vegatables and its amount
*/
class FruitsAndVegatables
{
    public:
        FruitsAndVegatables();
        virtual ~FruitsAndVegatables();
        void setName(string name);
        void setValue(string value);
        string getname();
        string getvalue();
    protected:

    private:
        string name;
        string value;
};

#endif // FRUITSANDVEGATABLES_H
