//
// Created by fklinck on 12/25/19.
//

#ifndef BF_TRANSPILER_PARSER_H
#define BF_TRANSPILER_PARSER_H

#include <string>
#include <map>
#include <functional>
#include "logger.h"

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
    explicit Brac(bool open);
    ~Brac() override = default;
    std::string getCode() override;

private:
    bool open;
};

class Shif : public Statement {
public:
    explicit Shif(bool left);
    ~Shif() override = default;
    std::string getCode() override;
private:
    bool left;
};

class Parser {
private:
    Logger *logger;
    std::map<char, std::function<Statement *()>> actions;
public:
    explicit Parser(Logger *logger);
    ~Parser() = default;
    Statement *parseStatement(char i);
};

#endif //BF_TRANSPILER_PARSER_H
