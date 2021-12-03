cmake_minimum_required(VERSION 3.20)
project(NBASim)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/include)
add_executable(NBASim main.cpp)
target_link_libraries(NBASim sfml-system sfml-window sfml-graphics sfml-audio sfml-audio)
