main: test.o Stack1.o
	g++ test.o Stack1.o
test.o: test.cpp 
	g++ -c test.cpp
Stack1.o: Stack1.cpp Stack.h
	g++ -c Stack1.cpp
clean:
	rm Stack1.o test.o
