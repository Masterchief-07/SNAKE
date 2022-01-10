cmake_minimum_required(VERSION 3.22)

project(GAME)

add_subdirectory(../SFML SFML)

add_executable(${PROJECT_NAME} main.cpp Game.hpp  Game.cpp Window.hpp Window.cpp Snake.hpp Snake.cpp World.hpp World.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_directories(${PROJECT_NAME} PUBLIC ../SFML/extlibs)

target_include_directories(${PROJECT_NAME} PUBLIC ../SFML/include)

target_link_libraries(${PROJECT_NAME} sfml-graphics)