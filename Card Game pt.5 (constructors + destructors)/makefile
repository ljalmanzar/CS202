main: shuffler6.o stringFuncs.o cardClass.o playerClass.o
	g++ shuffler6.o stringFuncs.o cardClass.o playerClass.o
shuffler6.o: shuffler6.cpp 
	g++ -c shuffler6.cpp
stringFuncs.o: stringFuncs.cpp stringFuncs.h
	g++ -c stringFuncs.cpp
cardClass.o: cardClass.cpp cardClass.h
	g++ -c cardClass.cpp
playerClass.o: playerClass.cpp playerClass.h
	g++ -c playerClass.cpp
clean:
	rm shuffler6.o stringFuncs.o cardClass.o playerClass.o
