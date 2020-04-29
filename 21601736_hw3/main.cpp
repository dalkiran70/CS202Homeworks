#include "PriorityQueue.h"
#include "fstream"
#include "string"
#include <cstring>
#include "iostream"
#include <stdlib.h>
#include <sstream>
#include "heap.h"
#include "ObjectCom.h"
#include "ObjectComs.h"
#include "ObjectReq.h"
#include "PriorityQueue.h"
using namespace std;
/**
*Title : Heaps & AVL Trees
*Author: Muhammed Naci Dalkýran
*ID: 21601736
*Section: 01
*Assignment: 3
*Description: Main
*/

void creating( string fileName, ObjectReq**&requests, int& reqNum ){

	ifstream file(fileName);
	string line;
	getline(file, line);
	reqNum= atoi( line.c_str() );
	int count = 0;
	requests = new ObjectReq*[reqNum];
    string id;
    string priority;
    string start;
    string time;
    int ida;
    int prioritya;
    int starta;
    int timea;
	while (getline(file, line)) {
		 ObjectReq *temp = new ObjectReq();

         id = line.substr(0,line.find(' '));
         line = line.substr(line.find(' ') + 1);

         priority  = line.substr(0,line.find(' '));
         line = line.substr(line.find(' ') + 1);

         start  = line.substr(0,line.find(' '));
         line = line.substr(line.find(' ') + 1);

         time =line;

         char * cstrid = new char [id.length() + 1];
        strcpy (cstrid, id.c_str());

        char * cstrpri = new char [priority.length()+1];
        strcpy (cstrpri, priority.c_str());

        char * cstrstar = new char [start.length()+1];
        strcpy (cstrstar, start.c_str());

        char * cstrtime = new char [time.length()+1];
        strcpy (cstrtime, time.c_str());

         ida = atoi(cstrid);
         prioritya = atoi(cstrpri);
         starta = atoi(cstrstar);
         timea = atoi(cstrtime);

		 temp->setId( ida );
		 temp->setPri( prioritya );
		 temp->setStart( starta );
         temp->setTime( timea );
		 requests[count++] = temp;
		}
	file.close();

    }

int main(int argc, char *argv[]) {
    int averageTime =0;
    PriorityQueue pq;
    int MaximumAverage = atoi(argv[2]);
    int numberReq = 0;
    ObjectReq** requests;
	creating( argv[1], requests, numberReq );
	//int waiting = 0;
	//pq.display();
    string display;
    double average = MaximumAverage + 1;

    int compCount = 1;
    while(average > MaximumAverage){ // calculate how many computer must be used
        ObjectComs computers(compCount);
        display = "Minimum number of computers required: " + to_string(compCount)
        + "\nSimulation with " + to_string(compCount) + " computers:\n";
        int reqCount = 0;
        int time = 0;
        // cout<<"xx"<<endl;
        bool check2 = !pq.pqIsEmpty();
        while( (reqCount < numberReq) || (!computers.AvAllOfthem() || check2 ) ) {
            while(   reqCount < numberReq  && (requests[reqCount])->getStart() == time ){
                pq.pqInsert(requests[reqCount]);
                reqCount++;
               // cout<<"xx"<<endl;
                check2 = !pq.pqIsEmpty();
            }
            	//pq.display();

            bool chek1 = !computers.busyAllOfthem();
            while( chek1 &&   check2   ){
                ObjectReq *prior = NULL;
                pq.pqDelete( prior);
                // cout<<"xx"<<endl;
                if ( prior != NULL ){
                    computers.progress(prior, time, display);
                }
                check2 = !pq.pqIsEmpty();
                chek1 = !computers.busyAllOfthem();
            }
            computers.update();
            ++time;
        }
        //pq.display();

        average = (double)computers.getTotalWait() /  numberReq;
        //cout<<average<<end;
        //cout<<compCount<<endl;
        if(average > MaximumAverage ){ // if average is bigger than increase computer count other wise display it
            compCount++;
        }
                //cout<<compCount<<endl;

        else{
                cout << display<< endl;
            cout << "Average waiting time: " << average << " ms. " << endl; // display average waiting time

        }
    }
    //pq.display();
    return 0;
}




