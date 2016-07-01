set(SOURCES ${SOURCES} zbc_report_zones.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_report_zones ${SOURCES})
target_link_libraries(zbc_report_zones zbc pthread)
