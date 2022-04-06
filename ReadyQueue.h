#include "MaxHeap.h"
#pragma once
#ifndef READYQUEUE_H
#define READYQUEUE_H
class ReadyQueue{

    public:
        ReadyQueue(){
           
        };

        void addPCB(PCB &ref_PCB){heap.insert_PCB(ref_PCB);};
        void removePCB(){heap.pop_top();};
        int size(){return heap.get_SIZE();};
        bool isEmpty(){return heap.isEmpty();};

        //Display the IDs and priorities of processes in the queue
        void display();


    private:
        MaxHeap heap;
        


};
#endif