#include <iostream>
#include <string>
#include "Fila.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
using namespace std;

int main() {
    Fila fila;
    int opcao;

    do {
        cout << "1 - Criar processo" << endl;
        cout << "2 - Executar proximo processo" << endl;
        cout << "3 - Executar processo por PID" << endl;
        cout << "4 - Salvar fila em arquivo" << endl;
        cout << "5 - Carregar fila do arquivo" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case 1: {
                cout << "Tipos de processo:" << endl;
                cout << "1 - ComputingProcess (calculo)" << endl;
                cout << "2 - WritingProcess (gravar expressao)" << endl;
                cout << "3 - ReadingProcess (ler e carregar expressoes do arquivo)" << endl;
                cout << "4 - PrintingProcess (mostrar fila atual)" << endl;
                cout << "Digite o tipo do processo: ";
                int tipo;
                cin >> tipo;
                cin.ignore();

                if (tipo == 1) {
                    string expressao;
                    cout << "Digite a expressao (ex: 3 + 5): ";
                    getline(cin, expressao);
                    fila.inserirPush(new ComputingProcess(expressao));
                } else if (tipo == 2) {
                    string expressao;
                    cout << "Digite a expressao para gravar: ";
                    getline(cin, expressao);
                    fila.inserirPush(new WritingProcess(expressao));
                } else if (tipo == 3) {
                    fila.inserirPush(new ReadingProcess(&fila));
                } else if (tipo == 4) {
                    fila.inserirPush(new PrintingProcess(&fila));
                } else {
                    cout << "Tipo invalido." << endl;
                }
                break;
            }
            case 2:
                fila.executeProximo();
                break;
            case 3: {
                int pid;
                cout << "Digite o PID do processo: ";
                cin >> pid;
                fila.executePorPid(pid);
                break;
            }
            case 4:
                fila.salvar();
                cout << "Fila salva com sucesso." << endl;
                break;
            case 5:
                fila.carregar();
                cout << "Fila carregada com sucesso." << endl;
                break;
            case 6:
                cout << "Encerrando o sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 6);

    return 0;
}