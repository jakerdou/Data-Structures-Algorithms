Project4.out: Project4.o PrimaryTable.o SecondaryTable.o
	g++ -std=c++11 -Wall Project4.o PrimaryTable.o SecondaryTable.o -o Project4.out
Project4.o: Project4.cpp PrimaryTable.h SecondaryTable.h
	g++ -std=c++11 -Wall -c Project4.cpp PrimaryTable.h SecondaryTable.h
PrimaryTable.o: PrimaryTable.cpp PrimaryTable.h
	g++ -std=c++11 -Wall -c PrimaryTable.cpp
SecondaryTable.o: SecondaryTable.cpp SecondaryTable.h
	g++ -std=c++11 -Wall -c SecondaryTable.cpp

clean:
	rm *.o *.out
run:
	./Project4.out $(FILE)