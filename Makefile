run: opengl_starter
	./opengl_starter

opengl_starter:
	g++ src/*.cc -o opengl_starter -lSDL2 -lGL
