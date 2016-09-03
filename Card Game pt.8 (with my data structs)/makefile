main: project11.o classes.o
	g++ project11.o classes.o
project11.o: project11.cpp 
	g++ -c project11.cpp
classes.o: classes.cpp classes.h
	g++ -c classes.cpp
clean:
	rm project11.o classes.o
