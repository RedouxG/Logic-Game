#pragma once
#ifndef GAME_GLOBAL
#define GAME_GLOBAL

// -------------------------------------------------
// DEPENDENCIES
// -------------------------------------------------

// Standard libs
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

// SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// -------------------------------------------------
// MACROS
// -------------------------------------------------

// Ansi colors
# define BOLD				"\033[1m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define BLUE				"\033[34m"
# define ANSI_RESET			"\033[0m"

// ERROR and DEBUG
#define DEBUG_MSG(msg,...) fprintf(stdout, BOLD BLUE"[DEBUG](%s:%d) " ANSI_RESET BOLD msg ANSI_RESET"\n" , __FILE__, __LINE__, ##__VA_ARGS__)
#define ERROR_MSG(msg,...) fprintf(stderr, BOLD RED"[ERROR](%s:%d) " ANSI_RESET BOLD msg ANSI_RESET"\n" , __FILE__, __LINE__, ##__VA_ARGS__)

#define ERROR_EXIT(msg,...) fprintf(stderr, BOLD RED"[ERROR|EXIT](%s:%d) " ANSI_RESET BOLD msg ANSI_RESET"\n" , __FILE__, __LINE__, ##__VA_ARGS__); exit(1)
#define ERROR_RETURN(R, msg,...) fprintf(stderr, BOLD RED"[ERROR|RETURN](%s:%d) " ANSI_RESET BOLD msg ANSI_RESET"\n" , __FILE__, __LINE__, ##__VA_ARGS__); return R

// Frees a given allocated pointer and NULL's it
#define free_and_NULL(ptr) (free(ptr), ptr = NULL)

// -------------------------------------------------
// GLOBAL TYPEDEFS
// -------------------------------------------------

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

typedef struct vec2 {
    i32 x;
    i32 y;
} vec2;

#endif
