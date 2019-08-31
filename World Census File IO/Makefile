driver.out: Driver.o Country.o Continent.o
	g++ -Wall -std=c++11 Driver.o Country.o Continent.o -o driver.out
Driver.o: Driver.cpp Country.h Continent.h
	g++ -std=c++11 -Wall -c Driver.cpp Country.h Continent.h
Country.o: Country.cpp Country.h
	g++ -std=c++11 -Wall -c Country.cpp
Continent.o: Continent.cpp Continent.h Country.h
	g++ -std=c++11 -Wall -c Continent.cpp
clean:
	rm *.o *.out
run:
	./driver.out
	