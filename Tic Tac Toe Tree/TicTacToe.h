/**************************************************************
 * File:    TicTacToe.h
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for the TicTacToe class
 * A linked list of moves (TicTacNodes) in a game
 * 
 *************************************************************/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "TicTacNode.h"

using namespace std;

class TicTacToe
{
public:

	TicTacToe();
	~TicTacToe();

/**********************************************************************
 * Name: GetIsOver
 * PreCondition: none
 *
 * PostCondition: boolean indicating whether or not game is over
 *********************************************************************/
	bool GetIsOver();

/**********************************************************************
 * Name: GetResults
 * PreCondition: none
 *
 * PostCondition: integer value results
 *********************************************************************/
	int GetResults();

/**********************************************************************
 * Name: GetSize
 * PreCondition: none
 *
 * PostCondition: integer value size
 *********************************************************************/
	int GetSize();

/**********************************************************************
 * Name: GetStart
 * PreCondition: none
 *
 * PostCondition: pointer to starting node of game
 *********************************************************************/
	TicTacNode* GetStart();

/**********************************************************************
 * Name: GetEnd
 * PreCondition: none
 *
 * PostCondition: pointer to ending node of game
 *********************************************************************/
	TicTacNode* GetEnd();

/**********************************************************************
 * Name: ReadGame
 * PreCondition: filename that is valid
 *
 * PostCondition: moves read into game
 *********************************************************************/
	void ReadGame(string filename);

/**********************************************************************
 * Name: InsertMove
 * PreCondition: pointer to node that isn't null
 *
 * PostCondition: inserts node at the current end of the game
 *********************************************************************/
	void InsertMove(TicTacNode* n);

/**********************************************************************
 * Name: Over
 * PreCondition: pointer to node that isn't null
 *
 * PostCondition: integer of results of game thus far
 *********************************************************************/
	int Over(TicTacNode* n);

private:

	bool isOver;

	int results;

	int size;

	//first node in the game
	TicTacNode* start;
};

#endif TICTACTOE_H