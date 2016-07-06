set(SOURCES ${SOURCES} zbc_finish_zone.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_finish_zone ${SOURCES})
target_link_libraries(zbc_finish_zone zbc pthread)
