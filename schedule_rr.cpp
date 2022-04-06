#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "task.h"
#include "CPU.cpp"
#include <queue>
#include "ReadyQueue.cpp"

using namespace std;

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
    int num_Tasks = taskQueue.size();
    int runTime = 0;
    int quantum = 10;
    while (!taskQueue.empty()) {

        Task tempTask = taskQueue.front();
        
        

        if (taskQueue.size() > 1) {
            
            if (tempTask.burst < quantum) {
                runTime = tempTask.burst;
            }
            else runTime = quantum;

            run(&tempTask, runTime);

            taskQueue.pop();
            tempTask.burst = tempTask.burst - runTime;
            final_Time = final_Time + runTime;

            if (tempTask.burst > 0) {
 
                taskQueue.push(tempTask);
            }
            else {
                
                turn_Time = turn_Time + final_Time;
            }
        }
        else {

            run(&tempTask, tempTask.burst);

            final_Time = final_Time + tempTask.burst;
            turn_Time = turn_Time + final_Time;

            taskQueue.pop();
        }

        /* if(!taskQueue.empty()){
             reponse_Time = reponse_Time + final_Time;
         } */

        if (tempTask.burst = 0) {

            wait_Time = turn_Time - final_Time;
            turn_Time = wait_Time + tempTask.burst;

            cout << tempTask.name << " turn-around time = " << turn_Time << ", waiting time = " << wait_Time << endl;
        }
       

    }
    cout << "Average turnaround time " << turn_Time / num_Tasks << ", Average waiting time " << wait_Time / num_Tasks << endl;
    // TODO: add your implementation here
}
