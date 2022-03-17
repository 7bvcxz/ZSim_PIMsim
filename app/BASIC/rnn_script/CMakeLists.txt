cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(rnn_test)

find_package(Torch REQUIRED)

add_executable(rnn_test rnn_test.cpp)
target_link_libraries(rnn_test "${TORCH_LIBRARIES}")
set_property(TARGET rnn_test PROPERTY CXX_STANDARD 14)
