cmake_minimum_required(VERSION 3.16)
project(local-peregrine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(gnutella-c)
add_subdirectory(gnutella-cpp)
add_subdirectory(network)
add_subdirectory(fs)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} gnutella-c)
target_link_libraries(${PROJECT_NAME} gnutella-cpp)
target_link_libraries(${PROJECT_NAME} network)
target_link_libraries(${PROJECT_NAME} fs)