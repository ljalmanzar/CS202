main: qtest.o classes.o
	g++ qtest.o classes.o
qtest.o: qtest.cpp
	g++ -c qtest.cpp
classes.o: classes.cpp classes.h
	g++ -c classes.cpp 
clean:
	rm classes.o qtest.o
