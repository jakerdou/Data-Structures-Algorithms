/**************************************************************
 * File:    TicTacToe.cpp
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the TicTacToe class
 * function declarations and member variables are held
 * in the .h file
 *************************************************************/

#include "TicTacToe.h"
#include <fstream>
#include <map>
#include <string>


TicTacToe::TicTacToe()
{
	//initializes variables to correct values
	size = 0;
	results = 0;
	isOver = false;
}

TicTacToe::~TicTacToe()
{
}

bool TicTacToe::GetIsOver()
{
	return this->isOver;
}

int TicTacToe::GetResults()
{
	return this->results;
}

int TicTacToe::GetSize()
{
	return size;
}

TicTacNode * TicTacToe::GetStart()
{
	return this->start;
}

TicTacNode * TicTacToe::GetEnd()
{
	//starts at the beginning
	TicTacNode* end = this->GetStart();

	//iterates through until the cursor reaches the end and then returns that
	for (int i = 1; i < this->size; i++)
	{
		end = (end->GetChildren()).at(0);
	}
	return end;
}

void TicTacToe::ReadGame(string filename)
{
	//opens input stream with filename
	ifstream gameStream;
	gameStream.open(filename);
	
	//buffers inputs from input stream
	string str;

	//while loop executes while the game is not yet done
	while (results == 0)
	{ 
		map<int, char> board;
		
		//for loop that iterates through the file and adds the elements at the correct spot on the board
		for (int i = 0; i < 9; i++)
		{
			//after 3rd, 6th, and 9th element there is a space that needs 
			//to extracted from the filestream by this if statement
			if (i % 3 == 0)
			{
				gameStream >> str;
			}
			board.insert(pair<int, char>(i, str.at(i%3)));
		}

		//after each board there is a newline that needs to be extracted by this getline
		getline(gameStream, str);

		//makes node on heap so it will continue to be accessible after the function stops executing
		TicTacNode* move = new TicTacNode;

		//sets board of the node to the one just extracted from the file
		move->SetBoard(board);

		//adds this 'move' (node) to the game
		this->InsertMove(move);

		//when the game has reached 5 moves, it is possible for a player to have won,
		//this if statement checks if the game is over
		if (this->size > 5)
		{
			this->results = this->Over(move);
		}
	}
}

void TicTacToe::InsertMove(TicTacNode* n)
{
	//first checks base case of size = 0
	if (this->size == 0)
	{
		this->start = n;
	}
	else
	{
		TicTacNode* cursor = this->start;

		//gets the end of the list and adds the move as a child
		cursor = this->GetEnd();
		cursor->AddChild(n);
	}
	(this->size)++;
}

int TicTacToe::Over(TicTacNode* n)
{
	//checks if game is over and returns correct number

	//X win
	if (n->XWin())
	{
		this->isOver = true;
		return 1;
	}

	//O win
	else if (n->OWin())
	{
		this->isOver = true;
		return 2;
	}

	//if the size is 10 and nobody has won, then it's a draw
	else if (this->size == 10)
	{
		this->isOver = true;
		return 3;
	}

	//game is still going
	else
	{
		this->isOver = false;
		return 0;
	}
}


