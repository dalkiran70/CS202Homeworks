
#include "fstream"
#include "string"
#include <cstring>
#include "iostream"
#include <stdlib.h>
#include <sstream>
#include "FruitsAndVegatables.h"
#ifndef BUCKET_H
#define BUCKET_H
using namespace std;
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : bucket class for gathering FruitAndVagitable object and flags
*/
class Bucket
{
    public:
        Bucket();
        virtual ~Bucket();
        bool getOccupied();
        bool getDeleted();
        bool getEmpty();
        FruitsAndVegatables getItem();
        void setOccupied(bool bo);
        void setDeleted(bool bo);
        void setEmpty(bool bo);
        void setItem(FruitsAndVegatables it);
    protected:

    private:
        bool occupied;
        bool deleted;
        bool emptya;
        FruitsAndVegatables item ;


};

#endif // BUCKET_H
