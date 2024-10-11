set(SOURCE_FILES
entryPoint.h
include/Meow.h
MeowApplication.h
MeowApplication.cpp
)

add_library(Meow SHARED ${SOURCE_FILES})

target_compile_definitions(Meow PRIVATE MEOW_LIB)

if(MSVC)
target_compile_definitions(Meow PUBLIC MEOW_MS_COMPILER)
endif()