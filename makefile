# UNAME = $(shell uname -o)
ifeq ($(OS),Windows_NT)
	EXEEXT = .exe
	COMPILE_OPT = -lglut32 -lglu32 -lopengl32
else
	COMPILE_OPT = -lGL -lGLU -lglut
endif

all: main

main: main.o graph.o edge.o node.o position.o
	g++ *.o $(COMPILE_OPT) -o main$(EXEEXT)

main.o: main.cpp
	g++ -c main.cpp
graph.o: engine/graph.cpp
	g++ -c engine/graph.cpp
edge.o: engine/edge.cpp
	g++ -c engine/edge.cpp
node.o: engine/node.cpp
	g++ -c engine/node.cpp
position.o: engine/position.cpp
	g++ -c engine/position.cpp

clean:
	rm -f *.o main$(EXEEXT)

run:
	./main$(EXEEXT)