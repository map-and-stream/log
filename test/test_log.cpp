#include <gtest/gtest.h>
#include "factory.h"
#include "spd_logger.h"
#include <sstream>
#include <iostream>
#include <memory>

TEST(SampleTest, BasicAssertion) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(LogTest, InfoOutput) {
    LogConfig cfg;
    cfg.filePath = ".";
    cfg.logLevel = LogLevel::info;

    auto logger = LoggerFactory::createLogger(LoggerType::Console, cfg);

    testing::internal::CaptureStdout();
    logger->info("Hello");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("[INFO] Hello"), std::string::npos);
}
