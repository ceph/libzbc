include_directories(../liblkvs ../../../../include)
add_executable(lkvsput lkvsput.cc)
add_executable(lkvsget lkvsget.cc)
add_executable(lkvsmultiput lkvsmultiput.cc)
add_executable(lkvsmultiget lkvsmultiget.cc)
add_executable(lkvsfileput lkvsfileput.cc)

target_link_libraries(lkvsput ../liblkvs/liblkvs ../../../../libzbc)
target_link_libraries(lkvsget ../liblkvs/liblkvs ../../../../libzbc)
target_link_libraries(lkvsmultiput ../liblkvs/liblkvs ../../../../libzbc)
target_link_libraries(lkvsmultiget ../liblkvs/liblkvs ../../../../libzbc)
target_link_libraries(lkvsfileput ../liblkvs/liblkvs ../../../../libzbc)
