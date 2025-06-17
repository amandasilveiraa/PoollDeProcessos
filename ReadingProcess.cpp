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
    string linha;
    while (getline(arquivo, linha)) {
        fila->inserirPush(new ComputingProcess(linha));
    }
    arquivo.close();
    ofstream clear("computation.txt", ios::trunc);
    clear.close();
    cout << "PID " << pid << ": Expressoes lidas e processadas" << endl;
}

string ReadingProcess::getType() { return "ReadingProcess"; }
string ReadingProcess::toString() { return "Leitura de arquivo"; }