cmake_minimum_required(VERSION 3.10)
project(estafetas)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")

file(GLOB FILES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(main src/main.cpp ${FILES})

