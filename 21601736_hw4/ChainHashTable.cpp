#include "ChainHashTable.h"
#include "FruitsAndVegatables.h"
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : Chain table
*/
ChainHashTable::ChainHashTable()
{
    //ctor
}

ChainHashTable::~ChainHashTable()
{
    //dtor
}
void ChainHashTable::insertFruitsAndVegatables(FruitsAndVegatables* newF) {

	int index = computeHash(newF->getname());

	BucketNode* bucket = new BucketNode;
	bucket->b.setItem(*newF);
	bucket->next = NULL;
	if (arr[index] == NULL ){
		arr[index] = bucket;
	}
	else{
		bucket->next=arr[index];
		arr[index] = bucket;

	} // end if

}
void ChainHashTable::searchTable(string name, int& compCount) {

		int index = computeHash(name);
		BucketNode* current;
		current = arr[index];
		while ( current != nullptr) {
			compCount++;
			if ( current->b.getItem().getname() == name) {
				cout << "Name: " << name << "\tAvailable Quantity: " << current->b.getItem().getvalue() <<endl;
				compCount++;
				//cout<<compCount<<endl;
				return;

			}
			current = current->next;
		}


}
int ChainHashTable::computeHash(string name){
    int total = 0;
    for(int i = 0; i< name.size()  ; ++i){
        total = total + name[i];
    }
    return total % sizeOfTable;

}

void ChainHashTable::deletetable(string name) {

		int index = computeHash(name);

		if (arr[index] != NULL){
			// Special case - first node has target
			if (name == arr[index]->b.getItem().getname()){
			BucketNode* toDelete = arr[index];
			arr[index] = arr[index]->next;
			delete toDelete;
			toDelete = NULL ;
			return;
			}
			else {
				BucketNode* prevPtr = arr[index];
				BucketNode* curPtr = prevPtr->next;
				while ((curPtr != NULL)){
					if (name == curPtr->b.getItem().getname())	{
						prevPtr->next = curPtr->next;
						delete curPtr;
						curPtr = NULL ;
						return;
					}
					else {
						prevPtr = curPtr;
						curPtr = curPtr->next;
					}
				}
			}
		}
}
void ChainHashTable:: printTable() {
	BucketNode* current;
	for (int i = 0; i < sizeOfTable; i++) {
			current = arr[i];
			//cout<<i;
		if ( current != NULL) {
                cout<<i<< ": ";
				while ( current != NULL) {
					cout << current->b.getItem().getname() << " = " << current->b.getItem().getvalue() << " , ";
					current = current->next;
				}
                		cout << endl;
		}


	}

}
