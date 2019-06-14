#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>


enum class Severity {
    DEBUG, INFO, WARNING, ERROR, FATAL
};

class Logger {
private:
    Logger() {
        file.open("logs/log");
        log(Severity::DEBUG, "Logging job started.");
    }
    std::string getSeverityString(Severity severity);
public:
    void log(Severity severity, std::string message);
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    ~Logger();
private:
    std::ofstream file;
};


#endif