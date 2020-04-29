#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
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
*Description: PriorityQueue.h part
*/
class PriorityQueue
{
    public:
    heap h;
    bool pqIsEmpty() const;
	void pqInsert(ObjectReq*& newItem) ;
	void pqDelete(ObjectReq*& priorityItem) ;
    void display ();

};

#endif // PRIORITYQUEUE_H
