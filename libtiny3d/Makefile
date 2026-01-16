CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Iinclude

# Object files for the library
LIB_OBJS = src/canvas.o src/math3d.o src/renderer.o

# The static library
LIB = build/libtiny3d.a

# Demos
DEMOS = build/clock_face build/cube_demo build/soccer_demo build/main

# Ensure build directory exists
$(shell mkdir -p build)

# Default: build all demos
all: $(DEMOS)

# Build the static library
$(LIB): $(LIB_OBJS)
	ar rcs $(LIB) $(LIB_OBJS)

# Build each demo, linking against the static library
build/clock_face: demo/clock_face.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -Lbuild -ltiny3d -lm

build/cube_demo: demo/cube_demo.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -Lbuild -ltiny3d -lm

build/soccer_demo: demo/soccer_demo.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -Lbuild -ltiny3d -lm

build/main: demo/main.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -Lbuild -ltiny3d -lm

# Pattern rule for compiling object files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf build/*.o build/*.a build/clock_face build/cube_demo build/soccer_demo build/main *.ppm *.gif

.PHONY: all clean
