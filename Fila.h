#pragma once
#include "Process.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include <fstream>
#include <sstream>

class Fila;

class Nodo {
public:
    Process* dado;
    Nodo* proximo;
    Nodo(Process* p);
};

class Fila {
private:
    Nodo* inicio;
    Nodo* fim;
public:
    Fila();
    ~Fila();
    void inserirPush(Process* p);
    bool ehVazio();
    void executeProximo();
    void executePorPid(int pid);
    void mostrarTudo();
    void salvar();
    void carregar();
};