/**************************************************************
 * File:    Driver.cpp
 * Project: CSCE 221 - Project 2
 * Author : James Robinson
 * Date   : 3/13/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * This is the driver file for Project 2. It will take in 
 * command line arguments as filenames that are TicTacToe
 * games. Those games will then be added to the TicTacTrie.
 * This file will also output some statistics about the games
 * and the trie.
 *************************************************************/

#include <iostream>
#include <map>
#include "TicTacNode.h"
#include"TicTacToe.h"
#include"TicTacTrie.h"

int main(int argc, char *argv[])
{
	using namespace std;

	TicTacTrie tree;

	//iterates through command line arguments and reads in the files as games and adds them to tree
	for (int i = 1; i < argc; i++)
	{

		TicTacToe game;

		//reads game
		game.ReadGame(argv[i]);

		cout << "======================\n";
		cout << "Reading: " << argv[i] << endl;
		cout << "======================\n";

		//gets results of game and outputs accordingly
		switch (game.GetResults())
		{
		case 1:
			cout << "Player X wins!\n";
			break;
		case 2:
			cout << "Player O wins!\n";
			break;
		case 3:
			cout << "The game was a draw!\n";
			break;
		}

		//outputs final move of game
		cout << "Game Board:\n";
		cout << *(game.GetEnd());
		cout << endl;

		//adds game to tree
		tree.addGame(game);
	}

	//outputs final values of trie statistics
	cout << "Final Trie Statistics\n";
	cout << "======================\n";
	cout << "Player X Wins: " << tree.GetXWins() << endl;
	cout << "Player O Wins: " << tree.GetOWins() << endl;
	cout << "Draws: " << tree.GetDraws() << endl;
	cout << "Trie Size: " << tree.GetSize() << endl;
}