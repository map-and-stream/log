#include "factory.h"

int main() {
    ILogger* l = LoggerFactory::createLogger(LoggerType::Console);
    l->info("This is an info message.");
    l->warn("This is a warning message.");
    l->error("This is an error message.");

    ILogger* s = LoggerFactory::createLogger(LoggerType::Spdlog);
    s->info("This is an info message.");
    s->warn("This is a warning message.");
    s->error("This is an error message.");

    // INSERT_YOUR_CODE
    // Attempt to create logger with an invalid type and handle possible failure
    ILogger* invalidLogger = LoggerFactory::createLogger(static_cast<LoggerType>(-1));
    if (!invalidLogger) {
        std::cout << "Failed to create logger: invalid logger type." << std::endl;
    } else {
        invalidLogger->info("This should not happen.");
    }


    return 0;
}
