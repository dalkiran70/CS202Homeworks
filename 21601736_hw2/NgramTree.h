#ifndef NGRAMTREE_H
#define NGRAMTREE_H
#include <string>
#include "fstream"

#include "iostream"
/**
* Title: Binary Search Trees
* Author: Muhammed Naci Dalk›ran
* ID: 21601736
* Section: 1
* Assignment: 2
* Description: This is hader file of NgramTree
*/
using namespace std;
class TreeNode{
    private:
        TreeNode(){}
        TreeNode(const string& nodeItem, TreeNode* left = NULL,
                TreeNode* right= NULL)
        :item(nodeItem), leftChildPtr(left), rightChildPtr(right){}
        string item;
        int  counter = 1;
        TreeNode* leftChildPtr;
        TreeNode* rightChildPtr;
        friend class NgramTree;
    };

class NgramTree{
public:
    NgramTree ();
    NgramTree (TreeNode* root);
    NgramTree (const string& rootItem);
    ~NgramTree();
    void addNgram(std::string ngram);

    int getTotalNgramCount ();
    void printNgramFrequencies ();
    bool isComplete ();
    bool isFull ();
    void generateTree(std::string fileName, int n);
protected:
    void insertItem(TreeNode*& treePtr, const string& item);
    int helperGetTotalNgramCount (TreeNode* root);
    void helperPrintNgramFrequencies (TreeNode* root);
    bool helperIsComplete (TreeNode* root,int pass, int heightx);
    int helperIsFull(TreeNode* root);
    int height(TreeNode* root);


private:
    TreeNode* root;
};

#endif // NGRAMTREE_H
