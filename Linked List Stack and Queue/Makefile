driver.out: Driver.o Node221.o Stack221.o Queue221.o
	g++ -Wall -std=c++11 Driver.o Node221.o Stack221.o Queue221.o -o driver.out
Driver.o: Driver.cpp List221.h Stack221.h Queue221.h Node221.h Exceptions221.h
	g++ -std=c++11 -Wall -c Driver.cpp List221.h Stack221.h Queue221.h Node221.h Exceptions221.h
Node221.o: Node221.cpp Node221.h
	g++ -std=c++11 -Wall -c Node221.cpp
Stack221.o: Stack221.cpp Stack221.h List221.h Node221.h
	g++ -std=c++11 -Wall -c Stack221.cpp
Queue221.o: Queue221.cpp Queue221.h List221.h Node221.h
	g++ -std=c++11 -Wall -c Queue221.cpp
clean:
	rm *.o *.out
run:
	./driver.out