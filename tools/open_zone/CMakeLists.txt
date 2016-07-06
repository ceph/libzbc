set(SOURCES ${SOURCES} zbc_open_zone.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_open_zone ${SOURCES})
target_link_libraries(zbc_open_zone zbc pthread)
