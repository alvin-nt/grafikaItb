CC = g++
CFLAGS = -g -Wall -O2 -std=c++11 -m32

DEMOS = demo_lines demo_movingLine demo_rectangle demo_ellipse demo_triangle demo_cruiser demo_parachute demo_ball demo_peta demo_cube demo_helicopter demo_scene4 demo_scene5 demo_allScene demo_writetext

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
	
demo_rectangle : demo_rectangle.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o
	$(CC) $(CFLAGS) -o $@ $^

demo_rectangle.o : demo_rectangle.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

demo_cube: demo_cube.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Cube.o
	$(CC) $(CFLAGS) -o $@ $^
	
demo_cube.o: demo_cube.cpp
	$(CC) $(CFLAGS) -c -o  $@ $^
	
demo_triangle : demo_triangle.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Triangle.o
	$(CC) $(CFLAGS) -o $@ $^

demo_triangle.o : demo_triangle.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	
	
demo_ellipse : demo_ellipse.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Ellipse.o
	$(CC) $(CFLAGS) -o $@ $^	

demo_ellipse.o : demo_ellipse.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

demo_parachute : demo_parachute.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Parachute.o
	$(CC) $(CFLAGS) -o $@ $^	

demo_parachute.o : demo_parachute.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

demo_ball : demo_ball.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Ball.o
	$(CC) $(CFLAGS) -o $@ $^	

demo_ball.o : demo_ball.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	
	
demo_cruiser : demo_cruiser.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Ellipse.o
	$(CC) $(CFLAGS) -o $@ $^

demo_cruiser.o : demo_cruiser.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	
	
demo_peta : demo_peta.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Peta.o ViewPort.o Rectangle.o
	$(CC) $(CFLAGS) -o $@ $^	

demo_peta.o : demo_peta.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

demo_helicopter : demo_helicopter.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Helicopter.o
	$(CC) $(CFLAGS) -o $@ $^

demo_helicopter.o : demo_helicopter.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	
	
demo_scene4: demo_scene4.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Cube.o Cruiser.o Ellipse.o
	$(CC) $(CFLAGS) -o $@ $^
	
demo_scene4.o : demo_scene4.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	
	
demo_scene5: demo_scene5.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Cruiser.o Ellipse.o Parachute.o Helicopter.o
	$(CC) $(CFLAGS) -o $@ $^
	
demo_scene5.o : demo_scene5.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

demo_writetext : demo_writetext.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o writetext.o
	$(CC) $(CFLAGS) -o $@ $^	

demo_writetext.o : demo_writetext.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

main_kapalPesawat : main_kapalPesawat.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Ellipse.o
	$(CC) $(CFLAGS) -o $@ $^

main_kapalPesawat.o : main_kapalPesawat.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	
	
demo_allScene: demo_allScene.o Keyboard.o Rasterizer.o Edge.o Point.o Color.o Shape.o ShapeFillable.o Drawable.o Rectangle.o Cube.o Cruiser.o Ellipse.o Peta.o ViewPort.o Helicopter.o Parachute.o writetext.o
	$(CC) $(CFLAGS) -o $@ $^
	
demo_allScene.o : demo_allScene.cpp
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

Rectangle.o : Rectangle.cpp Rectangle.hpp ShapeFillable.hpp Edge.hpp Rasterizer.hpp Point.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Cube.o : Cube.cpp Cube.hpp Rectangle.hpp ShapeFillable.hpp Edge.hpp Rasterizer.hpp Point.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
Ellipse.o : Ellipse.cpp Ellipse.hpp ShapeFillable.hpp Edge.hpp Rasterizer.hpp Point.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Triangle.o : Triangle.cpp Triangle.hpp ShapeFillable.hpp Edge.hpp Rasterizer.hpp Point.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
Parachute.o : Parachute.cpp Parachute.hpp Drawable.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Helicopter.o : Helicopter.cpp Helicopter.hpp Rectangle.hpp Drawable.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Ball.o : Ball.cpp Ball.hpp Drawable.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Peta.o : Peta.cpp Peta.hpp Drawable.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
ViewPort.o : ViewPort.cpp ViewPort.hpp Peta.hpp Drawable.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
Cruiser.o : Cruiser.cpp Cruiser.hpp Ellipse.hpp Rectangle.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
writetext.o : writetext.cpp writetext.hpp Drawable.hpp Edge.hpp Point.hpp Color.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean :
	rm -rf $(DEMOS) *.o
