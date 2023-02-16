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
LINK=-lSDL2main -lSDL2 -lSDL2_image
SRC=src/*c src/game/*.c
OUT_FILE=-o build/build.exe

# ----------------------------------------------------
# BUILD
# ----------------------------------------------------

all: main_build

# Build
main_build: pre_build
ifeq ($(OS), Windows_NT)
# Windows
	$(CC) -I src/include $(LIBS) $(FLAGS) $(SRC) $(OUT_FILE) -lmingw32 $(LINK) 
else
# Linux
	$(CC) -I src/include $(LIBS) $(FLAGS) $(SRC) $(OUT_FILE) $(LINK)
endif

# Check if build folders exist before building
pre_build:
ifeq ($(OS), Windows_NT)
# Windows
	if not exist "build" mkdir "build"
else
# Linux
	if ! [ -d "build" ]; then mkdir build; fi
endif
