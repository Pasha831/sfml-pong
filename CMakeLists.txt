cmake_minimum_required(VERSION 3.22)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game main.cpp Paddle.cpp Paddle.h Ball.cpp Ball.h Game.cpp Game.h)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(SFML/include)
target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)