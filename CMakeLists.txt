cmake_minimum_required(VERSION 2.6)
project(mipi)
file(GLOB SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
    )

add_executable(mipi ${SOURCE_FILES})


#format
find_package(ClangFormat)
if(NOT CLANG_FORMAT_FOUND)
    message(WARNING "ClangFormat is needed to format code.")
else()
    add_custom_target(code_format
        COMMAND ${CLANG_FORMAT_EXECUTABLE} -style=file -i ${SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        )
    add_dependencies(mipi code_format)
endif()
    
