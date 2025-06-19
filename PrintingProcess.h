#pragma once

#include "Process.h"
#include <list>

class PrintingProcess : public Process{
    private:
    std::list<Process*>& processos;

    public:
    PrintingProcess(std::list<Process*>& lista);
    void execute() override;
    std::string getType() override;
    std::string toString() override;
};

