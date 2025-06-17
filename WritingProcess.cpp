#include "WritingProcess.h"

WritingProcess::WritingProcess(string expressao) {
    expressao = expressao;
}

void WritingProcess::execute() {
    ofstream arquivo("computation.txt", ios::app);
    if (arquivo.is_open()) {
        arquivo << expressao << endl;
        arquivo.close();
        cout << "PID " << pid << ": Expressao gravada" << endl;
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

string WritingProcess::getType() { 
    return "WritingProcess"; 
}
string WritingProcess::toString() { 
    return expressao;
}
