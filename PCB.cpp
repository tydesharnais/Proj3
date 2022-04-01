
#include <iostream>

using namespace std;



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
        int set_PID(int num){PID = num;};
        int set_PRIORITY(int num){priority = num;};
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


std::ostream& operator<<(std::ostream& os, const PCB &s) {
    
    os << "PROCESS ID: " << s.PID << "\t PROIRTY: " << s.priority << "\t CURRENT_STATE: " << s.currentState << std::endl;
}

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
}