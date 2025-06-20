#include "Sistema.h"
#include "ComputingProcess.h"
#include "Fila.h"
#include "PrintingProcess.h"
#include "Process.h"
#include "ReadingProcess.h"
#include "WritingProcess.h"

int main() {
    system("chcp 65001"); //para corrigir problemas de acento no terminal
    Sistema sistema;
    sistema.iniciar();
    return 0;
}