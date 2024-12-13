cmake_minimum_required(VERSION 3.24)

project(F24_Rohan_Chitrakar)

if(MINGW)
set(CMAKE_SHARED_LIBRARY_PREFIX "") 
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Meow)
add_subdirectory(myGame)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT myGame)

file(COPY Meow/assets DESTINATION ${CMAKE_BINARY_DIR}/Meow)
file(COPY myGame/assets DESTINATION ${CMAKE_BINARY_DIR}/myGame)