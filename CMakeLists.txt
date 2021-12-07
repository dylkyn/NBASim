cmake_minimum_required(VERSION 3.20)
project(NBASim)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/include)
add_library(my-lib Player.cpp Player.h Team.cpp Team.h Game.cpp Game.h)
add_executable(NBASim main.cpp)
target_link_libraries(NBASim my-lib sfml-system sfml-window sfml-graphics sfml-audio sfml-audio)
