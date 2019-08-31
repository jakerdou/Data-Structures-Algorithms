/*****************************************
** File: Continent.cpp
** Project: CSCE 221 Project 0, Spring 2019
** Author: James Robinson
** Date: 1/23/19
** Section: 510
** E-mail: jakerdou@tamu.edu
**
**
** This is the cpp file for the Continent class
** It has various member variables and the
** getter/setter functions defined in this file
** It is the child class of the Country Class
**
**
***********************************************/

#include "Continent.h"

//The functions below are the setter functions
void Continent::SetHighestPopulation(Country& countryHighestPop)
{
	highestPopulation = countryHighestPop;
}

void Continent::SetHighestGDPSpent(Country& countryHighestGDP)
{
	highestGDPSpent = countryHighestGDP;
}

void Continent::SetHighestLiteracyRate(Country& countryHighestLitRate)
{
	highestLiteracyRate = countryHighestLitRate;
}

void Continent::AddCountry(Country countryToAdd)
{
	countriesInContinent.push_back(countryToAdd);
}


//The functions below are the getter functions
Country Continent::GetHighestPopulation()
{
	return highestPopulation;
}

Country Continent::GetHighestGDPSpent()
{
	return highestGDPSpent;
}

Country Continent::GetHighestLiteracyRate()
{
	return highestLiteracyRate;
}

vector<Country> &Continent::GetCountriesInContinent()
{
	return countriesInContinent;
}

//overloaded output
ostream & operator<<(ostream & os, Continent inputCont)
{
	os << inputCont.GetName();
	os << endl;

	//calculates total population of country
	long long totalPopulation = 0;
	for (int i = 0; i < (inputCont.GetCountriesInContinent()).size(); i++)
	{
		totalPopulation = ((inputCont.GetCountriesInContinent()).at(i)).GetPopulation() + totalPopulation;
	}

	os << " Population: ";
	os << totalPopulation;
	os << endl;

	//all output for highest lit rate
	os << " Country with highest literacy rate: ";
	os << (inputCont.GetHighestLiteracyRate()).GetName();
	os << " with a population of ";
	os << (inputCont.GetHighestLiteracyRate()).GetPopulation();
	os << " and a literacy rate of "; 
	os << (inputCont.GetHighestLiteracyRate()).GetLiteracyRate(); 
	os << endl;

	//all output for highest GDP
	os << " Country with highest GDP spendature on education: ";
	os << (inputCont.GetHighestGDPSpent()).GetName();
	os << " with a population of ";
	os << (inputCont.GetHighestGDPSpent()).GetPopulation();
	os << " and a literacy rate of ";
	os << (inputCont.GetHighestGDPSpent()).GetLiteracyRate();
	os << endl;

	//all output for highest population
	os << " Country with highest population: ";
	os << (inputCont.GetHighestPopulation()).GetName();
	os << " with a population of ";
	os << (inputCont.GetHighestPopulation()).GetPopulation();
	os << " and a literacy rate of ";
	os << (inputCont.GetHighestPopulation()).GetLiteracyRate();
	os << endl;

	return os;
}
