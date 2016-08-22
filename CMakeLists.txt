cmake_minimum_required(VERSION 2.8)
project(libzbc)

set(LIBZBC_MAJOR_VERSION 4)
set(LIBZBC_MINOR_VERSION 1)
set(LIBZBC_PATCH_VERSION 1)

set(LIBZBC_VERSION
	${LIBZBC_MAJOR_VERSION}.${LIBZBC_MINOR_VERSION}.${LIBZBC_PATCH_VERSION})

set(CMAKE_INSTALL_PREFIX "/usr")
set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib")
set(INSTALL_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/include")

set(LIBZBC_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIBZBC_LINK_DIR "${LIBZBC_ROOT_DIR}/lib")
include_directories("${LIBZBC_ROOT_DIR}/include")

set(CMAKE_COMPILE_FLAGS "-O2 -Wall -Wextra -Wno-unused-parameter -fPIC -I${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIBZBC_INCLUDE_PATH "${CMAKE_INCLUDE_PATH} ${LIBZBC_ROOT_DIR}/lib" PARENT_SCOPE)

add_subdirectory("${LIBZBC_ROOT_DIR}/include")
add_subdirectory("${LIBZBC_ROOT_DIR}/lib")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/info")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/report_zones")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/reset_write_ptr")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/read_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/write_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/open_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/close_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/finish_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/set_write_ptr")
add_subdirectory("${LIBZBC_ROOT_DIR}/tools/set_zones")

if(BUILD_TEST)
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/close_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/print_devinfo")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/report_zones")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/reset_write_ptr")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/open_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/finish_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/read_zone")
add_subdirectory("${LIBZBC_ROOT_DIR}/test/programs/write_zone")
endif(BUILD_TEST)
