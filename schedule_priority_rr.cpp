
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

    prioirity();

    while (!taskQueue.empty()) {
        prioirity();
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

void prioirity() {

    int j = taskQueue.size();
    vector <Task> a;
    for (int i = 0; i < j; i++) {
        a.at(i) = taskQueue.front();
        taskQueue.pop();
    }
    int k = a.size();
    bool check = true;
    int stop = 0;
    while (check)
    {
        for (int i = 1; i < k; i++) {
            if (a.at(i--).priority > a.at(i).priority) {
                task temp;
                temp = a.at(i--);
                a.at(i--) = a.at(i);
                a.at(i) = temp;
                stop++;

            }
        }
        if (stop == 0) {
            check = false;
        }
        stop = 0;
    }

    for (int i = 0; i < k; i++) {
        taskQueue.push(a.at(i));
    }
}