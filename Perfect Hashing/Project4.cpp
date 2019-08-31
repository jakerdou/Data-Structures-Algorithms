/**************************************************************
 * File:    Project4.cpp
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * The driver file for Project 4. Includes the main function
 * The file will take an input of a txt file of city names and
 * latitudes and longitudes that it will perfectly hash into
 * primary tables and secondary tables.
 * It will then output information about the primary tables and 
 * secondary tables.
 *************************************************************/

#include <iostream>
#include <fstream>
#include "PrimaryTable.h"
#include "SecondaryTable.h"
#include <cmath>

using namespace std;

const string SEARCH_FOR_CITY = "Lawnton, PA";

int main(int argc, char** argv)
{	
	//read in command line file
	ifstream input(argv[1]);

	vector<TableVal> tVec;

	int numCity = 0;
	
	//input all cities into vector to count how many there are
	while (input.good())
	{
		TableVal tv;
		string city, buffer;
		float lat, lon;

		getline(input, city);
		input >> lat;
		input >> lon;

		//puts values in the TableValue
		if (city != "")
		{
			tv.location = city;
			tv.latitude = lat;
			tv.longitude = lon;
			numCity++;
			tVec.push_back(tv);
		}

		//eat whitespace
		getline(input, buffer);
	}
	
	//instantiate PrimaryTable as big as how many cities there were
	PrimaryTable pTable(numCity);
	
	//take the cities from the vector and insert them at the correct place in the table
	for (int i = 0; i < numCity; i++)
	{
		TableVal currVal = tVec.at(i);
		int index = pTable.Hash(currVal.location);

		pTable.Insert(currVal.location, currVal.latitude, currVal.longitude, index);
	}

	//construct the secondary tables for all the necessary TableValues
	pTable.MakeSecondTables();

	//output statistics of tables
	cout << pTable << endl;

	//output statistics of searched for city
	cout << "SEARCH\ncity details: ";

	//output key of searched city
	int key = pTable.GetKey(SEARCH_FOR_CITY);
	if (key != -1)
	{
		cout << "Key: " << key << endl;
	}

	//output location, latitude, and longitude of searched for city
	pTable.OutputSearch(cout, SEARCH_FOR_CITY);
}