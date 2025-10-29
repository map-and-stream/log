#include "factory.h"
#include "logger.h"
#include <iostream>

int main() {
    LogConfig cfg;
    cfg.filePath = ".";
    cfg.maxLogRotate = 100;
    cfg.logLevel = LogLevel::info;

    // Console logger
    ILogger* l = LoggerFactory::createLogger(LoggerType::Console, cfg);
    l->info("Console: info");
    l->warn("Console: warn");
    l->error("Console: error");

    // Spdlog logger
    cfg.logLevel = LogLevel::error;
    ILogger* s = LoggerFactory::createLogger(LoggerType::Spdlog, cfg);
    s->info("Spdlog: info");
    s->warn("Spdlog: warn");
    s->error("Spdlog: error");

    // RotatingSpd logger
    cfg.filePath = "./logs";
    cfg.maxLogRotate = 3;
    cfg.logLevel = LogLevel::info;
    ILogger* r = LoggerFactory::createLogger(LoggerType::RotatingSpd, cfg);
    r->info("RotatingSpd: info");
    r->warn("RotatingSpd: warn");
    r->error("RotatingSpd: error");

    // Invalid logger type
    try {
        ILogger* invalidLogger = LoggerFactory::createLogger(static_cast<LoggerType>(-1), cfg);
        invalidLogger->info("This should not happen.");
    } catch (const std::exception& ex) {
        std::cout << "Failed to create logger: " << ex.what() << std::endl;
    }

    return 0;
}
