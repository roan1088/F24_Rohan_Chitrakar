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

#if MEOW_DEBUG==2
#define MEOW_LOG(x) std::cout << x << std::endl;
#define MEOW_ERROR(x) std::cout << x << std::endl;
#elif MEOW_DEBUG==1
#define MEOW_LOG(x)
#define MEOW_ERROR(x) std::cout << x << std::endl;
#else
#define MEOW_LOG(x)
#define MEOW_ERROR(x)
#endif