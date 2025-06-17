#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(string expressao) {
    expressao = expressao;
    istringstream ss(expressao);
    ss >> op1 >> operacao >> op2;
}

void ComputingProcess::execute() {
    float resultado;
    switch (operacao) {
        case '+': resultado = op1 + op2; break;
        case '-': resultado = op1 - op2; break;
        case '*': resultado = op1 * op2; break;
        case '/': resultado = op2 != 0 ? op1 / op2 : 0; break;
        default: cout << "Operador invalido" << endl; return;
    }
    cout << "PID " << pid << ": Resultado da expressao " << expressao << " = " << resultado << endl;
}

string ComputingProcess::getType() { 
    return "ComputingProcess";
}

string ComputingProcess::toString() { 
    return expressao;
}
