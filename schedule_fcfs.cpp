#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

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
    
    node *head;
    node *last;
    

    if(head == NULL){
        head = new node();
        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;
        head->next = NULL;

        last = head;
    }
    

	// TODO: add your implementation here
	
}

/**
 *  * Run the FCFS scheduler
 *   */
void schedule() 
{
	// TODO: add your implementation here
}
