//
// Created by fklinck on 12/25/19.
//

#include <sstream>
#include "parser.h"
#include "logger.h"

/* Constructors */

Shif::Shif(bool left) : left(left) {}

Brac::Brac(bool open) : open(open) {}

Parser::Parser() {
    actions['+'] = [](){ return new Incc();};
    actions['-'] = [](){ return new Decc();};
    actions['.'] = [](){ return new Prnt();};
    actions[','] = [](){ return new Getc();};
    actions['<'] = [](){ return new Shif(true);};
    actions['>'] = [](){ return new Shif(false);};
    actions['['] = [](){ return new Brac(true);};
    actions[']'] = [](){ return new Brac(false);};
}

/* Code Generation */

std::string Statement::getCode() { return "";}

std::string Incc::getCode() { return "updateValue(1);";}

std::string Decc::getCode() { return "updateValue(-1);";}

std::string Prnt::getCode() { return "std::cout<<(char)memory[mptr];";}

std::string Getc::getCode() { return "getch();";}

std::string Shif::getCode() {
    if (left) {
        return "left();";
    }
    return "right();";
}

std::string Brac::getCode() {
    if (open) {
        return "while(memory[mptr]!=0){";
    }
    return "}";
}

/* Parsing */

Statement *Parser::parseStatement(char i) {
    if (actions.count(i) != 0) {
        return actions[i]();
    }
    std::stringstream ss;
    ss << "Invalid character '" << i << "'";
    logger.warn(ss.str());
    return new Statement();
}
