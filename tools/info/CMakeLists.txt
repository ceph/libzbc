set(SOURCES ${SOURCES} zbc_info.c ${HEADER_FILES})
link_directories(${LIBZBC_LINK_DIR})
add_executable(zbc_info ${SOURCES})
target_link_libraries(zbc_info zbc pthread)
