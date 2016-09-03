main: listN-Main.o classes.o
	g++ listN-Main.o classes.o
listN-Main.o: listN-Main.cpp 
	g++ -c listN-Main.cpp
classes.o: classes.cpp classes.h
	g++ -c classes.cpp
clean:
	rm classes.o listN-Main.o
