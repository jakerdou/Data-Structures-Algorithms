/**************************************************************
 * File:    TicTacTrie.cpp
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the TicTacTrie class
 * function declarations and member variables are held
 * in the .h file
 *************************************************************/

#include "TicTacTrie.h"

TicTacTrie::TicTacTrie()
{
	//sets variables as correct values
	this->draws = 0;
	this->xWins = 0;
	this->oWins = 0;
	this->size = 1;
	this->root = nullptr;

}

TicTacTrie::~TicTacTrie()
{
}

int TicTacTrie::GetXWins()
{
	return xWins;
}

int TicTacTrie::GetOWins()
{
	return oWins;
}

int TicTacTrie::GetDraws()
{
	return draws;
}

int TicTacTrie::GetSize()
{
	return size;
}

void TicTacTrie::addGame(TicTacToe t)
{
	//sets root if it is not already
	if (root == nullptr)
	{
		root = new TicTacNode;
	}

	//sets node to add as second node in game
	TicTacNode* nodeToAdd = ((t.GetStart())->GetChildren()).at(0);

	//treeCursor will traverse through the tree and be the node in the tree that we will be looking
	//to add nodeToAdd to
	TicTacNode* treeCursor = root;

	//used to keep track of number of matching nodes found so as to accurately update size of tree
	int matchesFound = 1;

	//while loop iterates through moves in game while matches for every move have not been found
	while (matchesFound != t.GetSize())
	{
		//keeps track of if not a match has been found for this individual move
		bool matchFound = false;

		//for loop that iterates through children of node already in the tree
		for (int i = 0; i < (treeCursor->GetChildren()).size(); i++)
		{
			//if match found
			if (*nodeToAdd == *((treeCursor->GetChildren()).at(i)))
			{
				if (matchesFound != t.GetSize() - 1)
				{
					//updates cursor and the node to add next
					treeCursor = (treeCursor->GetChildren()).at(i);
					nodeToAdd = (nodeToAdd->GetChildren()).at(0);
				}
				
				matchFound = true;
				matchesFound++;
			}
		}

		//if a match wasn't found for current node to add then we add it, update the tree, and exit
		if (!matchFound)
		{
			//adds node with children and all so as to create new branch in tree
			treeCursor->AddChild(nodeToAdd);

			//updates size of tree
			this->size = this->size + (t.GetSize() - matchesFound);

			//updates results of tree
			switch (t.GetResults())
			{
			case 1:
				xWins++;
				break;
			case 2:
				oWins++;
				break;
			case 3:
				draws++;
				break;
			default:
				break;
			}
			return;
		}
	}

	/*this switch statement executes if all moves in the game being added have matches already
	in the tree, this will update the resuts of the tree*/
	switch (t.GetResults())
	{
	case 1:
		xWins++;
		break;
	case 2:
		oWins++;
		break;
	case 3:
		draws++;
		break;
	default:
		break;
	}
	return;
}
