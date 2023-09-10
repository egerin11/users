cmake_minimum_required(VERSION 3.24)
project(users_site)

set(CMAKE_CXX_STANDARD 11)

add_executable(users_site main.cpp lib/user.h lib/function.h garbage/function.cpp garbage/parse_file.cpp garbage/run_app.cpp lib/site_data_model.h lib/dymanic_array.h lib/site.h)
