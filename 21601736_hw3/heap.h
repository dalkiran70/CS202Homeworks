#ifndef HEAP_H
#define HEAP_H
#include <string>
#include "fstream"
#include "ObjectReq.h"

#include "iostream"
using namespace std;
/**
*Title : Heaps & AVL Trees
*Author: Muhammed Naci Dalkýran
*ID: 21601736
*Section: 01
*Assignment: 3
*Description: heap.h part
*/
const int MAX_SIZE = 120;
class heap
{
    public:
        heap();
        virtual ~heap();
        bool heapIsEmpty() const;
        void heapInsert(ObjectReq*& newItem);
        void heapDelete(ObjectReq*& rootItem);
    int size;
    ObjectReq* item[MAX_SIZE];
    protected:
    void heapRebuild(int root);



};

#endif // HEAP_H
