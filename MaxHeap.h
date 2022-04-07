/*
Assignment: 1 - Priority Queue of Processes

Name: Tyler Desharnais, James Donaldson
Date: 14 Feb 2022

Header filer for the Max heap class to control
establishes the vector for the PCB and also access to all of the functions.

*/
#pragma once
#include "PCB.h"
#include <vector>
#include <iostream>
#pragma once

class MaxHeap {
	friend class PCB;
	friend class ReadyQueue;
	
public:
	int capacity; //For display optional 
	int size;  //Current size of Heap
	int* heap; //pointer for heap array
	std::vector<PCB*> pcbHeap;
	std::vector<Task*> taskHeap;
	MaxHeap();
	MaxHeap(int size);
	//functions located in the class function
    int getSize() { return size; }
    int getCapacity() { return capacity; }
    bool isEmpty() { if (size <= 0) { return true; }return false; }
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    //Min-Heap Main functions

    void buildHeap(); //build OG heap
    void heapify(int i); //heapify and bubble up + array of pcbHeap
    PCB* peek_min(); //returns minimum element from heap
    void pop_top();

    //Aux functions for the heap
    void swap_PCB(PCB* a, PCB* b);
    void swap_Task(Task* a, Task* b);
    void swap(int& a, int& b);

    void printHeapLevels(); //print heap levels
    void printHeap(); //basic print
    int get_SIZE() { return size; };

    //Insert function
    void insert_PCB(PCB& new_PCB);
    void insert_Task(Task& task);

    void debugHelper(int left, int right, int cur_Largest);
};
