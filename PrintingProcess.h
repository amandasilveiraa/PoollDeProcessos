#pragma once
#include "Process.h"
class Fila;

class PrintingProcess : public Process {
private:
    Fila* fila;
public:
    PrintingProcess(Fila* f);
    void execute() override;
    string getType() override;
    string toString() override;
};