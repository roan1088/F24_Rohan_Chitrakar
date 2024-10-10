add_executable(myGame myGame.cpp)

include_directories(../Meow/include)

target_link_libraries(myGame Meow)