#pragma once

#include "logger.h"
#include "console_logger.h"
#include "spd_logger.h"
#include <memory>

class LoggerFactory {
public:
    static std::unique_ptr<ILogger> createLogger(LoggerType type, LogConfig cfg, SpdLogConfig spdCfg = {}) {
        switch (type) {
            case LoggerType::Console:
                return std::make_unique<ConsoleLogger>(cfg);

            case LoggerType::Spdlog:
            case LoggerType::RotatingSpd: 
            {
                auto spd = std::make_unique<SpdLogger>(cfg, spdCfg);
                spd->init();
                return spd;
            }

            default:
                throw std::invalid_argument("Invalid logger type");
        }
    }
};
