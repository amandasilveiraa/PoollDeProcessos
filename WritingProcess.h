#pragma once
#include "Process.h"
#include "ComputingProcess.h"

class WritingProcess : public Process {
private:
    ComputingProcess* comp;

public:
    WritingProcess(ComputingProcess* cp);
    WritingProcess(std::string expressao); 
    ~WritingProcess(); 
    void execute() override;
    std::string getType() override;
    std::string toString() override;
};
