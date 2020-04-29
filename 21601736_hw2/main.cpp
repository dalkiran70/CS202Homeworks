#include "NgramTree.h"
#include "fstream"
#include "string"
#include "iostream"
using namespace std;
/**
* Title: Binary Search Trees
* Author: Muhammed Naci Dalkıran
* ID: 21601736
* Section: 1
* Assignment: 2
* Description: This is main part
*/
int main(int argc, char **argv){
    NgramTree tree;
    
    string fileName(argv[1]);

    int n = atoi(argv[2]);
    tree.generateTree(fileName , n);
    cout << "\n Total " << n << "-gram count:" << tree.getTotalNgramCount() << endl;
    tree.printNgramFrequencies();
    cout << n << "-gram tree is complete: "
    << (tree.isComplete() ? "Yes" : "No");

//Before insertion of new n-grams
    cout << "\n Total " << n << "-gram count:" << tree.getTotalNgramCount() << endl;
    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    cout << "\n Total " << n << "-gram count:"
        << tree.getTotalNgramCount() << endl;
    tree.printNgramFrequencies();

    cout << n << "-gram tree is complete: "
   << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: "
    << (tree.isFull() ? "Yes" : "No") << endl;
    return 0;
}

