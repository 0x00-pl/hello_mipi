cmake_minimum_required(VERSION 2.6)
project(mipi)
file(GLOB SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.h"
    )

add_executable(mipi ${SOURCE_FILES})

#format
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(ClangFormat)
if(NOT CLANG_FORMAT_FOUND)
    message(WARNING "ClangFormat is needed to format code.")
else()
    add_custom_target(code_format
        COMMAND ${CLANG_FORMAT_EXECUTABLE} -style=file -i ${SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        COMMENT "ClangFormat all sources"
        VERBATIM
        )
    add_dependencies(mipi code_format)
endif()
    

#doxygen
find_package(Doxygen)  
if(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen is needed to build the documentation.")
else()
    add_custom_target(docs 
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/doxygen.cfg
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
        )
endif()
