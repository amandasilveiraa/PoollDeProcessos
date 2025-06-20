#include "PrintingProcess.h"
#include <iostream>

PrintingProcess::PrintingProcess(Fila* f) : fila(f) {}

void PrintingProcess::execute() {
    std::cout << "PID " << pid << ": Fila de processos:\n";

    if (fila->ehVazio()) {
        std::cout << "A fila de processos está vazia." << std::endl;
        return;
    }

    fila->mostrarTudo();
}

std::string PrintingProcess::getType() {
    return "PrintingProcess";
}

std::string PrintingProcess::toString() {
    return "Impressao da fila";
}
