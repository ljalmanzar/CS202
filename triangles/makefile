main: test.o triangle.o
	g++ test.o triangle.o
test.o: test.cpp
	g++ -c test.cpp
triangle.o: triangle.h triangle.cpp
	g++ -c triangle.cpp
clean: 
	rm test.o triangle.o

