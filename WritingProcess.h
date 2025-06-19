#pragma once
#include <fstream>
#include <ostream>
#include "Process.h"
#include <ComputingProcess.h>

class WritingProcess : public Process{
    private:
    ComputingProcess* comp;

    public:
    WritingProcess(ComputingProcess* cp);
    void execute() override;
    std::string getType() override;
    std::string toString() override;
};
