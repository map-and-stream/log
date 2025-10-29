#include "rotating_spd_logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <filesystem>
#include <chrono>
#include <regex>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

RotatingSpdLogger::RotatingSpdLogger(LogConfig cfg) : ILogger(cfg), config(cfg) {
    if (!fs::exists(cfg.filePath)) {
        fs::create_directories(cfg.filePath);
    }

    auto sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(
        cfg.filePath + "/log.txt", 0, 0); 

    logger = std::make_shared<spdlog::logger>("rotating_logger", sink);
    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);

    setLogLevel(cfg.logLevel);
}

RotatingSpdLogger::~RotatingSpdLogger() {
    spdlog::drop("rotating_logger");
}

bool RotatingSpdLogger::init() {
    cleanupOldLogs();
    return true;
}

void RotatingSpdLogger::info(const std::string& message) {
    logger->info(message);
}

void RotatingSpdLogger::warn(const std::string& message) {
    logger->warn(message);
}

void RotatingSpdLogger::error(const std::string& message) {
    logger->error(message);
}

void RotatingSpdLogger::setLogLevel(LogLevel level) {
    logger->set_level(static_cast<spdlog::level::level_enum>(level));
    currentLogLevel = level;
}

void RotatingSpdLogger::cleanupOldLogs() {
    const std::regex logPattern(R"(log\.txt\.(\d{4}-\d{2}-\d{2}))");
    const auto now = std::chrono::system_clock::now();

    for (const auto& entry : fs::directory_iterator(config.filePath)) {
        if (!entry.is_regular_file()) continue;

        std::smatch match;
        const std::string filename = entry.path().filename().string();
        if (std::regex_match(filename, match, logPattern)) {
            std::tm tm = {};
            std::istringstream ss(match[1].str());
            ss >> std::get_time(&tm, "%Y-%m-%d");
            auto fileTime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
            auto age = std::chrono::duration_cast<std::chrono::hours>(now - fileTime).count() / 24;

            if (age > config.maxLogRotate) {
                fs::remove(entry.path());
            }
        }
    }
}
