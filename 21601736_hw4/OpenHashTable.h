#ifndef OPENHASHTABLE_H
#define OPENHASHTABLE_H
#include "fstream"
#include "string"
#include <cstring>
#include "iostream"
#include <stdlib.h>
#include <sstream>
#include "FruitsAndVegatables.h"
#include "Bucket.h"

using namespace std;
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : Open hashtable
*/
class OpenHashTable
{
    public:
        OpenHashTable();
        virtual ~OpenHashTable();
         void insertFruitsAndVegatables(FruitsAndVegatables newF,int& coll);
        void printTable();
        void searchTable(string name, int &comp);
        void deletetable(string name);
    protected:

    private:
        int sizeOfTable;
        Bucket arr[151];
        int computeHash(string name);

};

#endif // OPENHASHTABLE_H
