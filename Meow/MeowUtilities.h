#pragma once

#ifdef MEOW_MS_COMPILER
#ifdef MEOW_LIB
#define MEOW_API __declspec(dllexport)
#else
#define MEOW_API __declspec(dllimport)
#endif
#else
#define MEOW_API
#endif