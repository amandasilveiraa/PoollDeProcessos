#pragma once
#include "process.h"
#include <sstream>
#include <iostream>

class ComputingProcess : public Process {
    public:
        ComputingProcess(string expressao);
        void execute() override;
        string getType() override;
        string toString() override;
    private:
        string expr;
        float op1, op2;
        char oper;
};
