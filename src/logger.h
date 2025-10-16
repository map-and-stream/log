#include <iostream>
#include <string>

// --- Abstract Logger Interface ---
class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void Info(const std::string& message) = 0;
    virtual void Warn(const std::string& message) = 0;
    virtual void Error(const std::string& message) = 0;
};



// --- Example Usage ---
// int main() {
//     ConsoleLogger logger;

//     logger.Info("Application started.");
//     logger.Warn("Low disk space.");
//     logger.Error("Failed to open file.");

//     return 0;
// }
