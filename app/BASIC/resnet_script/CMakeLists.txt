cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(resnet_test)

find_package(Torch REQUIRED)

add_executable(resnet_test resnet_test.cpp)
target_link_libraries(resnet_test "${TORCH_LIBRARIES}")
set_property(TARGET resnet_test PROPERTY CXX_STANDARD 14)
