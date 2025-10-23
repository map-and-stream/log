#include "spd_logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "logger.h"
#include "spdlog/common.h"

SpdLogger::SpdLogger(LogConfig cfg) : ILogger(cfg) {
    setLogLevel(cfg.logLevel);
    
}

SpdLogger::~SpdLogger() {
    spdlog::drop_all();
}

void SpdLogger::info(const std::string& message) {
    spdlog::info(message);
}

void SpdLogger::warn(const std::string& message) {
    spdlog::warn(message);
}

void SpdLogger::error(const std::string& message) {
    spdlog::error(message);
}

void SpdLogger::setLogLevel(LogLevel level) {
    switch (level) {
        case LogLevel::info:
            spdlog::set_level(spdlog::level::info);
            break;
        case LogLevel::warn:
            spdlog::set_level(spdlog::level::warn);
            break;
        case LogLevel::error:
            spdlog::set_level(spdlog::level::err);
            break;
        default:
        spdlog::set_level(spdlog::level::info);
    }
    currentLogLevel = level;
}