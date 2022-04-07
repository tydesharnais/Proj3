// length of a time quantum
#pragma once
#include "task.h"
extern int QUANTUM;

// run the specified task for the following time slice
void run(Task* task, int slice);
