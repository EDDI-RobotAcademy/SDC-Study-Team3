# CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(test_app C CXX)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)

if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()

# C source files
# 기존의 main.c에 병합될 소스코드(원래 하던대로 넣으면 됨)
file(GLOB C_SOURCES
    "board/domain/model/*.c"

    "board/adapter/api/request/board_operation_request.c"

    "board/adapter/api/add/*.c"
    "board/adapter/api/list_handler/list/*.c"
    "board/adapter/api/list_handler/list_read_data/*.c"
    "board/adapter/api/list_handler/make_format_from_file/*.c"
    "board/adapter/api/list_handler/make_file/*.c"

    "board/adapter/out/list_out/*.c"

    "board/applicaton/post/add/*.c"
    "board/applicaton/post/delete/*.c"
    "board/applicaton/post/edit/*.c"
    "board/applicaton/post/list/*.c"
    "board/applicaton/post/read/*.c"
    
    "board/adapter/api/*.c"
    "board/adapter/out/*.c"
    "board/application/post/*.c"
)

# C++ test source files
# test로 사용할 파일들을 여기에 배치
# network 폴더를 사용한다면 tests/network/*.cpp 형태로 작성
file(GLOB CPP_TEST_SOURCES
    "tests/*.cpp"

)

# Create a library from the shared C source files
add_library(simple_lib ${C_SOURCES})

# Test executable (C and C++)
add_executable(every_unit_test ${CPP_TEST_SOURCES} "tests/test_main.cpp" ${C_SOURCES})
target_link_libraries(every_unit_test PRIVATE ${GTEST_LIBRARIES} pthread simple_lib)

add_test(NAME every_unit_test COMMAND every_unit_test)
set_tests_properties(every_unit_test PROPERTIES FAIL_REGULAR_EXPRESSION ".*[Ff]ail.*")

# Custom command to check test results and build c_app accordingly
add_custom_command(
    TARGET every_unit_test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Checking test results..."
    COMMAND ${CMAKE_COMMAND} -E env TEST_RESULT=$<TARGET_FILE:every_unit_test> ${CMAKE_CURRENT_SOURCE_DIR}/build_script.sh
    COMMAND_ERROR_IS_FATAL
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running every_unit_test and building c_app if tests pass..."
    VERBATIM
)


# # Custom target to build c_app only if tests pass
# add_custom_target(build_c_app
#     DEPENDS every_unit_test
# )

# Main application (C)
file(GLOB MAIN_SOURCES
    "*.c"
    
)

# Only build c_app if every_unit_test is successful
add_executable(
    c_app
    ${C_SOURCES}
    ${MAIN_SOURCES}
)

# Set 'make run' as the default target
add_custom_target(run
    DEPENDS every_unit_test
)