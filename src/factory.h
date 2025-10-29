#pragma once

#include "logger.h"
#include "console_logger.h"
#include "spd_logger.h"
#include <string.h>
#include "rotating_spd_logger.h"


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
        else if (type == LoggerType::RotatingSpd) {
            auto* rot = new RotatingSpdLogger(cfg);
            rot->init();
            return rot;
        }
        else {
            throw std::invalid_argument("Invalid logger type");
        }
    }
};