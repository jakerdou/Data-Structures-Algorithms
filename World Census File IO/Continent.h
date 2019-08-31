/*****************************************
** File: Continent.h
** Project: CSCE 221 Project 0, Spring 2019
** Author: James Robinson
** Date: 1/23/19
** Section: 510
** E-mail: jakerdou@tamu.edu
**
**
** This is the h file for the Continent class
** The variables and functions are declared here
**
**
**
**
***********************************************/

#ifndef CONTINENT_H
#define CONTINENT_H
#include <iostream>
#include <vector>
#include "Country.h"

using namespace std;

class Continent : public Country
{
public:
	//The functions below are the setter functions
	void SetHighestPopulation(Country& countryHighestPop);
	void SetHighestGDPSpent(Country& countryHighestGDP);
	void SetHighestLiteracyRate(Country& countryHighestLitRate);
	void AddCountry(Country countryToAdd);

	//The functions below are the getter functions
	Country GetHighestPopulation();
	Country GetHighestGDPSpent();
	Country GetHighestLiteracyRate();
	vector<Country> &GetCountriesInContinent();
	vector<Country> countriesInContinent;
//-------------------------------------------------------
// Name: operator<< (output overload)
// PreCondition: The stream must have a file streaming in,
//				 and the Continent must not be empty
// PostCondition: Returns the output showing highest GDP,
//                Literacy Rate, and Population for each continent.
//---------------------------------------------------------
	friend ostream& operator<<(ostream& os, const Continent inputCont);

	
private:
	
	Country highestPopulation;
	Country highestGDPSpent;
	Country highestLiteracyRate;
};


#endif
