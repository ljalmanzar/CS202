main: stacktest.o classes.o
	g++ stacktest.o classes.o
stacktest.o: stacktest.cpp
	g++ -c stacktest.cpp
classes.o: classes.h classes.cpp
	g++ -c classes.cpp
clean:
	rm classes.o stacktest.o
