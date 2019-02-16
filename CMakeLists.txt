cmake_minimum_required(VERSION 2.6)
project(mipi)

add_executable(mipi main.cpp)

install(TARGETS mipi RUNTIME DESTINATION bin)
