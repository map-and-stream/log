#include "spd_logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/hourly_file_sink.h>
#include <filesystem>
#include <chrono>
#include <regex>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

SpdLogger::SpdLogger(LogConfig cfg, SpdLogConfig spdCfg)
    : ILogger(cfg), config(cfg), spdConfig(spdCfg) {
    if (!fs::exists(spdConfig.filePath)) {
        fs::create_directories(spdConfig.filePath);
    }

    std::shared_ptr<spdlog::sinks::sink> sink;
    std::string fullPath = spdConfig.filePath + "/" + spdConfig.fileName;

    switch (spdConfig.sinkType) {
        case SpdSinkType::Daily:
            sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(fullPath, 0, 0);
            break;
        case SpdSinkType::Hourly:
            sink = std::make_shared<spdlog::sinks::hourly_file_sink_mt>(fullPath);
            break;
        case SpdSinkType::Basic:
        default:
            sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(fullPath, true);
            break;
    }

    logger = std::make_shared<spdlog::logger>("spd_logger", sink);
    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);

    setLogLevel(cfg.logLevel);
}

SpdLogger::~SpdLogger() {
    spdlog::drop("spd_logger");
}

bool SpdLogger::init() {
    if (spdConfig.sinkType != SpdSinkType::Basic) {
        cleanupOldLogs();
    }
    return true;
}

void SpdLogger::info(const std::string& message) {
    logger->info(message);
}

void SpdLogger::warn(const std::string& message) {
    logger->warn(message);
}

void SpdLogger::error(const std::string& message) {
    logger->error(message);
}

void SpdLogger::setLogLevel(LogLevel level) {
    logger->set_level(static_cast<spdlog::level::level_enum>(level));
    currentLogLevel = level;
}

void SpdLogger::cleanupOldLogs() {
    if (spdConfig.logRegexPattern.empty() || spdConfig.logDateFormat.empty()) return;

    const std::regex logPattern(spdConfig.logRegexPattern);
    const auto now = std::chrono::system_clock::now();

    for (const auto& entry : fs::directory_iterator(spdConfig.filePath)) {
        if (!entry.is_regular_file()) continue;

        std::smatch match;
        const std::string filename = entry.path().filename().string();
        if (!std::regex_match(filename, match, logPattern)) continue;

        std::tm tm = {};
        std::istringstream ss(match[1].str());
        ss >> std::get_time(&tm, spdConfig.logDateFormat.c_str());
        if (ss.fail()) continue;

        auto fileTime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        auto ageHours = std::chrono::duration_cast<std::chrono::hours>(now - fileTime).count();

        if (spdConfig.sinkType == SpdSinkType::Hourly) {
            if (ageHours > spdConfig.maxRotateHours) {
                fs::remove(entry.path());
            }
        } else if (spdConfig.sinkType == SpdSinkType::Daily) {
            if (ageHours > spdConfig.maxRotateDays * 24) {
                fs::remove(entry.path());
            }
        }
    }
}
