cmake_minimum_required(VERSION 3.16)
project(gnutella-c)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CXX_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE CXX_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${PROJECT_NAME}
            ${CXX_FILES}
            ${CXX_HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)