cmake_minimum_required(VERSION 3.10)
project(estafetas)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")

file(GLOB FILES CONFIGURE_DEPENDS "codigo/*.cpp")
add_executable(project codigo/main.cpp ${FILES})

# Doxygen-generated documentation (doxygen needs to be installed)
find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_EXTRACT_PRIVATE "YES")
    set(DOXYGEN_EXTRACT_STATIC "YES")
    set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

    # set input and output files
    set(DOXYGEN_IN ${PROJECT_BINARY_DIR}/CMakeDoxyfile.in)
    set(DOXYGEN_OUT ${PROJECT_BINARY_DIR}/CMakeDoxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY "../codigo"
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)