# UNAME = $(shell uname -o)
ifeq ($(OS),Windows_NT)
	EXEEXT = .exe
	COMPILE_OPT = -lglut32 -lglu32 -lopengl32
else
	COMPILE_OPT = -lGL -lGLU -lglut
endif

all: main

main: main.o graph.o road.o line.o node.o car.o position.o
	g++ main.o graph.o road.o line.o node.o car.o position.o $(COMPILE_OPT) -o main$(EXEEXT)

main.o: main.cpp
	g++ -c -std=c++11 main.cpp
graph.o: engine/graph.cpp engine/graph.hpp
	g++ -c -std=c++11 engine/graph.cpp
road.o: engine/road.cpp engine/road.hpp
	g++ -c -std=c++11 engine/road.cpp
line.o: engine/line.cpp engine/line.hpp
	g++ -c -std=c++11 engine/line.cpp
node.o: engine/node.cpp engine/node.hpp
	g++ -c -std=c++11 engine/node.cpp
car.o: engine/car.cpp engine/car.hpp
	g++ -c -std=c++11 engine/car.cpp
position.o: engine/position.cpp engine/position.hpp
	g++ -c -std=c++11 engine/position.cpp

clean:
	rm -f *.o main$(EXEEXT)

run:
	./main$(EXEEXT)