#pragma once

#include <string>

class ConsoleLogger {
    public:
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
};
