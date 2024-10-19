set(SOURCE_FILES
entryPoint.h
include/Meow.h
MeowApplication.h
MeowApplication.cpp
)

add_library(Meow SHARED ${SOURCE_FILES})

target_compile_definitions(Meow PRIVATE MEOW_LIB)
target_compile_definitions(Meow PUBLIC
$<$<CONFIG:Debug>:MEOW_DEBUG=2>
$<$<CONFIG:RelWithDebInfo>:MEOW_DEBUG=1>)

if(MSVC)
target_compile_definitions(Meow PUBLIC MEOW_MS_COMPILER)
endif()

target_precompile_headers(Meow PRIVATE pch.h)