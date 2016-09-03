main: shuffler5.o stringfuncs.o
	g++ shuffler5.o stringfuncs.o
shuffler5.o: shuffler5.cpp 
	g++ -c shuffler5.cpp
stringfuncs.o: stringfuncs.cpp stringfuncs.h
	g++ -c stringfuncs.cpp
clean:
	rm shuffler5.o stringfuncs.o
