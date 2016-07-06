set(SOURCES ${SOURCES} zbc_set_zones.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_set_zones ${SOURCES})
target_link_libraries(zbc_set_zones zbc pthread)
