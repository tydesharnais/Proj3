/*
Assignment: 1 - Priority Queue of Processes

Name: Tyler Desharnais, James Donaldson
Date: 14 Feb 2022

Header filer for the PCB class to control 
enum state and functions for PCB data structure

*/
#include <string>
#pragma once

class PCB{
    friend class ReadyQueue;

     public:
        //CONSTRUCTORS//
        PCB(){
            this->currentState = NEW;
        }
        PCB(int priority){
            this->PID = priority;
            this->priority = priority;
            this->currentState = NEW;
        };

        //Overloaded Constructor id PID is given 

        PCB(int PID, int priority){
            this->PID = PID;
            this->priority = priority;
            this->currentState = NEW;
        };

        //Enums for State of PCB
        enum STATE{
                NEW,
                READY,
                RUNNING,
                WAITING,
                TERMINATED
            };

        //Inline functions for optimization and decreased function overhead
        
        int get_PID(){return PID;};
        void set_PID(int num){PID = num;};
        void set_PRIORITY(int num){priority = num;};
        STATE get_STATE(){return currentState;};
        int get_PRIORITY(){return priority;};
        void set_STATE(STATE nS){currentState = nS;};
        friend std::ostream& operator<<(std::ostream& os, const PCB &s);
        std::string state_HELPER();

    private:

        STATE currentState;
        int PID;   //Process ID - static 
        int priority; //Number from 1 to 50

};