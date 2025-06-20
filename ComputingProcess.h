#pragma once
#include "Process.h"
#include <sstream>
#include <iostream>

class ComputingProcess : public Process {
    public:
        ComputingProcess(std::string expressao);
        void execute() override;
        std::string getType() override;
        std::string toString() override;
    private:
        std::string expressao;
        float op1, op2;
        char operacao;
};