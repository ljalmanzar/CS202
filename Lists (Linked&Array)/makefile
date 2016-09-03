main: listN-Main.o listN.o
	g++ listN-Main.o listN.o
listN-Main.o: listN-Main.cpp 
	g++ -c listN-Main.cpp
listN.o: listN.cpp listN.h
	g++ -c listN.cpp
clean:
	rm listN.o listN-Main.o
