#include "ProcessRun.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main(int argc, char* argv[]){

    queue<ProcessRun> processes;

    cout << "Reading from " << argv[0] << " ..."<< endl;
    fstream myFile;
    myFile.open(argv[0],ios::in);
    if(myFile.is_open()){
        string str_PID, str_priority, str_CPU_BURST;
        int priority, CPU_BURST;
        string line;
        while(getline(myFile,line)){
            stringstream ss(line);
            getline(ss, str_PID, ',');
            getline(ss, str_priority, ',');
            getline(ss, str_CPU_BURST, ',');
            priority = stoi(str_priority);
            CPU_BURST = stoi(str_CPU_BURST);
            
            ProcessRun process(str_PID,priority,CPU_BURST);
            processes.push(process);
        }
    }


}