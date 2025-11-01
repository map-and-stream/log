#include "factory.h"
#include "logger.h"
#include "spd_logger.h"
#include <iostream>
#include <memory>

int main() {
    LogConfig cfg;
    cfg.filePath = ".";
    cfg.logLevel = LogLevel::info;

    auto consoleLogger = LoggerFactory::createLogger(LoggerType::Console, cfg);
    consoleLogger->info("Console: info");
    consoleLogger->warn("Console: warn");
    consoleLogger->error("Console: error");

    cfg.logLevel = LogLevel::error;
    SpdLogConfig basicCfg;
    basicCfg.sinkType = SpdSinkType::Basic;
    basicCfg.maxRotateDays = 0;
    basicCfg.maxRotateHours = 0;
    auto basicLogger = LoggerFactory::createLogger(LoggerType::Spdlog, cfg, basicCfg);
    basicLogger->info("Spdlog Basic: info");
    basicLogger->warn("Spdlog Basic: warn");
    basicLogger->error("Spdlog Basic: error");

    cfg.logLevel = LogLevel::info;
    SpdLogConfig dailyCfg;
    dailyCfg.sinkType = SpdSinkType::Daily;
    dailyCfg.maxRotateDays = 3;
    dailyCfg.maxRotateHours = 0;
    auto dailyLogger = LoggerFactory::createLogger(LoggerType::Spdlog, cfg, dailyCfg);
    dailyLogger->info("Rotating Daily: info");
    dailyLogger->warn("Rotating Daily: warn");
    dailyLogger->error("Rotating Daily: error");

    SpdLogConfig hourlyCfg;
    hourlyCfg.sinkType = SpdSinkType::Hourly;
    hourlyCfg.maxRotateDays = 0;
    hourlyCfg.maxRotateHours = 10;
    auto hourlyLogger = LoggerFactory::createLogger(LoggerType::Spdlog, cfg, hourlyCfg);
    hourlyLogger->info("Rotating Hourly: info");
    hourlyLogger->warn("Rotating Hourly: warn");
    hourlyLogger->error("Rotating Hourly: error");

    try {
        auto invalidLogger = LoggerFactory::createLogger(static_cast<LoggerType>(-1), cfg);
        invalidLogger->info("This should not happen.");
    } catch (const std::exception& ex) {
        std::cout << "Failed to create logger: " << ex.what() << std::endl;
    }

    return 0;
}
