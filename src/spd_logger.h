#pragma once

#include "logger.h"
#include <memory>
#include <string>
#include <spdlog/logger.h>

enum class SpdSinkType {
    Basic,
    Daily,
    Hourly
};

struct SpdLogConfig {
    std::string filePath = "./logs";
    std::string fileName = "log.txt";
    std::string logRegexPattern;
    std::string logDateFormat;
    int maxRotateDays = 7;
    int maxRotateHours = 168;
    SpdSinkType sinkType = SpdSinkType::Basic;

    SpdLogConfig() {
        switch (sinkType) {
            case SpdSinkType::Daily:
                logRegexPattern = R"(log\.txt\.(\d{4}-\d{2}-\d{2}))";
                logDateFormat = "%Y-%m-%d";
                break;
            case SpdSinkType::Hourly:
                logRegexPattern = R"(log\.txt\.(\d{4}-\d{2}-\d{2}_\d{2}))";
                logDateFormat = "%Y-%m-%d_%H";
                break;
            case SpdSinkType::Basic:
            default:
                logRegexPattern = "";
                logDateFormat = "";
                break;
        }
    }
};

class SpdLogger : public ILogger {
public:
    SpdLogger(LogConfig cfg, SpdLogConfig spdCfg);
    ~SpdLogger();

    void info(const std::string& message) override;
    void warn(const std::string& message) override;
    void error(const std::string& message) override;

    void setLogLevel(LogLevel level) override;
    bool init() override;

private:
    std::shared_ptr<spdlog::logger> logger;
    LogConfig config;
    SpdLogConfig spdConfig;

    void cleanupOldLogs();
};
