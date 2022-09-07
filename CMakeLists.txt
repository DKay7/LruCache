cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(lru_cache VERSION 1.0)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-tests tests.cpp)
