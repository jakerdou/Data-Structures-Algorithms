driver.out: Driver.o TicTacNode.o TicTacToe.o TicTacTrie.o
	g++ -std=c++11 -Wall Driver.o TicTacNode.o TicTacToe.o TicTacTrie.o -o driver.out
Driver.o: Driver.cpp TicTacNode.h TicTacToe.h TicTacTrie.h
	g++ -std=c++11 -Wall -c Driver.cpp TicTacNode.h TicTacToe.h TicTacTrie.h
TicTacNode.o: TicTacNode.cpp TicTacNode.h
	g++ -std=c++11 -Wall -c TicTacNode.cpp
TicTacToe.o: TicTacToe.cpp TicTacToe.h TicTacNode.h
	g++ -std=c++11 -Wall -c TicTacToe.cpp
TicTacTrie.o: TicTacTrie.cpp TicTacTrie.h TicTacNode.h TicTacToe.h
	g++ -std=c++11 -Wall -c TicTacTrie.cpp
clean:
	rm *.o *.out
run:
	./driver.out $(FILE)

driver.out: Driver.o TicTacNode.o TicTacToe.o TicTacTrie.o
	g++ -std=c++11 -Wall Driver.o TicTacNode.o TicTacToe.o TicTacTrie.o -o driver.out
Driver.o: Driver.cpp TicTacNode.h TicTacToe.h TicTacTrie.h
	g++ -std=c++11 -Wall -c Driver.cpp TicTacNode.h TicTacToe.h TicTacTrie.h
TicTacNode.o: TicTacNode.cpp TicTacNode.h
	g++ -std=c++11 -Wall -c TicTacNode.cpp
TicTacToe.o: TicTacToe.cpp TicTacToe.h TicTacNode.h
	g++ -std=c++11 -Wall -c TicTacToe.cpp
TicTacTrie.o: TicTacTrie.cpp TicTacTrie.h TicTacNode.h TicTacToe.h
	g++ -std=c++11 -Wall -c TicTacTrie.cpp