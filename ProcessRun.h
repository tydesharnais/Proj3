#ifndef PROCESSRUN_H
#define PROCESSRUN_H

#include <iostream>
#include <string>

class ProcessRun{


    public:

        //Enums for State of PCB
        enum STATE{
                NEW,
                READY,
                RUNNING,
                WAITING,
                TERMINATED
        };

        std::string P_Name; //Process name
        STATE current_State; //current state
        
        std::string PID; //Process ID
        int priority; //Process Priority

        //Times 
        int CPU_Burst; //CPU burst time
        
        int start_Time;
        int end_Time;
        int turn_Time;
        int wait_Time;
        int response_Time;

        //Constructors
        ProcessRun(std::string PID, int priority, int CPU_Burst);
        ProcessRun(std::string PID, int CPU_Burst);

        
        std::string get_PID();
        int get_Burst();
        int get_Priority();
        void set_STATE(STATE nS);

};

#endif