#include "Sistema.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"

void Sistema::iniciar() {
    int opcao;
    do {
        mostrarMenu();
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: criarProcesso(); break;
            case 2: executarProximo(); break;
            case 3: executarPorPid(); break;
            case 4: salvarFila(); break;
            case 5: carregarFila(); break;
            case 6: std::cout << "Encerrando o sistema..." << std::endl; break;
            default: std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 6);
}

void Sistema::mostrarMenu() {
    std::cout << "\n===== MENU =====" << std::endl;
    std::cout << "1 - Criar processo" << std::endl;
    std::cout << "2 - Executar próximo processo" << std::endl;
    std::cout << "3 - Executar processo por PID" << std::endl;
    std::cout << "4 - Salvar fila em arquivo" << std::endl;
    std::cout << "5 - Carregar fila do arquivo" << std::endl;
    std::cout << "6 - Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
}

void Sistema::criarProcesso() {
    std::cout << "\nTipos de processo:" << std::endl;
    std::cout << "1 - ComputingProcess (cálculo)" << std::endl;
    std::cout << "2 - WritingProcess (gravar expressão)" << std::endl;
    std::cout << "3 - ReadingProcess (ler arquivo)" << std::endl;
    std::cout << "4 - PrintingProcess (imprimir fila)" << std::endl;
    std::cout << "Digite o tipo: ";

    int tipo;
    while (!(std::cin >> tipo) || tipo < 1 || tipo > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Tipo inválido! Digite novamente (1-4): ";
    }
    std::cin.ignore();

    switch (tipo) {
        case 1: {
            std::string expressao;
            std::cout << "Digite a expressão (ex: 3 + 5): ";
            std::getline(std::cin, expressao);
            fila.inserirPush(new ComputingProcess(expressao));
            break;
        }
        case 2: {
            std::string expressao;
            std::cout << "Digite a expressão para gravar: ";
            std::getline(std::cin, expressao);
            fila.inserirPush(new WritingProcess(expressao));
            break;
        }
        case 3:
            fila.inserirPush(new ReadingProcess(&fila));
            break;
        case 4:
            fila.inserirPush(new PrintingProcess(&fila));
            break;
    }
}

void Sistema::executarProximo() {
    if (fila.ehVazio()) {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }
    fila.executeProximo();
}

void Sistema::executarPorPid() {
    if (fila.ehVazio()) {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }
    std::cout << "Digite o PID: ";
    int pid;
    while (!(std::cin >> pid)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "PID inválido! Digite novamente: ";
    }
    fila.executePorPid(pid);
}

void Sistema::salvarFila() {
    fila.salvar();
    std::cout << "Fila salva em 'fila.txt'." << std::endl;
}

void Sistema::carregarFila() {
    fila.carregar();
    std::cout << "Fila carregada de 'fila.txt'." << std::endl;
}