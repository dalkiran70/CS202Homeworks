#ifndef CHAINHASHTABLE_H
#define CHAINHASHTABLE_H
#include "Bucket.h"
#include "FruitsAndVegatables.h"
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : Chain table
*/
class ChainHashTable
{
    public:
        ChainHashTable();
        virtual ~ChainHashTable();
       void insertFruitsAndVegatables(FruitsAndVegatables* newF);
        void printTable();
        void searchTable(string name, int& compCount);
        void deletetable(string name);
    protected:

    private:
        struct BucketNode{
        Bucket b;
        BucketNode* next;
        };
        static const int sizeOfTable = 151;
        BucketNode* arr[sizeOfTable] = {NULL};
        int computeHash(string name);
};

#endif // CHAINHASHTABLE_H
