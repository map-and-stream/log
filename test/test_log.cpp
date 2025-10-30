#include <gtest/gtest.h>
#include "factory.h"
#include <sstream>
#include <iostream>

TEST(SampleTest, BasicAssertion) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(LogTest, InfoOutput) {
    LogConfig cfg;
    cfg.filePath = ".";
    cfg.maxLogRotate = 100;
    cfg.logLevel = LogLevel::error;

    ILogger* l = LoggerFactory::createLogger(LoggerType::Console, cfg);
    testing::internal::CaptureStdout();
    l->info("Hello");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[INFO] Hello"), std::string::npos);
}
