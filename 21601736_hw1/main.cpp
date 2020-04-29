/**
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Naci DalkÝran
* ID: 21601736
* Section: 1
* Assignment: 1
* Description: this part is main part
*/
#include "string"
#include "sorting.h"
#include <iostream>
#include <time.h>
using namespace std;
int main() {
    int* arr1 = new int[12];
    int* arr2 = new int[12];
    int* arr3 = new int[12];
    int number;
    int fixedArray[12] = {22, 11, 6, 7, 30, 2, 27, 24, 9,1, 20, 17};
    for(int i = 0; i < 12; ++i){
        arr1[i] = fixedArray[i];

    }
    for(int i = 0; i < 12; i++){

        arr2[i] = arr1[i];

    }
    for(int i = 0; i < 12; i++){

        arr3[i] = fixedArray[i];

    }
    int qComp = 0;
    int iComp = 0;
    int hComp = 0;
    int qMove = 0;
    int iMove = 0;
    int hMove = 0;
    int first = 0;
    int last = 11;
    printArray(arr1,12);
    printArray(arr2,12);
    printArray(arr3,12);

    quickSort(arr1,first,last,qComp,qMove);
    printArray(arr1,12);
    insertionSort(arr2,12,iComp,iMove);
    printArray(arr2,12);

    hybridSort(arr3,12,hComp,hMove);
    printArray(arr3,12);
    delete []arr1;
    delete []arr2;
    delete []arr3;

    performanceAnalysis();
    return 0;

}

