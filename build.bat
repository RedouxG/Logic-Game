@echo off
REM ----------------------------------------
REM BUILD BATCH FOR WINDOWS
REM ----------------------------------------

REM ----------------------------------------
REM BUILD
REM ----------------------------------------
if not exist "build" mkdir "build"

set FLAGS=-Wall -Wextra -g3 -O -Werror
set LIBS=-L src/lib
set LINK=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
set SRC=src/*c src/game/*.c
set OUT_FILE=-o build/build.exe

@echo on
gcc -I src/include %LIBS% %OUT_FILE% %SRC% %LINK%
