#include <iostream>
#include "logger.h"

Logger::Logger() : warnings(0), errors(0) {}

void Logger::info(const std::string &s) {
    std::cout << "[INFO] " << Color::BLD << s << Color::RST << std::endl;
}

void Logger::warn(const std::string &s) {
    warnings++;
    std::cout << "[WARN] " << Color::BLD << Color::YEL << s << Color::RST << std::endl;
}

void Logger::error(const std::string &s) {
    errors++;
    std::cout << "[ERROR] " << Color::BLD << Color::RED << s << Color::RST << std::endl;
}

void Logger::report() {
    if (errors > 0 || warnings > 0) {
        std::cout << "[REPORT] " << Color::BLD << Color::BLU << "Encoutered " << warnings ;
        if (warnings == 1) {
            std::cout << " warning and ";
        } else {
            std::cout << " warnings and ";
        }
        if (errors == 1) {
            std::cout << errors << " error" << Color::RST << std::endl;
        } else {
            std::cout << errors << " errors" << Color::RST << std::endl;
        }
    }
}