/**************************************************************
 * File:    TicTacTrie.h
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for the TicTacTrie class
 * A trie that will read in individual games and hold the nodes
 * according to the trie structure
 *************************************************************/

#ifndef TICTACTRIE_H
#define TICTACTRIE_H

#include <iostream>
#include <vector>
#include <map>
#include "TicTacToe.h"
#include "TicTacNode.h"

using namespace std;

class TicTacTrie
{
public:

	TicTacTrie();
	~TicTacTrie();

/**********************************************************************
 * Name: GetXWins
 * PreCondition: none
 *
 * PostCondition: returns number of X wins in tree
 *********************************************************************/
	int GetXWins();

/**********************************************************************
 * Name: GetOWins
 * PreCondition: none
 *
 * PostCondition: returns number of O wins in tree
 *********************************************************************/
	int GetOWins();

/**********************************************************************
 * Name: GetDraws
 * PreCondition: none
 *
 * PostCondition: returns number of Draws in tree
 *********************************************************************/
	int GetDraws();

/**********************************************************************
 * Name: GetSize
 * PreCondition: none
 *
 * PostCondition: returns size of tree
 *********************************************************************/
	int GetSize();

/**********************************************************************
 * Name: addGame
 * PreCondition: TicTacToe game with nodes that are formatted properly
 * and that have an end
 *
 * PostCondition: adds nodes in game to this tree in correct way
 * according to trie structure
 *********************************************************************/
	void addGame(TicTacToe t);

private:

	int xWins;

	int oWins;

	int draws;

	int size;

	//first node in trie
	TicTacNode* root;
};

#endif TICTACTRIE_H
