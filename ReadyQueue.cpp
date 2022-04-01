#include <iostream>
#include "MaxHeap.cpp"
#include <iomanip>

using namespace std;

class ReadyQueue{

    public:
        ReadyQueue(){
           
        };

        void addPCB(PCB &ref_PCB){heap.insert_PCB(ref_PCB);};
        void removePCB(){heap.pop_top();};
        int size(){return heap.get_SIZE();};
        bool isEmpty(){heap.isEmpty();};

        //Display the IDs and priorities of processes in the queue
        void display();


    private:
        MaxHeap heap;
        


};
//Displays results of the Queue 
void ReadyQueue::display(){
    int colWidth = 20; 
    int row = 40;
    string Names[4] = {"# Process", "PID", "PRIORITY", "STATE"};
    int counter =0;
    for(auto i : heap.pcbHeap){
        while(counter < heap.size){
            PCB* tmp = i;
            cout << tmp << endl;
            counter++;
        }
    }
    
    //Head
   // for(int i =0; i < )
   /*
   for(int i = 0; i <= 3; i++){
       if(i == 2 || i == 1 ){
           cout << "-" <<setfill('-') << setw(colWidth+Names[i].length()-i) << '+';
       }
       else{
           cout << "-" <<setfill('-') << setw(colWidth+Names[i].length()) << '+';
       }     
   }
   cout << endl;
   cout << "|";
   for(int i = 0; i <= 3; i++){
       cout << Names[i] << setfill(' ') << setw(colWidth) << "|";
   }
   cout <<"\n" <<endl;

   for(int i = 0; i < heap.getSize(); i++){
       int j =0;
       if(i >3){j = 0;};
       cout << i << setfill(' ') <<setw(colWidth+Names[j].length()) << "|" << heap.pcbHeap.at(i)->get_PID()<< setfill(' ') << setw(colWidth) << "|" << heap.pcbHeap.at(i)->get_PRIORITY()<< setfill(' ')  << setw(colWidth) << "|" << heap.pcbHeap.at(i)->state_HELPER()<< setfill(' ')  << setw(colWidth) << "|" << endl;
   }
   */

   
  

    //cout << setfill('-') << setw((3*colWidth)-1) << "-" << endl;
    //cout << setw(50) << "ReadyQueue  Contents" << setw(50) << endl;
   // cout << setw(120) <<setfill('-') << endl;
    
}