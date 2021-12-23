cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(SNAKE)

add_executable(${PROJECT_NAME} main.cpp Game.hpp Game.cpp Snake.hpp Snake.cpp Fruit.cpp Fruit.hpp)

add_subdirectory(SFML)

target_link_directories(${PROJECT_NAME} PUBLIC SFML/extlibs)
target_include_directories(${PROJECT_NAME} PUBLIC SFML/include)
target_link_libraries(${PROJECT_NAME} sfml-graphics)