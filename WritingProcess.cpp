#include "WritingProcess.h"
#include "ComputingProcess.h"
#include <iostream>
#include <fstream>

WritingProcess::WritingProcess(ComputingProcess* cp) : comp(cp) {}

WritingProcess::WritingProcess(std::string expressao) {
    comp = new ComputingProcess(expressao);
}

WritingProcess::~WritingProcess() {
    delete comp;
}

void WritingProcess::execute() {
    std::ofstream file("Computation.txt", std::ios::app); // modo append
    if (file.is_open()) {
        file << comp->toString() << "\n";
        std::cout << "PID " << pid << ": Expressao " << comp->toString() << " gravada com sucesso\n";
        file.close();
    } else {
        std::cout << "Erro ao abrir arquivo para gravação.\n";
    }
}

std::string WritingProcess::getType() {
    return "WritingProcess";
}

std::string WritingProcess::toString() {
    return "Salvar expressão: " + comp->toString();
}
