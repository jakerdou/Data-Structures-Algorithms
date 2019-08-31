/**************************************************************
 * File:    SecondTableVal.cpp
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for secondary table value.
 * holds info for the indexes of the SecondaryTable
 *
 *************************************************************/

#include "SecondaryTable.h"

using namespace std;

SecondaryTable::SecondaryTable(int rootSize)
{
	//instantiate values
	tableSize = rootSize * rootSize;
	SecondHashTable = new SecondTableVal*[tableSize];

	//iterate through table and set beginning values
	for (int i = 0; i < tableSize; i++)
	{
		SecondHashTable[i] = new SecondTableVal;
		SecondHashTable[i]->location = "n/a";
		SecondHashTable[i]->latitude = 0;
		SecondHashTable[i]->longitude = 0;
		SecondHashTable[i]->numCollisions = 0;
	}
	
}

SecondaryTable::~SecondaryTable()
{
}

int SecondaryTable::GetNumTries()
{
	return numTries;
}

void SecondaryTable::PopulateSecondTable(vector<SecondTableVal*> items)
{
	int index;
	int seed = 1;
	int numInserted = 0;
	bool isPopulated = false;

	numTries = 1;
	
	//while the table isn't fully populated
	while (!isPopulated)
	{
		//iterate through items and add them to table
		for (int i = 0; i < items.size(); i++)
		{
			SecondTableVal* currItem = items.at(i);
			index = SecondHash(currItem->location, seed);

			//if the insert collides
			if (!(SecondInsert(currItem, seed, index)))
			{
				seed++;
				numTries++;
				numInserted = 0;
				i = items.size();
			}
			else
			{
				numInserted++;
			}
		}

		//if all the values get inserted
		if (numInserted == items.size())
		{
			isPopulated = true;
		}
	}
}

int SecondaryTable::SecondHash(string str, int seed)
{
	/*this function is basically the same as the one in
	  primary table, it just takes an input paramater seed
	  so that it can generate different random numbers*/

	unsigned long long g = GetSecondG(str, seed);

	int h = GetSecondH(g);

	return h;
}

unsigned long long SecondaryTable::GetSecondG(string str, int seed)
{
	unsigned long long g = 0;

	srand(seed);

	int c2 = 1;

	for (int i = 0; i < str.length(); i++)
	{	
		g = g + ((unsigned long long)str[i] * (unsigned long long)(pow(double(c2), double(i)) + .5));
	}

	g = g % p1;

	c = c2;

	return g;
}

int SecondaryTable::GetSecondH(unsigned long long g)
{
	unsigned long long h = 0;
	int a2, b2;

	a2 = (rand() % p2) + 1;
	b2 = (rand() % p2);

	h = (((a2 * g + b2) % p2) % tableSize);

	a = a2;
	b = b2;

	h = int(h);

	return h;
}

bool SecondaryTable::SecondInsert(SecondTableVal * sv, int seed, int index)
{
	//if the spot at the index is empty
	if (SecondHashTable[index]->location == "n/a")
	{
		SecondTableVal* sv2 = new SecondTableVal;
		sv2->location = sv->location;
		sv2->latitude = sv->latitude;
		sv2->longitude = sv->longitude;
		sv2->numCollisions = sv->numCollisions;
		SecondHashTable[index] = sv2;
		return true;
	}

	//if there's a collision, clear the table, and start over with a new seed
	else
	{
		ClearTable();
		return false;
	}
	
}

void SecondaryTable::ClearTable()
{
	//set all the values back to how they started
	for (int i = 0; i < tableSize; i++)
	{
		SecondHashTable[i]->location = "n/a";
		SecondHashTable[i]->latitude = 0;
		SecondHashTable[i]->longitude = 0;
		SecondHashTable[i]->numCollisions = 0;
	}
}

ostream & SecondaryTable::SecondOutputSearch(ostream & os, string str)
{
	//base case, if search is empty
	if (str == "")
	{
		os << "n/a\n";
		return os;
	}


	//get index of string based on number of tries it took
	
	int index = SecondHash(str, numTries);

	//if the spot at the index isn't empty
	if (SecondHashTable[index]->location != "n/a")
	{
		os << SecondHashTable[index] << endl;
	}
	else
	{
		os << "n/a\n";
	}
	
	return os;
}


