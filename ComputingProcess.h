#pragma once
#include "Process.h"
#include <sstream>
#include <iostream>

class ComputingProcess : public Process {
    public:
        ComputingProcess(string expressao);
        void execute() override;
        string getType() override;
        string toString() override;
    private:
        string expressao;
        float op1, op2;
        char operacao;
};