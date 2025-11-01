#include "sqlite_log_bridge.h"
#include <sqlite3.h>
#include <string>

namespace {

    // sqlite callback
    void sqlite_log_callback(void* pArg, int errCode, const char* zMsg) {
        if (!pArg) return;
        ILogger* logger = static_cast<ILogger*>(pArg);
        std::string msg = zMsg ? zMsg : std::string();

        // Map errCode to log level: treat 0 (SQLITE_OK) as info, others as error/warn.
        // You can refine mapping if you want specific codes -> warn/info.
        if (errCode == SQLITE_OK) {
            logger->info(msg);
        } else {
            // for SQLITE_WARNING or others you might want warn, but many sqlite codes >0 are errors
            logger->error(std::string("SQLite[") + std::to_string(errCode) + "]: " + msg);
        }
    }

    // store last attached userdata so detach works
    void* g_sqlite_userdata = nullptr;
}

namespace logbridge {

void attachSqliteLogger(ILogger* logger) {
    // call sqlite3_config to set log callback. Must be before sqlite3_open and sqlite3_initialize
    if (!logger) return;
    int rc = sqlite3_config(SQLITE_CONFIG_LOG, sqlite_log_callback, logger);
    if (rc == SQLITE_OK) {
        g_sqlite_userdata = logger;
    } else {
        // optional: fallback or print to stderr
        std::cerr << "Failed to configure sqlite logging: " << rc << std::endl;
    }
}

void detachSqliteLogger() {
    // to detach, pass nullptr as userdata. (Note: sqlite3_config persists until changed)
    int rc = sqlite3_config(SQLITE_CONFIG_LOG, sqlite_log_callback, nullptr);
    if (rc == SQLITE_OK) {
        g_sqlite_userdata = nullptr;
    } else {
        std::cerr << "Failed to detach sqlite logging: " << rc << std::endl;
    }
}

} // namespace logbridge

