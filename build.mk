# ----------------------------------------------------
# Makefile build
# ----------------------------------------------------

.ONESHELL: # Every line in one shell

# ----------------------------------------------------
# VARIABLES
# ----------------------------------------------------

CC=gcc
FLAGS=-Wall -Wextra -g3 -O -Werror
LIBS=-L src/lib
LINK=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SRC=src/*c src/game/*.c
OUT_FILE=-o build/build.exe

# ----------------------------------------------------
# BUILD
# ----------------------------------------------------

all: main_build

# Build
main_build: pre_build
	$(CC) -I src/include $(LIBS) $(FLAGS) $(SRC) $(OUT_FILE) $(LINK)


# Check if build folders exist before building
pre_build:
ifeq ($(OS), Windows_NT)
# Windows
	if not exist "build" mkdir "build"
else
# Linux
	if ! [ -d "build" ]; then mkdir build; fi
endif
