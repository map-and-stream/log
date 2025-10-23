#pragma once

#include "logger.h"
#include "console_logger.h"
#include "spd_logger.h"
#include <string.h>



class LoggerFactory {
public:
    static ILogger* createLogger(LoggerType type, LogConfig cfg) {
        if (type == LoggerType::Console) {
            return new ConsoleLogger(cfg);
        }
        else if (type == LoggerType::Spdlog) {
            SpdLogger *spd = new SpdLogger(cfg);//TODO: using smart pointer
            spd->init();
            return spd;
        }
        else {
            throw std::invalid_argument("Invalid logger type");
        }
    }
};