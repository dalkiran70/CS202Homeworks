
/**
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Naci DalkÝran
* ID: 21601736
* Section: 1
* Assignment: 1
* Description: This are sorting algorithms
*/
#ifndef _sorting_H
#define	_sorting_H
#include <iostream>
#include <time.h>
using namespace std;

void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);
void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void hybridSort(int *arr, int size, int &compCount, int &moveCount);
void printArray(int* arr, int size);
void performanceAnalysis();






#endif

