cmake_minimum_required(VERSION 3.20)

# Create the testing project
project(aocTest CXX)

set (AUX_TEST_FILES
        test_dayOne.cpp)

set(SOURCE_AUX_FILES
        ../src/aoc.cpp)

set(AUX_TEST_INCLUDES
        ../src/
        ../src/inc/)


add_executable(aocTest test_main.cpp ${SOURCE_AUX_FILES} ${AUX_TEST_FILES})

target_include_directories(aocTest
        PUBLIC
        ${SOURCE_INCLUDE_DIRS}
        ${AUX_TEST_INCLUDES}
        ${GTEST_SOURCE_DIR}/include
        ${GTEST_SOURCE_DIR})

target_link_libraries(aocTest
        PRIVATE
        gtest
        gtest_main
        project_warnings
        project_options)