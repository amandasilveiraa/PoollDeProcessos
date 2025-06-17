#pragma once
#include <string>
using namespace std;

extern int global_pid;

class Process {
protected:
    int pid;
public:
    Process();
    virtual void execute() = 0;
    int getPid();
    virtual string getType() = 0;
    virtual string toString() = 0;
};