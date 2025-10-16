#include "console_logger.h"
#include <iostream>

void ConsoleLogger::info(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}
void ConsoleLogger::warn(const std::string& message) {
    std::cout << "[WARN] " << message << std::endl;
}
void ConsoleLogger::error(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}
