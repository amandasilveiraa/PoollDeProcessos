#include "Fila.h"
#include "PrintingProcess.h"
#include "ReadingProcess.h"

Nodo::Nodo(Process* p) {
    dado = p;
    proximo = nullptr;
}

Fila::Fila() {
    inicio = nullptr;
    fim = nullptr;
}

Fila::~Fila() {
    while (inicio) {
        Nodo* temp = inicio;
        inicio = inicio->proximo;
        delete temp->dado;
        delete temp;
    }
}

void Fila::inserirPush(Process* p) {
    Nodo* novo = new Nodo(p);
    if (!fim) inicio = fim = novo;
    else {
        fim->proximo = novo;
        fim = novo;
    }
}

bool Fila::ehVazio() { return inicio == nullptr; }

void Fila::executeProximo() {
    if (ehVazio()) {
        cout << "Fila vazia!" << endl;
        return;
    }
    Process* p = inicio->dado;
    p->execute();
    Nodo* temp = inicio;
    inicio = inicio->proximo;
    if (!inicio) fim = nullptr;
    delete temp;
}

void Fila::executePorPid(int pid) {
    Nodo *anterior = nullptr, *atual = inicio;
    while (atual && atual->dado->getPid() != pid) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (!atual) {
        cout << "PID nao encontrado!" << endl;
        return;
    }
    atual->dado->execute();
    if (!anterior) inicio = atual->proximo;
    else anterior->proximo = atual->proximo;
    if (atual == fim) fim = anterior;
    delete atual;
}

void Fila::mostrarTudo() {
    if (ehVazio()) {
        cout << "Fila vazia!" << endl;
        return;
    }
    Nodo* atual = inicio;
    while (atual) {
        cout << "PID: " << atual->dado->getPid() 
             << " - Tipo: " << atual->dado->getType() 
             << " - Info: " << atual->dado->toString() << endl;
        atual = atual->proximo;
    }
}

void Fila::salvar() {
    ofstream arquivo("fila.txt");
    Nodo* atual = inicio;
    while (atual) {
        arquivo << atual->dado->getType() << ";" << atual->dado->toString() << endl;
        atual = atual->proximo;
    }
    arquivo.close();
}

void Fila::carregar() {
    ifstream arquivo("fila.txt");
    string linha;
    while (getline(arquivo, linha)) {
        string tipo, conteudo;
        stringstream ss(linha);
        getline(ss, tipo, ';');
        getline(ss, conteudo);

        if (tipo == "ComputingProcess")
            inserirPush(new ComputingProcess(conteudo));
        else if (tipo == "WritingProcess")
            inserirPush(new WritingProcess(conteudo));
        else if (tipo == "ReadingProcess")
            inserirPush(new ReadingProcess(this));
        else if (tipo == "PrintingProcess")
            inserirPush(new PrintingProcess(this));
    }
    arquivo.close();
}