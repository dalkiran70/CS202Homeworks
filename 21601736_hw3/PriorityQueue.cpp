#include "PriorityQueue.h"
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
*Description: PriorityQueue.cpp part
*/
bool PriorityQueue::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(ObjectReq*& newItem){
		h.heapInsert(newItem);

}

void PriorityQueue::pqDelete(ObjectReq*& priorityItem) {
        if(!pqIsEmpty())
		h.heapDelete(priorityItem);


}
void PriorityQueue::display(){
    for(int i = 0; i < h.size; i++){
        cout<<h.item[i]->getId()<<endl;
    }

}
