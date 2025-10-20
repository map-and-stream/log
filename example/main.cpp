#include "factory.h"

int main() {
    ILogger* l = LoggerFactory::createLogger(LoggerType::Console);
    l->info("This is an info message.");
    l->warn("This is a warning message.");
    l->error("This is an error message.");

    ILogger* s = LoggerFactory::createLogger(LoggerType::Spdlog);
    s->info("This is an info message.");
    s->warn("This is a warning message.");
    s->error("This is an error message.");
    return 0;
}
