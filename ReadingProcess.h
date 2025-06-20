#pragma once

#include "Process.h"
class Fila;

class ReadingProcess : public Process {
private:
    Fila* fila;
public:
    ReadingProcess(Fila* f);
    void execute() override;
    string getType() override;
    string toString() override;
};