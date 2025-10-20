#include "console_logger.h"
#include "spd_logger.h"

int main() {
    ConsoleLogger l{};
    l.info("This is an info message.");
    l.warn("This is a warning message.");
    l.error("This is an error message.");

    SpdLogger s{};
    s.info("This is an info message.");
    s.warn("This is a warning message.");
    s.error("This is an error message.");
    return 0;
}
