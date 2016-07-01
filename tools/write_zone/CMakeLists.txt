set(SOURCES ${SOURCES} zbc_write_zone.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_write_zone ${SOURCES})
target_link_libraries(zbc_write_zone zbc pthread)
