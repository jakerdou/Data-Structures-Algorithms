/*****************************************
** File: Driver.cpp
** Project: CSCE 221 Project 0, Spring 2019
** Author: James Robinson
** Date: 1/23/19
** Section: 510
** E-mail: jakerdou@tamu.edu
**
** This file contains the main driver program for Project 0.
** This program takes 2 text files consisting of continents, countries
** and data about them.
** It groups the countries into their respective countries
** and assigns them their proper statistics.
** The program then finds the highest population, GDP percent
** spent on education, and literacy rate then outputs the results.
***********************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "Country.h"
#include "Continent.h"

using namespace std;

//-------------------------------------------------------
// Name: GetContinents
// PreCondition: The string is an actual file name
// PostCondition: Returns continent vector with proper continent names
//---------------------------------------------------------

vector<Continent> GetContinents(string CountryFile)
{
	//2nd continent vector, temporary vector that will be returned at end of function as ContVec in the ReadFromFiles function
	vector<Continent> ContVec2;
	
	ifstream contStream; //continent stream
	string goBetween; //string meant to contain the data we are reading in

	//open file with continent names
	contStream.open(CountryFile);

	while (contStream >> goBetween)
	{	//loops until finds a name of a continent
		if (isupper(goBetween[1]))
		{
			//acts as continent that we can put into the vector the function returns
			Continent tempCont; 

			tempCont.SetName(goBetween);

			//puts continent in vector
			ContVec2.push_back(tempCont); 
		}
	}
	contStream.close();
	
	return ContVec2;
}

//-------------------------------------------------------
// Name: GetCountries
// PreCondition: The string must be an actual file name, 
//				 vector is not empty
// PostCondition: Returns continent vector with proper country names
//---------------------------------------------------------

vector<Continent> GetCountries(string CountryFile, vector<Continent> ContVec3)
{
	ifstream countryStream;
	string goBetween2; //2nd go between string, going to read file in as string and then convert it to floats, ints, etc.

	countryStream.open(CountryFile); 

	//iterator to tell under which continent to put the countries
	int contIterate = 0; 

	//extracts first continent so that while loop will execute correctly
	getline(countryStream, goBetween2); 

	while (countryStream >> goBetween2)
	{
		Country tempCountry; //acts as country that we can put into the vector the function returns

		//loops and puts countries in to vector until an all caps word is reached (name of continent)
		if (isupper(goBetween2[1]))
		{
			contIterate++;

			//take in rest of info on line of name of continent (eg. "-- 54") so that it doesn't mess up the naming
			getline(countryStream, goBetween2); 
		}
		else
		{
			tempCountry.SetName(goBetween2);

			//adds country to vector
			(ContVec3.at(contIterate)).AddCountry(tempCountry); 
		}
	}
	countryStream.close();

	return ContVec3;
}

//-------------------------------------------------------
// Name: SetStats
// PreCondition: Stream works and country has name
// PostCondition: Returns country with proper statistics
//---------------------------------------------------------

Country SetStats(ifstream& stream, Country inputCountry)
{
	string goBetween4;

	//setting population
	stream >> goBetween4;
	inputCountry.SetPopulation(stol(goBetween4));

	//setting literacy rate
	stream >> goBetween4;
	if (goBetween4 == "N/A")
	{ 
		inputCountry.SetLiteracyRate(-1); 
	}
	else
	{
		inputCountry.SetLiteracyRate(stof(goBetween4));
	}

	//percent GDP spent on education
	stream >> goBetween4;
	if (goBetween4 == "N/A") 
	{ 
		inputCountry.SetEducationGDPSpent(-1); 
	}
	else
	{
		inputCountry.SetEducationGDPSpent(stof(goBetween4));
	}

	//Total primary completion percentage
	stream >> goBetween4;
	if (goBetween4 == "N/A") 
	{ 
		inputCountry.SetPrimaryCompletionTotal(-1); 
	}
	else
	{
		inputCountry.SetPrimaryCompletionTotal(stof(goBetween4));
	}

	//Male primary completion percentage
	stream >> goBetween4;
	if (goBetween4 == "N/A") 
	{ 
		inputCountry.SetPrimaryCompletionMale(-1); 
	}
	else
	{
		inputCountry.SetPrimaryCompletionMale(stof(goBetween4));
	}

	//Female primary completion percentage
	stream >> goBetween4;
	if (goBetween4 == "N/A") 
	{ 
		inputCountry.SetPrimaryCompletionFemale(-1); 
	}
	else
	{
		inputCountry.SetPrimaryCompletionFemale(stof(goBetween4));
	}

	//Female youth literacy rate
	stream >> goBetween4;
	if (goBetween4 == "N/A") 
	{ 
		inputCountry.SetYouthLitRateFemale(-1); 
	}
	else
	{
		inputCountry.SetYouthLitRateFemale(stof(goBetween4));
	}

	//Male youth literacy rate
	stream >> goBetween4;
	if (goBetween4 == "N/A") 
	{ 
		inputCountry.SetYouthLitRateMale(-1); 
	}
	else
	{
		inputCountry.SetYouthLitRateMale(stof(goBetween4));
	}

	return inputCountry;
}

//-------------------------------------------------------
// Name: GetStats
// PreCondition: StatsFile is the correct file, continent is not empty
// PostCondition: Returns continent with proper stats for all countries
//---------------------------------------------------------

Continent GetStats(string StatsFile, Continent inputCont)
{
	ifstream statStream;

	for (int countryIterate = 0; countryIterate < (inputCont.GetCountriesInContinent()).size(); countryIterate++)
	{
		statStream.open(StatsFile);
		string goBetween3;
		getline(statStream, goBetween3);

		//countryName is set to the name of the country that we are currently searching through the stats file for a match
		string countryName = ((inputCont.GetCountriesInContinent()).at(countryIterate)).GetName(); 
		
		//looping to find name that matches
		while (statStream >> goBetween3)
		{

			if (countryName == goBetween3)
			{
				//once a match is found, stats are set

				break;
			}
			else
			{
				//if a match is not found, rest of information on line is taken in because it is just numbers
				getline(statStream, goBetween3);
			}
		}
		if (countryName == goBetween3)
		{
			((inputCont.GetCountriesInContinent()).at(countryIterate)) = SetStats(statStream, ((inputCont.GetCountriesInContinent()).at(countryIterate)));
		}
		else
		{
			//setting default values if country is not found in stats file
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetPopulation(0);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetLiteracyRate(-1);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetEducationGDPSpent(-1);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetPrimaryCompletionTotal(-1);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetPrimaryCompletionMale(-1);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetPrimaryCompletionFemale(-1);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetYouthLitRateFemale(-1);
			((inputCont.GetCountriesInContinent()).at(countryIterate)).SetYouthLitRateMale(-1);
		}
		statStream.close();
	}
	return inputCont;
}

//-------------------------------------------------------
// Name: SetHighest
// PreCondition: inputCont has countries with stats
// PostCondition: Returns continent with highest statistics set
//---------------------------------------------------------

Continent SetHighest(Continent& inputCont)
{
	//sets highest to first country in each continent
	inputCont.SetHighestPopulation((inputCont.GetCountriesInContinent().at(0)));
	inputCont.SetHighestLiteracyRate((inputCont.GetCountriesInContinent().at(0)));
	inputCont.SetHighestGDPSpent((inputCont.GetCountriesInContinent().at(0)));

	for (int i = 1; i < (inputCont.GetCountriesInContinent()).size(); i++)
	{
		//assigns higher population
		if (((inputCont.GetCountriesInContinent()).at(i)).GetPopulation() > (inputCont.GetHighestPopulation()).GetPopulation())
		{
			inputCont.SetHighestPopulation((inputCont.GetCountriesInContinent().at(i)));
			
		}
		
		//assigns higher literacy rate
		if (((inputCont.GetCountriesInContinent()).at(i)).GetLiteracyRate() > (inputCont.GetHighestLiteracyRate()).GetLiteracyRate())
		{
			inputCont.SetHighestLiteracyRate((inputCont.GetCountriesInContinent().at(i)));
			
		}

		//assigns higher GDP spent
		if (((inputCont.GetCountriesInContinent()).at(i)).GetEducationGDPSpent() > (inputCont.GetHighestGDPSpent()).GetEducationGDPSpent())
		{
			inputCont.SetHighestGDPSpent((inputCont.GetCountriesInContinent().at(i)));
			
		}
	}
	return inputCont;
}

//-------------------------------------------------------
// Name: readFromFiles
// PreCondition: Strings are correct file names
// PostCondition: Returns continent vector with countries and proper statistics
//---------------------------------------------------------

vector<Continent> readFromFiles(string CountryFile, string StatsFile)
{
	//Vector that will be returned at the end of the function as "world" in the main function
	vector<Continent> ContVec; 

	//calling function to load the correct continents into the vector
	ContVec = GetContinents(CountryFile);
	
	ContVec = GetCountries(CountryFile, ContVec);

	//loops through all continents and adds statistics to countries, then sets the highest in the appropriate categories
	for (int i = 0; i < ContVec.size(); i++)
	{
		ContVec.at(i) = GetStats(StatsFile, ContVec.at(i));
		SetHighest(ContVec.at(i));
	}

	return ContVec;
}

int main()
{
	vector<Continent> world;

	world = readFromFiles("CountriesContinents.txt", "2013WorldBankEducationCensusData.txt");

	//for loop iterating through all the continents and outputting information
	for (int i = 0; i < world.size(); i++)
	{
		cout << world.at(i);
	}

	system("pause");
	
	return 0;
}














