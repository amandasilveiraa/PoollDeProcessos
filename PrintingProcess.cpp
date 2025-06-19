#include "PrintingProcess.h"
#include <iostream>

PrintingProcess::PrintingProcess(std::list<Process*>& lista) : processos(lista) {}

void PrintingProcess::execute() {
    cout << "PID " << pid << ": Fila de processos:\n";
    
    if (processos.empty()) {
        std::cout << "A fila de processos está vazia.\n";
        return;
    }
    for (auto* processo : processos) {
        std::cout << "PID: " << processo->getPid() << " "
                  << "Tipo: " << processo->getType() << " "
                  << processo->toString() << std::endl;
    }
}

string PrintingProcess::getType() {
    return "PrintingProcess";
}

string PrintingProcess::toString() {
    return "Impressao da fila";
}
