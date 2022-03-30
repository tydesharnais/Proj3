#include "ProcessRun.h"
#include <string>

ProcessRun::ProcessRun(std::string PID, int priority, int CPU_Burst){
    this->PID = PID;
    this->priority = priority;
    this->CPU_Burst = CPU_Burst;
}
std::string ProcessRun::get_PID(){
    return PID;
}

int ProcessRun::get_Priority(){
    return priority;
}

int ProcessRun::get_Burst(){
    return CPU_Burst;
}