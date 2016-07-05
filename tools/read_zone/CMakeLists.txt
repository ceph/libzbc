set(SOURCES ${SOURCES} zbc_read_zone.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_read_zone ${SOURCES})
target_link_libraries(zbc_read_zone zbc pthread)
