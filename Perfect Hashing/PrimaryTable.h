/**************************************************************
 * File:    PrimaryTable.h
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for primary table.
 * Has as many buckets as things being inserted
 * 
 *************************************************************/

#ifndef PRIMARYTABLE_H
#define PRIMARYTABLE_H

#include "stdlib.h"
#include "TableVal.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class PrimaryTable
{

private:
	int a, b, c;

	static const int p1 = 16890581;
	static const int p2 = 17027399;

	int tableSize;
	int amtMoreThan1;
	double avgTries;

	TableVal* maxCollisions;

	TableVal** HashTable;

public:

/**********************************************************************
 * Name: PrimaryTable
 * PreCondition: integer tablesize
 *
 * PostCondition: PrimaryTable with HashTable size of ts
 *********************************************************************/
	PrimaryTable(int ts);


/**********************************************************************
 * Name: ~PrimaryTable
 * PreCondition: none
 *
 * PostCondition: deleted PrimaryTable
 *********************************************************************/
	~PrimaryTable();


/**********************************************************************
 * Name: Hash
 * PreCondition: string to be hashed
 *
 * PostCondition: integer index value
 *********************************************************************/
	int Hash(string str);


/**********************************************************************
 * Name: GetGVal
 * PreCondition: string to be hashed
 *
 * PostCondition: integer G value of hash function
 *********************************************************************/
	unsigned long long GetGVal(string str);


/**********************************************************************
 * Name: GetHVal
 * PreCondition: string to be hashed
 *
 * PostCondition: integer H value of hash function
 *********************************************************************/
	int GetHVal(unsigned long long g);


/**********************************************************************
 * Name: Insert
 * PreCondition: location, latitude, longitude to be inserted at index
 *
 * PostCondition: inserted TableVal in HashTable
 *********************************************************************/
	void Insert(string loc, float lat, float lon, int index);


/**********************************************************************
 * Name: MakeSecondTables
 * PreCondition: none
 *
 * PostCondition: secondary tables made for all necessary table values
 *********************************************************************/
	void MakeSecondTables();


/**********************************************************************
 * Name: ConstructSecondary
 * PreCondition: TableVal to make secondary table for
 *
 * PostCondition: secondary table made for TableVal
 *********************************************************************/
	void ConstructSecondary(TableVal* tv);


/**********************************************************************
 * Name: operator<<
 * PreCondition: output stream and table to be outputted
 *
 * PostCondition: outputted statistics of table
 *********************************************************************/
	friend ostream& operator<<(ostream& os, PrimaryTable pTable);


/**********************************************************************
 * Name: OutputNumCities
 * PreCondition: output stream
 *
 * PostCondition: output statistics of how many cities hashtable has
 *********************************************************************/
	ostream& OutputNumCities(ostream& os);


/**********************************************************************
 * Name: HowManyXCities
 * PreCondition: number x
 *
 * PostCondition: number of tableVals had x cities
 *********************************************************************/
	int HowManyXCities(int x);


/**********************************************************************
 * Name: OutputNumFunctions
 * PreCondition: output stream
 *
 * PostCondition: output statistics of how many functions hashtable tried
 *********************************************************************/
	ostream& OutputNumFunctions(ostream& os);


/**********************************************************************
 * Name: HowManyXCities
 * PreCondition: number x
 *
 * PostCondition: number of secondTableVals had tried x hash functions
 *********************************************************************/
	int HowManyXTries(int x);


/**********************************************************************
 * Name: GetKey
 * PreCondition: string str
 *
 * PostCondition: index value of string
 *********************************************************************/
	int GetKey(string str);


/**********************************************************************
 * Name: OutputSearch
 * PreCondition: output stream and string
 *
 * PostCondition: location, latitude, and longitude of string
 * at location in table
 *********************************************************************/
	ostream& OutputSearch(ostream& os, string str);
};

#endif
