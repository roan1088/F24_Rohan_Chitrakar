set(SOURCE_FILES
entryPoint.h
include/Meow.h
MeowApplication.h
MeowApplication.cpp
)

add_library(Meow SHARED ${SOURCE_FILES})