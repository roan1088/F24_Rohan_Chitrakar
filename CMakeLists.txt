cmake_minimum_required(VERSION 3.24)

project(F24_Rohan_Chitrakar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(glfw)
add_subdirectory(Meow)
add_subdirectory(myGame)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT myGame)