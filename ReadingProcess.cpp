#include "ReadingProcess.h"
#include "ComputingProcess.h"
#include "Fila.h"
#include <fstream>
#include <iostream>
using namespace std;

ReadingProcess::ReadingProcess(Fila* f) {
    fila = f;
}

void ReadingProcess::execute() {
    ifstream arquivo("computation.txt");
    
    if (!arquivo.is_open()) {
        cout << "Arquivo computation.txt não encontrado. Nenhuma expressão para ler." << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        fila->inserirPush(new ComputingProcess(linha));
    }
    arquivo.close();

    // Limpa o arquivo
    ofstream clear("computation.txt", ios::trunc);
    clear.close();
    cout << "PID " << pid << ": Expressões lidas e processadas" << endl;
}

string ReadingProcess::getType() { return "ReadingProcess"; }
string ReadingProcess::toString() { return "Leitura de arquivo"; }