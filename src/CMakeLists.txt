set(LOG_SOURCES
console_logger.cpp
)

set(LOG_HEADERS
logger.h
console_logger.h
)

add_library(log STATIC ${LOG_SOURCES})

# Keep headers associated with this target for IDEs, but do not propagate
target_sources(log PRIVATE ${LOG_HEADERS})

target_include_directories(log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Convenient namespaced alias for downstream targets
add_library(isiran::log ALIAS log)