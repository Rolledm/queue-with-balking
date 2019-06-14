#include "Logger.h"
#include <iostream>

std::string Logger::getSeverityString(Severity severity) {
    switch (severity)
    {
    case Severity::DEBUG:
        return "DEBUG";

    case Severity::INFO:
        return "INFO";

    case Severity::WARNING:
        return "WARNING";

    case Severity::ERROR:
        return "ERROR";

    case Severity::FATAL:
        return "FATAL";

    default:
        throw "Unknown severity.";
    }
}

Logger::~Logger() {
    if (file.is_open()) {
        log(Severity::DEBUG, "Stop of logging job.");
        file.close();
    }
}

void Logger::log(Severity severity, std::string message) {
    if (file.is_open()) {
        file << "[" << getSeverityString(severity) << "]: " << message << std::endl;
    } else {
        std::cout << "File is not open" << std::endl;
    }
}