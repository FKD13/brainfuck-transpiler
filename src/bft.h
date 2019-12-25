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

class Statement {
public:
    Statement() = default;
    virtual ~Statement() = default;
    virtual std::string getCode();
};

class Incc : public Statement {
public:
    Incc() = default;
    ~Incc() override = default;
    std::string getCode() override;
};

class Decc : public Statement {
public:
    Decc() = default;
    ~Decc() override = default;
    std::string getCode() override;
};

class Prnt : public Statement {
public:
    Prnt() = default;
    ~Prnt() override = default;
    std::string getCode() override;

};

class Getc : public Statement {
public:
    Getc() = default;
    ~Getc() override = default;
    std::string getCode() override;
};

class Brac : public Statement {
public:
    Brac(bool open);
    ~Brac() override = default;
    std::string getCode() override;

private:
    bool open;
};

class Shif : public Statement {
public:
    Shif(bool left);
    ~Shif() override = default;
    std::string getCode() override;
private:
    bool left;
};

class Parser {
private:
    std::map<char, std::function<Statement *()>> actions;
public:
    Parser();
    ~Parser() = default;
    Statement *parseStatement(char i);
};

#endif //BF_TRANSPILER_PARSER_H