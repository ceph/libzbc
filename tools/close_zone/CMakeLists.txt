set(SOURCES ${SOURCES} zbc_close_zone.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_close_zone ${SOURCES})
target_link_libraries(zbc_close_zone zbc pthread)
