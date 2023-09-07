cmake_minimum_required(VERSION 3.24)
project(users_site)

set(CMAKE_CXX_STANDARD 17)

add_executable(users_site main.cpp lib/user.h garbage/user.cpp lib/function.h garbage/function.cpp garbage/parse_file.cpp)
