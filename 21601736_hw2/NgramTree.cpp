#include "NgramTree.h"
#include <string>
#include "iostream"
#include "fstream"

#include "math.h"
using namespace std;
/**
* Title: Binary Search Trees
* Author: Muhammed Naci Dalk›ran
* ID: 21601736
* Section: 1
* Assignment: 2
* Description: This is cpp file of NgramFile and implementation of Binary Search Tree
*/
NgramTree::NgramTree():root(NULL)
{

}
NgramTree::NgramTree(TreeNode* nodePtr):root(NULL)
{

}
NgramTree::NgramTree(const string& rootItem )
{
        root = new TreeNode(rootItem,NULL,NULL);
}
NgramTree::~NgramTree()
{
    //dtor
}

void NgramTree:: addNgram(std::string ngram){
    insertItem(root,ngram);
}
void NgramTree::insertItem(TreeNode*& treePtr, const string& item){

    if(treePtr==NULL){
        treePtr=new TreeNode(item,NULL,NULL);
    }
    else if(item < treePtr->item)
        insertItem(treePtr->leftChildPtr, item);
    else if( item > treePtr->item)
        insertItem(treePtr->rightChildPtr, item);
    else
        treePtr->counter++;

}
void NgramTree:: generateTree(std::string fileName, int n){
    string line;
    ifstream file(fileName);
        while(!file.eof()){
        getline( file , line, '\n' ) ;
            while(line.size() >= n) {
                if(line.find(' ') < n){
                    line = line.substr(1);
                    continue;
                }
                else {
                    insertItem(root,line.substr(0,n) );
                    line = line.substr(1);
                }

            }
        }
	

	file.close();
}
int NgramTree:: getTotalNgramCount (){
    int sum = helperGetTotalNgramCount(root);
    return sum;

}
void NgramTree::printNgramFrequencies (){
    helperPrintNgramFrequencies(root);
}
void NgramTree::helperPrintNgramFrequencies (TreeNode* root){
    if(root != NULL){
        helperPrintNgramFrequencies(root->leftChildPtr);
        cout<< root->item<< "   appears "<<root->counter<<" time (s)"<<endl;
        helperPrintNgramFrequencies(root->rightChildPtr);
    }

}
bool NgramTree::isComplete (){
        int heightx = height(root);

    return helperIsComplete(root, 0,heightx);
}
bool NgramTree::helperIsComplete(TreeNode* root, int pass, int heightx){
    if (root == NULL)
        return (true);


    if (pass >= heightx)
        return (false);
    bool leftB = helperIsComplete(root->leftChildPtr, 2*pass + 1, heightx);
    bool rightB = helperIsComplete(root->rightChildPtr, 2*pass + 2, heightx);


    return leftB && rightB;

}
bool NgramTree::isFull(){
   int sum = helperIsFull( root);
   int heightTree = height(root);
   int check = pow(heightTree,2) - 1;
   return sum == check;

}
int NgramTree:: helperIsFull(TreeNode* root){
    if(root != NULL){
        return 1 + helperIsFull(root->leftChildPtr) + helperIsFull(root->rightChildPtr);
    }
    else
        return 0;
}

int NgramTree::height(TreeNode* root){
    if (root == NULL)
        return 0;
    else
    {
        int heightL = height(root->leftChildPtr);
        int heightR = height(root->rightChildPtr);

        if ( heightL > heightR )
            return(heightL + 1);
        else
            return(heightR + 1);
    }
}

int NgramTree::helperGetTotalNgramCount(TreeNode* root){
    if(root == NULL)
        return 0;
    else{
        return 1  + helperGetTotalNgramCount(root->leftChildPtr) + helperGetTotalNgramCount(root->rightChildPtr);
    }

}





