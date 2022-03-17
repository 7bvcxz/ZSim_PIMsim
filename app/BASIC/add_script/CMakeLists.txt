cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(add_test)

find_package(Torch REQUIRED)

add_executable(add_test add_test.cpp)
target_link_libraries(add_test "${TORCH_LIBRARIES}")
set_property(TARGET add_test PROPERTY CXX_STANDARD 14)
