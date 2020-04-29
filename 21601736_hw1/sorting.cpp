/**
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Naci Dalk›ran
* ID: 21601736
* Section: 1
* Assignment: 1
* Description: This are sorting algorithms
*/
#include "string"
#include "sorting.h"
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
void partitionQuckSort(int *arr, int f ,int l, int &pivotIndex, int &compCount, int &moveCount){
    int pivot = arr[f];
    ++moveCount;
    int lastS1=f;
    int firstUnknown = f + 1;
    for( ; firstUnknown <= l; ++firstUnknown ){
        ++compCount;
        if(arr[firstUnknown] < pivot){
            ++lastS1;
            ++compCount;
            swap(arr[firstUnknown],arr[lastS1]);
            moveCount = 3 + moveCount;

        }
    }
    swap(arr[f],arr[lastS1]);
    moveCount = 3 + moveCount;
    pivotIndex = lastS1;
}
void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount){
    int pivotIndex;
    if(f < l ){
        ++compCount;
        partitionQuckSort(arr, f, l,pivotIndex, compCount, moveCount);
        quickSort(arr, f, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, l, compCount, moveCount);
    }
}

void insertionSort(int *arr, int n, int &compCount, int &moveCount) {

    for (int unsorted = 1; unsorted < n; ++unsorted) {
        ++compCount;
        int nextItem = arr[unsorted];
        int loc = unsorted;
        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
            ++compCount;
            arr[loc] = arr[loc-1];
            ++moveCount;
    }
    arr[loc] = nextItem;
    ++moveCount;
    }
  }
  void hybridSort(int *arr, int size, int &compCount, int &moveCount){
    if(size <= 10){
        insertionSort(arr,size - 1,compCount,moveCount);
        ++compCount;
    }
    else{
        ++compCount;
        int pivotIndex;
        partitionQuckSort(arr,0,size -1,pivotIndex,compCount,moveCount);
        quickSort(arr,0,pivotIndex-1,compCount,moveCount);
        quickSort(arr,pivotIndex+1,size - 1 ,compCount,moveCount);
    }
}

void printArray(int *arr, int size){
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
        return;
}
void performanceAnalysis(){

    int sizeArray[10] = {1500,3000, 4500,6000, 7500, 9000, 10500, 12000, 13500, 15000};
    int qCompArray[10];
    int iCompArray[10];
    int hCompArray[10];
    int qMoveArray[10];
    int iMoveArray[10];
    int hMoveArray[10];
    double qTime[10];
    double iTime[10];
    double hTime[10];

    for(int i = 0; i <10; ++i){

        int sizeOfArrays = sizeArray[i];
        int *arr1 = new int[sizeOfArrays];
        int *arr2 = new int[sizeOfArrays];
        int *arr3 = new int[sizeOfArrays];

        for(int j = 0; j < sizeOfArrays; ++j){
            int number = rand() % RAND_MAX;
            arr1[j] = number;
            arr2[j] = number;
            arr3[j] = number;
        }
        int first = 0;
        int last = sizeOfArrays - 1;

        int quickComp = 0;
        int insertComp = 0;
        int hybridComp = 0;
        int quickMove = 0;
        int insertMove = 0;
        int hybridMove = 0;

        chrono::time_point< chrono::system_clock > startTime;
        chrono::duration< double, milli > elapsedTime;

        startTime = chrono::system_clock::now();
        quickSort(arr1, first,sizeOfArrays,quickComp,quickMove);
        elapsedTime = chrono::system_clock::now() - startTime;
        qTime[i] = elapsedTime.count();
        qCompArray[i] = quickComp;
        qMoveArray[i] = quickMove;

        startTime = chrono::system_clock::now();
        insertionSort(arr2, sizeOfArrays,insertComp,insertMove);
        elapsedTime = chrono::system_clock::now() - startTime;
        iTime[i] = elapsedTime.count();
        iCompArray[i] = insertComp;
        iMoveArray[i] = insertMove;

        startTime = chrono::system_clock::now();
        hybridSort(arr3,sizeOfArrays,hybridComp,hybridMove);
        elapsedTime = chrono::system_clock::now() - startTime;
        hTime[i] = elapsedTime.count();
        hCompArray[i] = hybridComp;
        hMoveArray[i] = hybridMove;
        delete []arr1;
        delete []arr2;
        delete []arr3;

    }
    string str1 = "-----------------------------------------------------";
    string str2 = "Array Size\tTime Elapsed\tcompCount\tmoveCount";
    cout<<str1<<endl;
    cout<<"Part a - Time analysis of Quick Sort"<<endl;
    cout<<str2<<endl;
    for(int j = 0; j < 10; ++j){
        cout<<sizeArray[j]<<"\t\t"<<qTime[j]<<"\t\t"<<qCompArray[j]<<"\t\t"<<qMoveArray[j]<<endl ;
    }

    cout<<str1<<endl;
    cout<<"Part b - Time analysis of Insertion Sort"<<endl;
    cout<<str2<<endl;

    for(int j = 0; j < 10; ++j){
        if(j <= 3)
            cout<<sizeArray[j]<<"\t\t"<<(double)iTime[j]<<"\t\t"<<iCompArray[j]<<"\t\t"<<iMoveArray[j]<<endl ;
        else
            cout<<sizeArray[j]<<"\t\t"<<(double)iTime[j]<<"\t\t"<<iCompArray[j]<<"\t"<<iMoveArray[j]<<endl ;

    }
    cout<<str1<<endl;
    cout<<"Part b - Time analysis of Hybrid Sort"<<endl;
    cout<<str2<<endl;

    for(int j = 0; j < 10; ++j){
        if(j <= 3)
            cout<<sizeArray[j]<<"\t\t"<<(double)hTime[j]<<"\t\t"<<hCompArray[j]<<"\t\t"<<hMoveArray[j]<<endl ;
        else
            cout<<sizeArray[j]<<"\t\t"<<(double)hTime[j]<<"\t\t"<<hCompArray[j]<<"\t\t"<<hMoveArray[j]<<endl ;
    }
    cout<<str1<<endl;

}





