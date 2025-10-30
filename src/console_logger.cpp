#include "console_logger.h"
#include <iostream>
#include "logger.h"

ConsoleLogger::ConsoleLogger(LogConfig cfg) :ILogger(cfg) {
    
}

ConsoleLogger::~ConsoleLogger() {

}

void ConsoleLogger::setLogLevel(LogLevel level) {
    currentLogLevel = level;
}

void ConsoleLogger::info(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}
void ConsoleLogger::warn(const std::string& message) {
    std::cout << "[WARN] " << message << std::endl;
}
void ConsoleLogger::error(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}
