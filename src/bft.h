#ifndef BF_TRANSPILER_H
#define BF_TRANSPILER_H

#include <map>
#include <list>
#include <string>
#include <functional>

const std::list<std::string> base_begin = {
    "#include <deque>",
    "#include <iostream>",
    "std::deque<char> mem;",
    "int mptr=0;",
    "void right(){mptr++;if(mptr>=mem.size()){mem.push_back(0);}}",
    "void left(){mptr--;if(mptr<0){mptr=0;mem.push_front(0);}}",
    "void getch(){mem[mptr]=getchar();if(mem[mptr]<0){std::cout<<\"[ABORT] EOF received\"<<std::endl;exit(1);}}",
    "int main(){mem.push_back(0);"
};

const std::list<std::string> base_end = {
        "}"
};

#endif //BF_TRANSPILER_H
