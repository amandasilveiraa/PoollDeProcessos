#pragma once
#include "Process.h"
#include <fstream>
#include <iostream>

class WritingProcess : public Process {
private:
    string expressao;
public:
    WritingProcess(string expressao);
    void execute() override;
    string getType() override;
    string toString() override;
};