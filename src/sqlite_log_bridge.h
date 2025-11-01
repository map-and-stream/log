#pragma once

#include "logger.h"   // ILogger / LogLevel declaration
// forward-declare sqlite3 to avoid forcing include in header
struct sqlite3;

namespace logbridge {

    // attach sqlite internal logging to given ILogger instance.
    // call this before any sqlite3_open / sqlite3_initialize calls.
    void attachSqliteLogger(ILogger* logger);

    // detach (optional) - restores default behaviour (NULL userdata)
    void detachSqliteLogger();

} // namespace logbridge

