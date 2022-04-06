#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include "task.h"
#include "cpu.h"
#include "schedulers.h"
#include "ReadyQueue.h"

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
    int final_Time = 0;
    int num_Tasks = taskQueue.size();
    int runTime = QUANTUM;
    

    int q = taskQueue.size();

    vector<Task> a;

    for (int i = 0; i < q; i++)
    {
        a.push_back(taskQueue.front());
        taskQueue.pop();
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (a.at(i).priority > a.at(j).priority)
            {
                task temp;
                temp = a.at(i);
                a.at(i) = a.at(j);
                a.at(j) = temp;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        taskQueue.push(a.at(i));
    }
    a.clear();

    while (!taskQueue.empty())
    {

        Task tempTask = taskQueue.front();

        if (taskQueue.size() > 1)
        {
            if (tempTask.burst < runTime)
            {
                runTime = tempTask.burst;
            }

            run(&tempTask, runTime);

            taskQueue.pop();
            tempTask.burst = tempTask.burst - runTime;
            final_Time = final_Time + runTime;

            if (tempTask.burst > 0)
            {

                taskQueue.push(tempTask);
            }
            else
            {

                turn_Time = turn_Time + final_Time;
            }
        }
        else
        {

            run(&tempTask, tempTask.burst);

            final_Time = final_Time + tempTask.burst;
            turn_Time = turn_Time + final_Time;

            taskQueue.pop();
        }

        /* if(!taskQueue.empty()){
             reponse_Time = reponse_Time + final_Time;
         } */
        if (tempTask.burst == 0)
        {

            wait_Time = turn_Time - final_Time;
            turn_Time = wait_Time + tempTask.burst;

            cout << tempTask.name << " turn-around time = " << turn_Time << ", waiting time = " << wait_Time << endl;
        }

        int b = taskQueue.size();
        for (int i = 0; i < b; i++)
        {
            a.push_back(taskQueue.front());
            taskQueue.pop();
        }

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (a.at(i).priority > a.at(j).priority)
                {
                    task temp;
                    temp = a.at(i);
                    a.at(i) = a.at(j);
                    a.at(j) = temp;
                }
            }
        }
            
        for (int i = 0; i < b; i++)
        {
            taskQueue.push(a.at(i));
        }
        a.clear();
    }
    cout << "Average turnaround time " << turn_Time / num_Tasks << ", Average waiting time " << wait_Time / num_Tasks << endl;
    // TODO: add your implementation here
}
