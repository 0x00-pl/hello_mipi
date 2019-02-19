cmake_minimum_required(VERSION 2.6)
project(mipi)
file(GLOB SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
    )

add_executable(mipi ${SOURCE_FILES})

