set(SOURCE_FILES
myGame.cpp
MyGameApplication.cpp
Timer.cpp
Scorer.cpp
)

add_executable(myGame ${SOURCE_FILES})

include_directories(../Meow/include)

target_link_libraries(myGame Meow)