/**************************************************************
 * File:    PrimaryTable.cpp
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for primary table.
 * Has as many buckets as things being inserted
 * 
 *************************************************************/

#include "PrimaryTable.h"

using namespace std;

PrimaryTable::PrimaryTable(int ts)
{
	//instantiate values
	tableSize = ts;
	amtMoreThan1 = 0;
	avgTries = 0;
	HashTable = new TableVal*[tableSize];
	maxCollisions = new TableVal;

	//instantiate values for max collision tablevalue
	maxCollisions->location = "n/a";
	maxCollisions->latitude = 0;
	maxCollisions->longitude = 0;
	maxCollisions->numCollisions = 0;
	maxCollisions->sTable = NULL;
	
	//fill hashtable with proper beginning values
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new TableVal;
		HashTable[i]->location = "n/a";
		HashTable[i]->latitude = 0;
		HashTable[i]->longitude = 0;
		HashTable[i]->numCollisions = 0;
		HashTable[i]->sTable = NULL;
	}
}

PrimaryTable::~PrimaryTable()
{

}

int PrimaryTable::Hash(string str)
{

	unsigned long long g = GetGVal(str);

	int h = GetHVal(g);

	return h;
}

unsigned long long PrimaryTable::GetGVal(string str)
{
	unsigned long long g = 0;

	//seed the random number generator
	srand(0);

	int c2 = 2;

	//turn string into number with first hash function
	for (int i = 0; i < str.length(); i++)
	{
		g = g + (str[i] * (unsigned long long)(pow(double(c2), double(i)) + .5));
	}

	g = g % p1;

	c = c2;

	return g;
}

int PrimaryTable::GetHVal(unsigned long long g)
{
	unsigned long long h = 0;
	int a2, b2;

	a2 = abs(rand() % p2) + 1;
	b2 = abs(rand() % p2);

	//get final index with second hash function
	h = ((a2 * g + b2) % p2) % tableSize;

	a = a2;
	b = b2;

	h = int(h);

	return h;
}

void PrimaryTable::Insert(string loc, float lat, float lon, int index)
{	
	//create new TableVal with correct values
	TableVal* tv = new TableVal;
	tv->location = loc;
	tv->latitude = lat;
	tv->longitude = lon;
	tv->numCollisions = 0;

	
	if (HashTable[index]->location == "n/a")
	{
		//delete place in table and replace it with new value
		//delete HashTable[index];
		HashTable[index] = tv;
	}
	//if there was a value already at that index
	else
	{
		HashTable[index]->numCollisions++;
		((HashTable[index])->collided).push_back(tv);
	}	
}

void PrimaryTable::MakeSecondTables()
{
	//iterate through table and construct secondaries
	for (int index = 0; index < tableSize; index++)
	{
		ConstructSecondary(HashTable[index]);
	}
}

void PrimaryTable::ConstructSecondary(TableVal* tv)
{
	//if at the index there were no collisions
	if (tv->numCollisions == 0)
	{
		return;
	}
	else
	{
		if (tv->numCollisions > maxCollisions->numCollisions)
		{
			//update maxCollisions
			//delete maxCollisions;
			maxCollisions = tv;
		}

		//construct the new second table
		tv->sTable = new SecondaryTable(tv->numCollisions);
		
		vector<SecondTableVal*> sVec;

		//iterate through and create new second table vals for all the collided
		for (int i = 0; i < tv->numCollisions; i++)
		{
			SecondTableVal* sv = new SecondTableVal;
			sv->location = tv->collided.at(i)->location;
			sv->latitude = tv->collided.at(i)->latitude;
			sv->longitude = tv->collided.at(i)->longitude;
			sv->numCollisions = 0;
			sVec.push_back(sv);
		}
		
		//take the vector of second table vals and populate the second table with it
		tv->sTable->PopulateSecondTable(sVec);
	}
}

ostream & operator<<(ostream & os, PrimaryTable pTable)
{
	//output constant values
	os << "p1: " << pTable.p1 << endl;
	os << "p2: " << pTable.p2 << endl;
	os << "a: " << pTable.a << endl;
	os << "b: " << pTable.b << endl;
	os << "c: " << pTable.c << endl << endl;

	os << "number of cities: " << pTable.tableSize << endl;

	os << "maximum collisions: " << pTable.maxCollisions->numCollisions + 1 << endl;

	pTable.OutputNumCities(os) << endl;

	os << "**cities in the slot with the most collisions**\n";

	os << pTable.maxCollisions;
	for (int i = 0; i < pTable.maxCollisions->collided.size(); i++)
	{
		os << pTable.maxCollisions->collided.at(i);
	}

	os << endl;

	pTable.OutputNumFunctions(os);

	os << "number of secondary hash tables with more than one item: " << pTable.amtMoreThan1 << endl;

	os << "average number of hash functions tried: " << pTable.avgTries << endl;

	return os;
}

ostream & PrimaryTable::OutputNumCities(ostream & os)
{
	for (int i = 0; i < 10; i++)
	{
		os << "# primary slots with " << i << " cities: ";
		os << HowManyXCities(i) << endl;
	}
	return os;
}

int PrimaryTable::HowManyXCities(int x)
{
	//num is how many places in the table have x cities
	int num = 0;

	//base case
	if (x == 0)
	{
		for (int i = 0; i < tableSize; i++)
		{
			if (HashTable[i]->location == "n/a")
			{
				num++;
			}
		}
	}
	else
	{
		for (int i = 0; i < tableSize; i++)
		{
			//iterate through table and icrement num if table val has x cities
			if (HashTable[i]->numCollisions == x - 1 && HashTable[i]->location != "n/a")
			{
				num++;
			}
		}
	}
	return num;
}

ostream & PrimaryTable::OutputNumFunctions(ostream & os)
{
	//outputs for 1-10, but collects data on 1-50
	for (int i = 1; i < 51; i++)
	{
		if (i < 11)
		{
			os << "# secondary hash tables trying " << i << " hash functions: ";
			os << HowManyXTries(i) << endl;
		}
	}
	avgTries = avgTries / amtMoreThan1;
	return os;
}

int PrimaryTable::HowManyXTries(int x)
{
	//num is how many second tables took x tries to find a valid hash function
	int num = 0;

	for (int i = 0; i < tableSize; i++)
	{
		if (HashTable[i]->numCollisions != 0)
		{
			//if second table tried x times
			if (HashTable[i]->sTable->GetNumTries() == x)
			{
				num++;

				/*update data on how many functions were tried in tables with more than
				  2 second table vals*/
				if (HashTable[i]->collided.size() > 1)
				{
					amtMoreThan1++;
					avgTries = avgTries + HashTable[i]->sTable->GetNumTries();
				}
			}
			
		}
	}

	return num;
}

int PrimaryTable::GetKey(string str)
{ 
	//hash string and tell if empty
	int index = Hash(str);
	if (HashTable[index]->location != "n/a")
	{
		return index;
	}

	return -1;
}

ostream & PrimaryTable::OutputSearch(ostream & os, string str)
{
	int index = Hash(str);

	//if the searched city is in the primary table
	if (HashTable[index]->location == str)
	{
		os << HashTable[index];
	}

	//if the searched city is not in the primary table, search secondary table
	else
	{
		//if no second table exists
		if (HashTable[index]->numCollisions == 0)
		{
			os << "n/a\n";
			return os;
		}
		HashTable[index]->sTable->SecondOutputSearch(os, str);
	}

	return os;
}
