/**************************************************************
 * File:    TicTacNode.cpp
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the TicTacNode class
 * function declarations and member variables are held 
 * in the .h file
 *************************************************************/

#include "TicTacNode.h"

TicTacNode::TicTacNode()
{
	this->parent = nullptr;

	//next lines makes map of all dashes (-) then set the board as that
	map<int, char> setMap;

	for (int i = 0; i < 9; i++)
	{
		setMap.insert(pair<int, char>(i, '-'));
	}
	this->SetBoard(setMap);
}

TicTacNode::~TicTacNode()
{
}

void TicTacNode::AddChild(TicTacNode* inputChild)
{
	//sets child as inputted child and makes the parent of the inputted this node
	inputChild->SetParent(this);
	children.push_back(inputChild);
}

void TicTacNode::SetParent(TicTacNode* inputParent)
{
	this->parent = inputParent;
}

void TicTacNode::SetBoard(map<int, char> inputBoard)
{
	this->board = inputBoard;
}

bool TicTacNode::HasChildren()
{
	//returns boolean based on if node has children or not
	if (children.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

vector<TicTacNode*> TicTacNode::GetChildren()
{
	return this->children;
}

void TicTacNode::operator=(TicTacNode n)
{
	//clears board if it is not already empty
	if (!((this->board).empty()))
	{
		(this->board).clear();
	}
	
	//one by one assigns elements of inputted node's board to this node's board
	for (int i = 0; i < 9; i++)
	{
		(this->board).insert(pair<int, char>(i, (n.board).at(i)));
		
	}
}

bool TicTacNode::operator==(TicTacNode n)
{
	//checks value for similarity one by one and returns false if one is dissimilar
	for (int i = 0; i < 9; i++)
	{
		if ((this->board).at(i) != (n.board).at(i))
		{
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream & os, const TicTacNode n)
{
	for (int i = 0; i < 9; i++)
	{
		//outputs element of board at iterator
		os << n.board.at(i);

		/*outputs newline if after 3rd, 6th, or 9th element so it's formatted like a
		tic tac toe board*/
		if ((i + 1) % 3 == 0)
		{
			os << endl;
		}
	}

	return os;
}

bool TicTacNode::XWin()
{
	//individually checks all board combinations for 3 Xs making a line

	//element 4 is middle square
	if (board.at(4) == 'X')
	{
		//checks left to right diagonal
		if (board.at(0) == 'X')
		{
			if (board.at(8) == 'X')
			{
				return true;
			}
		}
		//checks right to left diagonal
		if (board.at(2) == 'X')
		{
			if (board.at(6) == 'X')
			{
				return true;
			}
		}
		//checks middle row
		if (board.at(3) == 'X')
		{
			if (board.at(5) == 'X')
			{
				return true;
			}
		}
		//checks middle column
		if (board.at(1) == 'X')
		{
			if (board.at(7) == 'X')
			{
				return true;
			}
		}
	}
	//element 0 is top left square
	if (board.at(0) == 'X')
	{
		//checks top row
		if (board.at(1) == 'X')
		{
			if (board.at(2) == 'X')
			{
				return true;
			}
		}
		//checks left column
		if (board.at(3) == 'X')
		{
			if (board.at(6) == 'X')
			{
				return true;
			}
		}
	}
	//element 8 is bottom right square
	if (board.at(8) == 'X')
	{
		//checks bottom row
		if (board.at(7) == 'X')
		{
			if (board.at(6) == 'X')
			{
				return true;
			}
		}
		//checks right column
		if (board.at(5) == 'X')
		{
			if (board.at(2) == 'X')
			{
				return true;
			}
		}
	}
	return false;
}

bool TicTacNode::OWin()
{
	//individually checks all board combinations for 3 Os making a line

	//element 4 is middle square
	if (board.at(4) == 'O')
	{
		//checks left to right diagonal
		if (board.at(0) == 'O')
		{
			if (board.at(8) == 'O')
			{
				return true;
			}
		}
		//checks right to left diagonal
		if (board.at(2) == 'O')
		{
			if (board.at(6) == 'O')
			{
				return true;
			}
		}
		//checks middle row
		if (board.at(3) == 'O')
		{
			if (board.at(5) == 'O')
			{
				return true;
			}
		}
		//checks middle column
		if (board.at(1) == 'O')
		{
			if (board.at(7) == 'O')
			{
				return true;
			}
		}
	}
	//element 0 is top left square
	if (board.at(0) == 'O')
	{
		//checks top row
		if (board.at(1) == 'O')
		{
			if (board.at(2) == 'O')
			{
				return true;
			}
		}
		//checks left column
		if (board.at(3) == 'O')
		{
			if (board.at(6) == 'O')
			{
				return true;
			}
		}
	}
	//element 8 is bottom right square
	if (board.at(8) == 'O')
	{
		//checks bottom row
		if (board.at(7) == 'O')
		{
			if (board.at(6) == 'O')
			{
				return true;
			}
		}
		//checks right column
		if (board.at(5) == 'O')
		{
			if (board.at(2) == 'O')
			{
				return true;
			}
		}
	}
	return false;
}
