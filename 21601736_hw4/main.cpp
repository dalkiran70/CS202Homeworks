#include "OpenHashTable.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <string>
#include <fstream>
#include "ChainHashTable.h"
#include "FruitsAndVegatables.h"
#include "Bucket.h"

using namespace std;
/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Muhammed Naci Dalkýran
* ID: 21601736
* Section : 1
* Assignment : 4
* Description : main
*/


void analyze(OpenHashTable& h, ChainHashTable& c, double& o,double& chain,int &coll)
{
 string fileName("items.txt");
 ifstream fileO(fileName);
 string lineO;
 string randomName[100];
 int random = 0;
 int counter =0;
 string value;
 string name;
 string data;
 while(getline(fileO,lineO) )
 { data = lineO;
    value = data.substr(0,data.find_first_of("\t"));
    name = data.substr(data.find_first_of('\t')+1);

    if(random == 1 && counter < 100){
        randomName[counter] = name;

        random = 0;
        counter++;
    }
    else
        random++;

 }
 int compOpen = 0;
 int compChain = 0;
 chrono::time_point< chrono::system_clock > startTime;
 chrono::duration< double, milli > elapsedTime;

 startTime = chrono::system_clock::now();
 while(counter >= 0){
    h.searchTable(randomName[counter], compOpen);
    --counter;
 }
 elapsedTime = chrono::system_clock::now() - startTime;
 double OpenSearch= elapsedTime.count();

 counter = 99;
 startTime = chrono::system_clock::now();
 while(counter >= 0){
    c.searchTable(randomName[counter], compChain);
    --counter;
 }
 elapsedTime = chrono::system_clock::now() - startTime;
 double ChainSearch= elapsedTime.count();

 counter = 99;
 startTime = chrono::system_clock::now();
 while(counter >= 0){
    h.deletetable(randomName[counter]);
    --counter;
 }
 elapsedTime = chrono::system_clock::now() - startTime;
 double OpenDelete= elapsedTime.count();

 counter = 99;
 startTime = chrono::system_clock::now();
 while(counter >= 0){
    c.deletetable(randomName[counter]);
    --counter;
 }
 elapsedTime = chrono::system_clock::now() - startTime;
 double ChainDelete= elapsedTime.count();




   cout <<endl;
    cout << "-----------------------------------------------------"<<endl;
    cout << "Part a - Analysis of Open Addressing Hash Table"<<endl;
    cout << "Parameter";
    cout.width(35);
    cout << "Time Elapsed"<<endl;
    cout<<"Average Insertion Time";
    cout.width(20);
    cout<< o<<endl;
    cout<<"Average Retrieval Time";
    cout.width(20);
    cout<< OpenSearch<< endl;
    cout<<"Average Deletion Time";
    cout.width(20);
    cout<< OpenDelete<< endl;
    cout << "Number of comparisons in Retrieval = " << compOpen<<endl;
    cout<<"Number of collisions in Insertion = " <<coll<<endl;
    cout << "-----------------------------------------------------"<<endl;
    cout << "Part b - Analysis of Separate Chain Hash Table"<<endl;
    cout << "Parameter";
    cout.width(35);
    cout << "Time Elapsed"<<endl;
    cout<<"Average Insertion Time";
    cout.width(20);
    cout<< chain<<endl;
    cout<<"Average Retrieval Time";
    cout.width(20);
    cout<< ChainSearch<< endl;
    cout<<"Average Deletion Time";
    cout.width(20);
    cout<< ChainDelete<< endl;
    cout << "Number of comparisons in Retrieval = " << compChain<<endl;
    cout << "-----------------------------------------------------"<<endl;
}
int main(int argc, char *argv[]) {

        string fileName("items.txt");
        string line;
        string data;
        string linex;
        string datax;
        OpenHashTable h;
        ChainHashTable c;

        chrono::time_point< chrono::system_clock > startTime;
        chrono::duration< double, milli > elapsedTime;
        int collopen = 0;
        ifstream textFile(fileName);
        startTime = chrono::system_clock::now();
        while (getline(textFile, line)){
             data = line;
             string amount = data.substr(0,data.find_first_of("\t"));
             string name = data.substr(data.find_first_of('\t')+1);
             FruitsAndVegatables temp;
             temp.setName(name);
             temp.setValue(amount);
             h.insertFruitsAndVegatables(temp,collopen);
        }
        elapsedTime = chrono::system_clock::now() - startTime;
        double HashOpen = elapsedTime.count();
        int comp1 = 0;
        int comp2 = 0;
        int comp3 = 0;

        cout<<"OpenHashTable"<< endl;
        h.printTable();

        cout<<"***********************************"<< endl;
        cout<<"Favorite 3 fruits:"<< endl;
        h.searchTable("banana macho", comp1);
        h.searchTable("chile habanero",comp2);
        h.searchTable("cucumber persian",comp3);
        h.deletetable("beans black eye");
        h.deletetable("beans garbanzo");
        h.deletetable("broccoli");
        cout<<"***********************************"<< endl;
        cout<<"OpenHashTable"<< endl;
        h.printTable();



         ifstream textFiled(fileName);
          startTime = chrono::system_clock::now();
          while (getline(textFiled, linex)){
             datax = linex;
             string amount = datax.substr(0,datax.find_first_of("\t"));
             string name = datax.substr(datax.find_first_of('\t')+1);
             FruitsAndVegatables* tempptr = new FruitsAndVegatables();
             tempptr->setName(name);
             tempptr->setValue(amount);
             c.insertFruitsAndVegatables(tempptr);

        }
        elapsedTime = chrono::system_clock::now() - startTime;
        double HashChain= elapsedTime.count();

         comp1 = 0;
         comp2 = 0;
         comp3 = 0;
        cout<<"ChainHashTable"<< endl;
        c.printTable();
        cout<<"***********************************-"<< endl;
        c.searchTable("banana macho", comp1);
        c.searchTable("chile habanero",comp2);
        c.searchTable("cucumber persian",comp3);


        c.deletetable("beans black eye");
        c.deletetable("beans garbanzo");
        c.deletetable("broccoli");
        cout<<"***********************************"<< endl;
        cout<<"ChainHashTable"<< endl;
        c.printTable();

        analyze(h,c,HashOpen,HashChain,collopen);
}
