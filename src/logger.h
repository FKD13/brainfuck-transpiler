#ifndef BF_TRANSPILER_LOGGER_H
#define BF_TRANSPILER_LOGGER_H

#include <string>

namespace Color {
    static std::string RST = "\x1B[0m";
    static std::string RED = "\x1B[31m";
    static std::string GRN = "\x1B[32m";
    static std::string YEL = "\x1B[33m";
    static std::string BLU = "\x1B[34m";
    static std::string MAG = "\x1B[35m";
    static std::string CYN = "\x1B[36m";
    static std::string WHT = "\x1B[37m";
    static std::string BLD = "\x1B[1m";
    static std::string UND = "\x1B[4m";
}

class Logger {
public:
    Logger();
    ~Logger() = default;
    void info(const std::string &s);
    void warn(const std::string&);
    void error(const std::string&);
    void report();
private:
    unsigned long warnings;
    unsigned long errors;
};

#endif //BF_TRANSPILER_LOGGER_H
