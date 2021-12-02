cmake_minimum_required (VERSION 3.20)

set(SOURCE_INCLUDE_DIRS
        ./
        ./inc)

set(AUX_SOURCE)

# Add source to this project's executable.
add_executable (aoc main.cpp ${AUX_SOURCE})
target_include_directories(aoc PUBLIC ${SOURCE_INCLUDE_DIRS})
target_link_libraries(aoc PRIVATE project_warnings project_options)