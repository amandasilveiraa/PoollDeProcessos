#pragma once
#include "Process.h"
#include "Fila.h"
#include <string>

class PrintingProcess : public Process {
private:
    Fila* fila;

public:
    PrintingProcess(Fila* f);
    void execute() override;
    std::string getType() override;
    std::string toString() override;
};
