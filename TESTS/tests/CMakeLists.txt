cmake_minimum_required(VERSION 3.10)
project(tests_catch)

add_executable(${PROJECT_NAME} main_catch.cpp test.cpp catch_amalgamated.cpp)
