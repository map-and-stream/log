#include "spd_logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

SpdLogger::SpdLogger() {
    spdlog::set_level(spdlog::level::info);
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