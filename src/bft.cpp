//
// Created by fklinck on 12/25/19.
//

#include <sstream>
#include <fstream>
#include <vector>
#include "parser.h"
#include "logger.h"
#include "bft.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        std::ifstream ifstream(argv[1]);
        std::ofstream ofstream("out.cpp");
        Parser parser;
        if (ifstream.good()) {
            std::vector<Statement*> statements;
            int i;
            /* parse the input file */
            logger.info("Parsing brainfuck");
            while((i=ifstream.get())!=-1) {
                statements.push_back(parser.parseStatement((char)i));
            }
            /* Generate cpp code */
            logger.info("Generating cpp");
            for (const std::string &s : base_begin) {
                ofstream << s << std::endl;
            }
            for (Statement *s : statements) {
                ofstream << s->getCode() << std::endl;
            }
            for (const std::string &s : base_end) {
                ofstream << s << std::endl;
            }
            logger.report();
            logger.info(Color::GRN + "Done");
        } else {
            logger.error("File does not exist");
            exit(EXIT_FAILURE);
        }
    } else {
        std::stringstream ss;
        ss << "Usage: " << argv[0] << " <file>";
        logger.error(ss.str());
        exit(EXIT_FAILURE);
    }
}