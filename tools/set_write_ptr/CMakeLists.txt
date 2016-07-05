set(SOURCES ${SOURCES} zbc_set_write_ptr.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_set_write_ptr ${SOURCES})
target_link_libraries(zbc_set_write_ptr zbc pthread)
