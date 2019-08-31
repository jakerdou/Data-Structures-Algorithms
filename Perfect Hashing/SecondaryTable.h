/**************************************************************
 * File:    SecondaryTable.h
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for secondary table.
 * Has as many buckets as the square of how many things being inserted
 * 
 *************************************************************/

#ifndef SECONDARYTABLE_H
#define SECONDARYTABLE_H

#include "stdlib.h"
#include "SecondTableVal.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class SecondaryTable
{
private:
	int a, b, c;

	static const int p1 = 16890581;
	static const int p2 = 17027399;

	int numTries;

	int tableSize;

	SecondTableVal** SecondHashTable;

public:

/**********************************************************************
 * Name: SecondaryTable
 * PreCondition: number, square root of size
 *
 * PostCondition: SecondaryTable with hash table size of rootSize ^ 2
 *********************************************************************/
	SecondaryTable(int rootSize);


/**********************************************************************
 * Name: ~SecondaryTable
 * PreCondition: none
 *
 * PostCondition: deleted SecondaryTable
 *********************************************************************/
	~SecondaryTable();


/**********************************************************************
 * Name: GetNumTries
 * PreCondition: none
 *
 * PostCondition: integer of number of hash functions tried
 *********************************************************************/
	int GetNumTries();


/**********************************************************************
 * Name: SecondaryTable
 * PreCondition: vector of second table vals
 *
 * PostCondition: second hash table with all items inserted
 *********************************************************************/
	void PopulateSecondTable(vector<SecondTableVal*> items);


/**********************************************************************
 * Name: SecondaryHash
 * PreCondition: string, integer
 *
 * PostCondition: integer of index of string according to hash function
 * and seed
 *********************************************************************/
	int SecondHash(string str, int seed);


/**********************************************************************
 * Name: GetSecondG
 * PreCondition: string to be hashed, seed
 *
 * PostCondition: integer G value of hash function
 *********************************************************************/
	unsigned long long GetSecondG(string str, int seed);


/**********************************************************************
 * Name: GetSecondH
 * PreCondition: string to be hashed, seed
 *
 * PostCondition: integer H value of hash function
 *********************************************************************/
	int GetSecondH(unsigned long long g);


/**********************************************************************
 * Name: SecondInsert
 * PreCondition: second table val to be inserted, seed, index
 *
 * PostCondition: sv inserted at correct location
 *********************************************************************/
	bool SecondInsert(SecondTableVal* sv, int seed, int index);


/**********************************************************************
 * Name: ClearTable
 * PreCondition: none
 *
 * PostCondition: second hash table with no items
 *********************************************************************/
	void ClearTable();


/**********************************************************************
 * Name: SecondOutputSearch
 * PreCondition: output stream and string to be searched
 *
 * PostCondition: output stream of info of string in table
 *********************************************************************/
	ostream& SecondOutputSearch(ostream& os, string str);
};

#endif