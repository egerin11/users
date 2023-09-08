cmake_minimum_required(VERSION 3.24)
project(users)

set(CMAKE_CXX_STANDARD 17)

add_executable(users_site main.cpp lib/user.h garbage/user.cpp lib/function.h garbage/function.cpp garbage/parse_file.cpp garbage/run_app.cpp)
