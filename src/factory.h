#pragma once

#include "logger.h"
#include "console_logger.h"
#include "spd_logger.h"

enum class LoggerType {
    Console,
    Spdlog
};

class LoggerFactory {
public:
    static ILogger* createLogger(LoggerType type) {
        if (type == LoggerType::Console) {
            return new ConsoleLogger();
        }
        else if (type == LoggerType::Spdlog) {
            return new SpdLogger();
        }
        else {
            throw std::invalid_argument("Invalid logger type");
        }
    }
};