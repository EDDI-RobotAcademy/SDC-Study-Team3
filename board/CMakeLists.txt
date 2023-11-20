cmake_minimum_required(VERSION 3.16)
project(test_app C) 

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCE_FILES
    "*.c"
    "board/domain/model/*.c"
    "board/adapter/api/request/*.c"
    "board/application/service/*.c"
    "board/application/service/add/*.c"
    "board/application/service/delete/*.c"
    "board/application/service/edit/*.c"
    "board/application/service/lista/*.c"
    "board/application/service/read/*.c"
    
)
add_executable(
    test_app
    ${SOURCE_FILES}
)
