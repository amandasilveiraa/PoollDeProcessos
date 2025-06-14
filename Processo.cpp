#pragma once
#include "Processo.h"

int global_pid = 1;

Process::Process() {
    pid = global_pid++;
}

int Process::getPid() {
    return pid;
}