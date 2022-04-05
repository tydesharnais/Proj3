#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include <queue>
#include "ReadyQueue.cpp"


queue<Task> taskQueue;

// add a new task to the list of tasks
void add(char* name, int priority, int burst)
{

    Task task;
    task.name = name;
    task.tid = 999;
    task.priority = priority;
    task.burst = burst;

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
    int runTime = 0;

    while (!taskQueue.empty()) {

        Task tempTask = taskQueue.front();
        num_Tasks = num_Tasks + 1;
        

        if (taskQueue.size() > 1) {
            
            if (tempTask.burst < QUANTUM) {
                runTime = tempTask.burst;
            }
            else runTime = QUANTUM;

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

            cout << tempTask.name << " turn-around time = " << turn_Time << ", waiting time = " << wait_Time << endl;
        }

    }
    cout << "Average turnaround time " << turn_Time / num_Tasks << ", Average waiting time " << wait_Time / num_Tasks << endl;
    // TODO: add your implementation here
}
