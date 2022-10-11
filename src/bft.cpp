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
    Logger logger;
    if (argc == 2) {
        std::ifstream ifstream(argv[1]);
        std::ofstream ofstream("out.cpp");
        Parser parser(&logger);
        if (ifstream.good()) {
            /* Output some definitions */
            logger.info("Adding definitions");
            for (const std::string &s: base_begin) {
                ofstream << s << std::endl;
            }
            /* parse the input file and generate cpp code */
            int i;
            logger.info("Parsing brainfuck and generating code");
            while ((i = ifstream.get()) != -1) {
                Statement *s = parser.parseStatement((char) i);
                ofstream << s->getCode() << std::endl;
            }
            /* Output the file ending */
            logger.info("Adding file end");
            for (const std::string &s: base_end) {
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
