#pragma once
#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(string expressao) {
    expr = expressao;
    istringstream ss(expr);
    ss >> op1 >> oper >> op2;
}

void ComputingProcess::execute() {
    float resultado;
    switch (oper) {
        case '+': resultado = op1 + op2; break;
        case '-': resultado = op1 - op2; break;
        case '*': resultado = op1 * op2; break;
        case '/': resultado = op2 != 0 ? op1 / op2 : 0; break;
        default: cout << "Operador invalido" << endl; return;
    }
    cout << "PID " << pid << ": Resultado da expressao " << expr << " = " << resultado << endl;
}

string ComputingProcess::getType() { 
    return "ComputingProcess";
}

string ComputingProcess::toString() { 
    return expr;
}

