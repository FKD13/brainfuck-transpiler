#ifndef BF_TRANSPILER_PARSER_H
#define BF_TRANSPILER_PARSER_H

#include <map>
#include <list>
#include <string>
#include <functional>

const std::list<std::string> base = {
    "#include <deque>",
    "#include <iostream>",
    "static std::deque<int> memory;",
    "long int mptr=0;",
    "void updateValue(int x){memory[mptr]+=x;if(memory[mptr]<0){std::cerr<<\"[ABORT] Memory value lower than one\"<<std::endl;exit(2);}}",
    "void right(){mptr++;if(mptr>=(long signed int)memory.size()){memory.push_back(0);}}",
    "void left(){mptr--;if(mptr<0){mptr=0;memory.push_front(0);}}",
    "void getch(){memory[mptr]=getchar();if(memory[mptr]<0){exit(1);}}"
};

#endif //BF_TRANSPILER_PARSER_H