cmake_minimum_required(VERSION 3.16)
project(gnutella-c LANGUAGES C)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CPP_COMPILER clang)

file(GLOB_RECURSE C_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE C_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${PROJECT_NAME}
            ${C_FILES}
            ${C_HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)