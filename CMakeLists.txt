cmake_minimum_required(VERSION 3.24)
project(users_site)

set(CMAKE_CXX_STANDARD 17)

add_executable(users_site main.cpp user.h user.cpp)
