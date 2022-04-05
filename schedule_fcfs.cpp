#include <stdlib.h>
#include <stdio.h>
#include "task.h"
#include "CPU.cpp"
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
queue<Task> taskQueue; 

// add a new task to the list of tasks
 void add(char *name, int priority, int burst) 
{
    
    Task task;
    task.name = name;
   // task.tid = 999;
    task.priority = priority;
    task.burst = burst;
  //  std::cout << "Added " << name << task.name << " " << priority << " " << burst << std::endl;

    

    
    taskQueue.push(task);
	// TODO: add your implementation here
	
}

/**
 *  * Run the FCFS scheduler
 *   */
void schedule() 
{
    float turn_Time = 0;
    float wait_Time = 0;
    float reponse_Time = 0;
    int final_Time = 0;
    int num_Tasks = 0;
    Task tempTask;

    while(!taskQueue.empty()){

        num_Tasks = num_Tasks + 1;

        tempTask = taskQueue.front();
       

        run(&tempTask, tempTask.burst);

        final_Time = final_Time + tempTask.burst;
        turn_Time = turn_Time + final_Time;

        taskQueue.pop();

       /* if(!taskQueue.empty()){
            reponse_Time = reponse_Time + final_Time;            
        } */
        
        wait_Time = turn_Time - final_Time;
        turn_Time = wait_Time + tempTask.burst;

        cout << tempTask.name << " turn-around time = " << turn_Time << ", waiting time = " << wait_Time << endl;
        
    }
    cout << "Average turnaround time " << turn_Time/num_Tasks << ", Average waiting time " << wait_Time/num_Tasks << endl; 
	// TODO: add your implementation here
}
