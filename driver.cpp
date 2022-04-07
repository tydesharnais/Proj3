/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "schedule_fcfs.cpp"

#define SIZE    100

int main(int argc, char *argv[]){
    
    std::cout << "CS 433 Programming assignment 3" << std::endl;
    std::cout << "Author: xxxxxx and xxxxxxx" << std::endl;
    std::cout << "Date: xx/xx/20xx" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : **** " << std::endl;
    std::cout << "=================================" << std::endl;

    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    int tid;

    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        name = strtok(task,",");
        priority = atoi(strtok(NULL, ","));
        burst = atoi(strtok(NULL, ","));
        tid =  name[1]-'0';
      //  temp = strdup(task);
      //  string tempSplit[] = strtok(temp,",");
        
        // add the task to the scheduler's list of tasks
        
        add(name,priority,burst, tid);
        

      //  free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    return 0;
}
