set(SOURCES zbc.c zbc_block.c zbc_sg.c zbc_scsi.c zbc_ata.c zbc_fake.c zbc_tools.c)
set(HEADER_FILES zbc.h zbc_sg.h zbc_tools.h)

add_library(zbc SHARED ${SOURCES} ${HEADER_FILES})

set_target_properties(zbc PROPERTIES COMPILE_FLAGS ${CMAKE_COMPILE_FLAGS})
set_target_properties(zbc PROPERTIES CMAKE_SHARE_LINKER_FLAGS "-Wl,--version-script -release ${LIBZBC_VERSION}")
