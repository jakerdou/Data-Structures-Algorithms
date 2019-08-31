/**************************************************************
 * File:    TicTacNode.h
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for the TicTacNode class
 * holds individual moves of the TicTacToe games
 * Nodes are also held in the tree as a trie
 *************************************************************/

#ifndef TICTACNODE_H
#define TICTACNODE_H

#include <iostream>
#include <vector>
#include <map>
#include <ostream>

using namespace std;

class TicTacNode
{
public:

	TicTacNode();
	~TicTacNode();

/**********************************************************************
 * Name: AddChild
 * PreCondition: pointer to node
 *
 * PostCondition: adds that pointer to this nodes vector of children
 *********************************************************************/
	void AddChild(TicTacNode* inputChild);

/**********************************************************************
 * Name: SetParent
 * PreCondition: pointer to node
 *
 * PostCondition: sets that pointer to this nodes parent
 *********************************************************************/
	void SetParent(TicTacNode* inputParent);

/**********************************************************************
 * Name: SetBoard
 * PreCondition: map<int, char> that has numbers 1-9 and is not empty
 *
 * PostCondition: sets this node's board as that map
 *********************************************************************/
	void SetBoard(map<int, char> inputBoard);

/**********************************************************************
 * Name: HasChildren
 * PreCondition: none
 *
 * PostCondition: boolean indicating whether or not is has children
 *********************************************************************/
	bool HasChildren();

/**********************************************************************
 * Name: GetChildren
 * PreCondition: none
 *
 * PostCondition: returns this node's vector of children
 *********************************************************************/
	vector<TicTacNode*> GetChildren();

/**********************************************************************
 * Name: operator=
 * PreCondition: a node that is not null
 *
 * PostCondition: assigns this node's board as equal to the input node
 *********************************************************************/
	void operator=(TicTacNode n);

/**********************************************************************
 * Name: operator==
 * PreCondition: a node that is not null
 *
 * PostCondition: boolean indicating whether this node and the inputted
 * are equal
 *********************************************************************/
	bool operator==(TicTacNode n);

/**********************************************************************
 * Name: operator<<
 * PreCondition: a reference to an ostream and a node that isn't null
 *
 * PostCondition: output stream of inputted node's game board
 *********************************************************************/
	friend ostream& operator<<(ostream& os, const TicTacNode n);

/**********************************************************************
 * Name: XWin
 * PreCondition: none
 *
 * PostCondition: boolean indicating whether or not X wins
 *********************************************************************/
	bool XWin();

/**********************************************************************
 * Name: OWin
 * PreCondition: none
 *
 * PostCondition: boolean indicating whether or not O wins
 *********************************************************************/
	bool OWin();

private:
	//move that comes before this one
	TicTacNode* parent;

	//moves that come after this one
	vector<TicTacNode*> children;

	map<int, char> board;
};

#endif TICTACNODE_H