#include "OpenHashTable.h"
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
* Description : Open hashtable
*/
using namespace std;
OpenHashTable::OpenHashTable()
{   sizeOfTable = 151; //Prime number
    //ctor
}

OpenHashTable::~OpenHashTable()
{
    //dtor
}

int OpenHashTable::computeHash(string name){
    int total = 0;
    for(int i = 0; i< name.size()  ; ++i){
        total = total + name[i];
    }
    return total % sizeOfTable;

}
void OpenHashTable::insertFruitsAndVegatables(FruitsAndVegatables newF,int& coll){

    int index = computeHash(newF.getname());
    int i = 1;
    int temp = index;
    while(arr[temp].getOccupied() && !arr[temp].getEmpty() && !arr[temp].getDeleted() ){

         temp = (i*i + index)%sizeOfTable;

         if (temp <0)
         temp += sizeOfTable;

         ++i;
         coll++;
    }
    arr[temp].setOccupied(true);
    arr[temp].setEmpty(false);
    arr[temp].setDeleted(false);
    arr[temp].setItem(newF);
}
void OpenHashTable::printTable(){

    for(int i = 0; i < sizeOfTable; i++ ){
            if(!arr[i].getEmpty() && !arr[i].getDeleted() && arr[i].getOccupied()){
                     cout<<i<<" : " << arr[i].getItem().getname()<<" = "<< arr[i].getItem().getvalue()<<", "<<endl;

            }
    }
}
void OpenHashTable::searchTable(string name,int &comp){
   int index = computeHash(name);
    int i = 1;
    int temp = index;
    while(arr[temp].getOccupied() && !arr[temp].getEmpty() )
    {
        if(arr[temp].getItem().getname() == name && !arr[temp].getDeleted()){
                comp++;
            cout<< "Name: "<<arr[temp].getItem().getname()<<" Available: "<<arr[temp].getItem().getvalue()<<endl;
            break;
        }
        else{
         temp = (i*i + index)%sizeOfTable;

         if (temp <0)
         temp += sizeOfTable;

         ++i;
        }

    }

}
void OpenHashTable::deletetable(string name){
   int index = computeHash(name);
    int i = 1;
    int temp = index;
    while(arr[temp].getOccupied() && !arr[temp].getEmpty() )
    {
        if(arr[temp].getItem().getname() == name && !arr[temp].getDeleted()){
           arr[temp].setOccupied(true);
           arr[temp].setEmpty(false);
           arr[temp].setDeleted(true);
            break;
        }
        else{
         temp = (i*i + index)%sizeOfTable;
         if (temp <0)
         temp += sizeOfTable;
         ++i;
        }


    }
}
