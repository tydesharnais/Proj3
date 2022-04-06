#include <iostream>
#include <vector>
#include "PCB.h"
#include "task.h"
#include "MaxHeap.h"

using namespace std;

void MaxHeap::insert_Task(Task &task){
    size++;
    taskHeap.emplace_back(&task);
}

void MaxHeap::insert_PCB(PCB &new_PCB){
    size++;
    new_PCB.set_STATE(PCB::STATE::READY); //set new state to ready
    pcbHeap.emplace_back(&new_PCB); //inserts new PCB
    int count = size -1;

    while(count != 0 && pcbHeap.at(parent(count))->get_PRIORITY() < pcbHeap.at(count)->get_PRIORITY()){ 
      swap_PCB(pcbHeap.at(parent(count)),pcbHeap.at(count));
      count = parent(count);
    }
   // heapify(size -1);
}

/**
 * @brief MIN-HEAP FUNCTIONS
 * 
 */

void MaxHeap::buildHeap() 
{
 //from last non leaf 
	for (int i = size/2 -1; i >= 0; i--) { 
		heapify(i); 
	} 
} 

void MaxHeap::debugHelper(int left, int right, int cur_Largest){
    cout << "\n------DEBUG HELPER-------\n";
    cout << "Curr Size: " << size << endl;
    cout << "Curr Index Left: " << left << " and is: " << pcbHeap.at(left)->get_PRIORITY() << endl;
    cout << "Curr Index Right: " << right << " and is: " << pcbHeap.at(right)->get_PRIORITY() << endl;
    cout << "Curr Index largest: " << cur_Largest << " and is: " << pcbHeap.at(cur_Largest)->get_PRIORITY() << endl;
    
};

void MaxHeap::heapify(int i){  //heapify and bubble up
    
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
  //  debugHelper(left, right, largest);
    
    //Must find the largest element in the heap
    if(left < size && pcbHeap.at(left)->get_PRIORITY() > pcbHeap.at(i)->get_PRIORITY()){ //left is largest
        largest = left;
    }
    if(right < size && pcbHeap.at(right)->get_PRIORITY() > pcbHeap.at(largest)->get_PRIORITY()){ //right is largest 
        largest = right;
    }
    if(largest != i){ //largest was not the parent
        cout << "Swap Between " << pcbHeap.at(i)->get_PRIORITY() << " and " << pcbHeap.at(largest)->get_PRIORITY() <<endl;
        swap_PCB(pcbHeap.at(i), pcbHeap.at(largest));
       
        heapify(largest);
    }
};

void MaxHeap::pop_top(){
    if(isEmpty()==true){
        cout << "Queue is empty" << endl;
    }
    else if(size ==1){
        PCB* ref_PCB = pcbHeap.at(0);
        ref_PCB->set_STATE(PCB::STATE::RUNNING);
        pcbHeap.pop_back();
        size--;
    }
    else{
        swap_PCB(pcbHeap.at(0), pcbHeap.at(size - 1));
        PCB* ref_PCB = pcbHeap.at(size-1);
        ref_PCB->set_STATE(PCB::STATE::RUNNING);
        pcbHeap.pop_back();
        size--;
        heapify(0);
    }
}

PCB* MaxHeap::peek_min(){
    if(isEmpty()==true){
        cout << "Queue is empty!" << endl;
    }
    return pcbHeap.at(0);
}
        
//Aux functions for the heap

//C-style swap for heap elements 
void MaxHeap::swap_PCB(PCB *a, PCB *b){

    int tempPID = a->get_PID();
    int tempPriority = a->get_PRIORITY();

    a->set_PRIORITY(b->get_PRIORITY());
    a->set_PID(b->get_PID());
    b->set_PRIORITY(tempPriority);
    b->set_PID(tempPID);

}

void MaxHeap::swap_Task(Task *a, Task *b){
    int tmpPriority = a->priority;
    int tmpBurst = a->burst;
    char* tmpName = a->name;
  //  int tmpID = a->tid;

    a->name = b->name;
    a->priority = b->priority;
    a->burst = b->burst;
   // a->tid = b->tid;

    b->name = tmpName;
    b->priority = tmpPriority;
   // b->tid = tmpID;
    b->burst = tmpBurst;

}
void MaxHeap::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
};

void MaxHeap::printHeapLevels(){

    int power = 0;
    int value = 1;
    for(int i=0; i <size; i++){
        if(i == value){
            cout<<endl;
            power+=1;
            value+= (1<<power);
        }
        cout << "ID:" << pcbHeap.at(i)->get_PID() << "  ";
        cout << "Priority:" << pcbHeap.at(i)->get_PRIORITY() << "  ";
    }
    cout << endl;

}; 

//print heap

void MaxHeap::printHeap(){
    for(int i=0; i <size; i++){
        cout << &pcbHeap.at(i) << " ";
    }
    cout << endl;
}

