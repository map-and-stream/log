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

// --- Simple Console Logger Implementation ---
class ConsoleLogger : public ILogger {
public:
    void Info(const std::string& message) override {
        std::cout << "[INFO]  " << message << std::endl;
    }

    void Warn(const std::string& message) override {
        std::cout << "[WARN]  " << message << std::endl;
    }

    void Error(const std::string& message) override {
        std::cout << "[ERROR] " << message << std::endl;
    }
};

// --- Example Usage ---
int main() {
    ConsoleLogger logger;

    logger.Info("Application started.");
    logger.Warn("Low disk space.");
    logger.Error("Failed to open file.");

    return 0;
}
