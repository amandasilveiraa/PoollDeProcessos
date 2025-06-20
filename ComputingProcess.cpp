#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(string expressao) : expressao(expressao) {
    istringstream ss(expressao);
    ss >> op1 >> operacao >> op2;
}

void ComputingProcess::execute() {
    float resultado;
    try {
        switch (operacao) {
            case '+': resultado = op1 + op2; break;
            case '-': resultado = op1 - op2; break;
            case '*': resultado = op1 * op2; break;
            case '/': 
                if (op2 == 0) throw runtime_error("Divisao por zero");
                resultado = op1 / op2; 
                break;
            default: throw runtime_error("Operador invalido");
        }
        cout << "PID " << pid << ": Resultado da expressao " << expressao << " = " << resultado << endl;
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

string ComputingProcess::getType() { 
    return "ComputingProcess";
}

string ComputingProcess::toString() { 
    return expressao;
}