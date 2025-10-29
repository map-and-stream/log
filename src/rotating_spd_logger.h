#pragma once

#include "logger.h"
#include <spdlog/logger.h>
#include <memory>
#include <string>

class RotatingSpdLogger : public ILogger {
public:
    explicit RotatingSpdLogger(LogConfig cfg);
    ~RotatingSpdLogger();

    void info(const std::string& message) override;
    void warn(const std::string& message) override;
    void error(const std::string& message) override;

    void setLogLevel(LogLevel level) override;
    bool init() override;

private:
    std::shared_ptr<spdlog::logger> logger;
    LogConfig config;

    void cleanupOldLogs();
};
