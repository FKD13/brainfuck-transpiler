#ifndef BF_TRANSPILER_H
#define BF_TRANSPILER_H

#include <map>
#include <list>
#include <string>
#include <functional>

const std::list<std::string> base_begin = {
        "#include <inttypes.h>",
        "#include <stdio.h>",
        "#include <stdlib.h>",
        "uint8_t mem[65536] = { 0 };",
        "uint16_t mptr=0;",
        R"(void getch(){int c = getchar(); if(c<0){printf("[ABORT] EOF received\n");exit(1);}else{mem[mptr]=c;}})",
        "int main(){"
};

const std::list<std::string> base_end = {
        "}"
};

#endif //BF_TRANSPILER_H
