#pragma once

#include <iostream>
#include <string>

// --- Abstract Logger Interface ---
class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void info(const std::string& message) = 0;
    virtual void warn(const std::string& message) = 0;
    virtual void error(const std::string& message) = 0;
};



// --- Example Usage ---
// int main() {
//     ConsoleLogger logger;

//     logger.Info("Application started.");
//     logger.Warn("Low disk space.");
//     logger.Error("Failed to open file.");

//     return 0;
// }
