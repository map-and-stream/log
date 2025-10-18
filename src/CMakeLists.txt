set(LIBRARY_NAME log)

set(LOG_SOURCES
console_logger.cpp
)

set(LOG_HEADERS
logger.h
console_logger.h
)

add_library(${LIBRARY_NAME} STATIC ${LOG_SOURCES})

# Keep headers associated with this target for IDEs, but do not propagate
target_sources(${LIBRARY_NAME} PRIVATE ${LOG_HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Convenient namespaced alias for downstream targets
add_library(${LIB_ALIAS} ALIAS ${LIBRARY_NAME})