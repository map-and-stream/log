#pragma once

#include "logger.h"
#include <string>


class SpdLogger : public ILogger {
public:
    SpdLogger();
    ~SpdLogger();
    public:
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
};