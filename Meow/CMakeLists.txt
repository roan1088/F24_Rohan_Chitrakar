set(SOURCE_FILES
entryPoint.h
include/Meow.h
MeowApplication.h
MeowApplication.cpp
MeowWindow.cpp
WindowImpl.h
codeGLFW/WindowGLFW.cpp
Image.cpp
ImageImpl.h
codeOpenGL/OpenGLImage.cpp
Shaders.cpp
ShadersImpl.h
codeOpenGL/OpenGLShaders.cpp
Renderer.cpp
RendererImpl.h
codeOpenGL/OpenGLRenderer.cpp
MeowEvents.cpp
)

add_library(Meow SHARED ${SOURCE_FILES})

include_directories(.)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

target_compile_definitions(Meow PRIVATE MEOW_LIB)
target_compile_definitions(Meow PUBLIC
$<$<CONFIG:Debug>:MEOW_DEBUG=2>
$<$<CONFIG:RelWithDebInfo>:MEOW_DEBUG=1>)
target_compile_definitions(Meow PRIVATE MEOW_GLFW)
target_compile_definitions(Meow PUBLIC MEOW_OPENGL)

if(MSVC)
target_compile_definitions(Meow PUBLIC MEOW_MS_COMPILER)
endif()

target_precompile_headers(Meow PRIVATE pch.h)

target_link_libraries(Meow glfw)
target_link_libraries(Meow glad)
target_link_libraries(Meow stbi)