#pragma once
#include "Fila.h"
#include <iostream>
#include <limits>

class Sistema {
private:
    Fila fila;
    void mostrarMenu();
    void criarProcesso();
    void executarProximo();
    void executarPorPid();
    void salvarFila();
    void carregarFila();

public:
    void iniciar();
};