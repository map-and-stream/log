#pragma once

#include <string>
#include "logger.h"

class ConsoleLogger : public ILogger {
    public:
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
};
