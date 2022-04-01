#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include <queue>
#include "ReadyQueue.cpp"


/*
struct node {
    Task *task;
    struct node *next;
};

typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
*/

// add a new task to the list of tasks
 void add(char *name, int priority, int burst) 
{
    
    Task task;
    task.name = name;
    task.tid = 999;
    task.priority = priority;
    task.burst = burst;
    


    

	// TODO: add your implementation here
	
}

/**
 *  * Run the FCFS scheduler
 *   */
void schedule() 
{
	// TODO: add your implementation here
}
