#pragma once

#include <iostream>
#include <string>

enum class LogLevel {
    info,
    warn,
    error
};

enum class LoggerType {
    Console,
    Spdlog
};

struct LogConfig {
    std::string filePath; 
    int maxLogRotate; //per days
    LogLevel logLevel;
};

// --- Abstract Logger Interface ---
class ILogger {
public:
    virtual ~ILogger() = default;
    ILogger(LogConfig cfg){}

    virtual void info(const std::string& message) = 0;
    virtual void warn(const std::string& message) = 0;
    virtual void error(const std::string& message) = 0;

    virtual void setLogLevel(LogLevel level) = 0;
    virtual LogLevel logLevel() {return currentLogLevel;};
protected:
    LogLevel currentLogLevel = LogLevel::warn;
};



// --- Example Usage ---
// int main() {
//     ConsoleLogger logger;

//     logger.Info("Application started.");
//     logger.Warn("Low disk space.");
//     logger.Error("Failed to open file.");

//     return 0;
// }
