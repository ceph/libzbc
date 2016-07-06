set(SOURCES ${SOURCES} gzbc.c gzbc_if.c gzbc_if_dev.c gzbc.h)
#add_library(gzbc SHARED ${SOURCES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(gzbc ${SOURCES})

target_link_libraries(gzbc ${GTK3_LIBRARIES})
#set_target_properties(gzbc PROPERTIES COMPILE_FLAGS ${CMAKE_COMPILE_FLAGS} ${GTK_CFLAGS})
#set_target_properties(gzbc PROPERTIES CMAKE_SHARE_LINKER_FLAGS ${GTK_LIBS})
