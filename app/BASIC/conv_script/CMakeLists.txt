cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(conv_test)

find_package(Torch REQUIRED)

add_executable(conv_test conv_test.cpp)
target_link_libraries(conv_test "${TORCH_LIBRARIES}")
set_property(TARGET conv_test PROPERTY CXX_STANDARD 14)
