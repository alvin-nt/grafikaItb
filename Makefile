CC = g++
CFLAGS = -g -Wall -O2 -std=c++11

DEMOS = demo_lines demo_movingLine

demo_all: $(DEMOS)

# ---Demos---
#
# all demos should be prefixed with "demo_"

demo_movingLine : demo_movingLine.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o
	$(CC) $(CFLAGS) -o $@ $^

demo_movingLine.o : demo_movingLine.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

demo_lines : demo_lines.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o
	$(CC) $(CFLAGS) -o $@  $^

demo_lines.o : demo_lines.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
# ---Dependencies---
# Naming convention:
#
# $(TARGET_NAME).o : $(TARGET_NAME).cpp $(TARGET_NAME).hpp $(HEADER_DEPENDENCIES)
#	$(CC) $(CFLAGS) -o $@ $<
#
# Example:
# foo.cpp depends on bar.hpp
#
# foo.o : foo.cpp foo.hpp bar.hpp
#	$(CC) $(CFLAGS) -c -o $@ $<

# Interface primitives

Keyboard.o : Keyboard.cpp Keyboard.hpp Types.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Rasterizer.o : Rasterizer.cpp Types.hpp Rasterizer.hpp Drawable.hpp ShapeFillable.hpp Singleton.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Shape bases

Color.o : Color.cpp Color.hpp Types.hpp Rasterizer.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Drawable.o: Drawable.cpp Drawable.hpp Rasterizer.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Shape.o : Shape.cpp Shape.hpp Types.hpp Point.hpp Drawable.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

ShapeFillable.o : ShapeFillable.cpp ShapeFillable.hpp Shape.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Shape primitives

Point.o : Point.cpp Point.hpp Types.hpp Rasterizer.hpp Color.hpp Drawable.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
Edge.o : Edge.cpp Edge.hpp Shape.hpp Point.hpp Rasterizer.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(DEMOS) *.o
