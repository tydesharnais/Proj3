
#include <iostream>
#include "PCB.h"
using namespace std;


/*
std::ostream& operator<<(std::ostream& os, const PCB &s) {
    
    os << "PROCESS ID: " << s.PID << "\t PROIRTY: " << s.priority << "\t CURRENT_STATE: " << s.currentState << std::endl;
}*/

std::string PCB::state_HELPER(){
    string state_Handler;
    switch(currentState){
        case PCB::STATE::NEW:
            return "NEW";
            break;
        case PCB::STATE::READY:
            return "READY";
            break;
        case PCB::STATE::RUNNING:
            return "RUNNING";
            break;
        case PCB::STATE::WAITING:
            return "WAITING";
            break;
        case PCB::STATE::TERMINATED:
            return "TERMINATED";
            break;
    }
    return "WAITING";
}