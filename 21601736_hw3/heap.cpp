#include "heap.h"


#include "iostream"
using namespace std;
/**
*Title : Heaps & AVL Trees
*Author: Muhammed Naci Dalkýran
*ID: 21601736
*Section: 01
*Assignment: 3
*Description: heap.cpp part
*/
heap::heap() : size(0)
{
    //ctor
}

heap::~heap()
{
    //dtor
}

bool heap::heapIsEmpty()const{
    return (size == 0);
}

void heap::heapInsert(ObjectReq*& newItem){
    item[size] = newItem;
    int place = size;
    int parent = (place - 1) / 2;
    while( ( place > 0 ) && (item[place]->getPri() > item[parent]->getPri()))
    {
      ObjectReq* temp = item[parent];
      item[parent] = item[place];
      item[place] = temp;

      place = parent;
      parent = (place - 1)/2;
   }


    ++size;
}

void heap::heapDelete(ObjectReq*& rootItem) {
    if(!heapIsEmpty()){
        rootItem = item[0];
    item[0] = item[--size];
    heapRebuild(0);
    }

}

void heap::heapRebuild(int root){
    int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) && (item[rightChild]->getPri() >= item[child]->getPri() )
                && item[rightChild]->getStart() < item[child]->getStart())
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( item[root]->getPri()<= item[child]->getPri()
      && item[rightChild]->getStart() > item[child]->getStart()) {
			ObjectReq* temp = item[root];
			item[root] = item[child];
			item[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}
