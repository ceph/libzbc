include_directories(m4)
add_subdirectory(src)

add_custom_command(check-local
		COMMAND cd src/test
		COMMAND make check)

if(WITH_PYBIND)
add_custom_command(pybind
		COMMAND cd src/pybind
		COMMAND make pybind)
endif(WITH_PYBIND)

if(WITH_JAVABIND)
add_custom_command(javabind
		COMMAND cd src/javabind
		COMMAND make javabind)
endif(WITH_JAVABIND)
