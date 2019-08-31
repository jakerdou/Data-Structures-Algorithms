/*****************************************
** File: Country.h
** Project: CSCE 221 Project 0, Spring 2019
** Author: James Robinson
** Date: 1/23/19
** Section: 510
** E-mail: jakerdou@tamu.edu
**
**
** This is the h file for the Country class
** The variables and functions are declared here
** 
**
**
**
***********************************************/

#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>

using namespace std;

class Country 
{
public:
	//The functions below are the setter functions
	void SetName(string inputName);

	void SetPopulation(long inputPopulation);

	void SetLiteracyRate(float inputLitRate);

	void SetPrimaryCompletionMale(float inputCompletionRate);

	void SetPrimaryCompletionFemale(float inputCompletionRate);

	void SetPrimaryCompletionTotal(float inputCompletionRate);

	void SetEducationGDPSpent(float inputAmtSpent);

	void SetYouthLitRateFemale(float inputLitRate);

	void SetYouthLitRateMale(float inputLitRate);

	//The functions below are the getter functions
	string GetName();

	long GetPopulation();

	float GetLiteracyRate();

	float GetPrimaryCompletionMale();

	float GetPrimaryCompletionFemale();

	float GetPrimaryCompletionTotal();

	float GetEducationGDPSpent();

	float GetYouthLitRateFemale();

	float GetYouthLitRateMale();

protected:

private:
	string name;
	long population;
	float literacyRate;
	float primaryCompletionMale;
	float primaryCompletionFemale;
	float primaryCompletionTotal;
	float educationGDPSpent;
	float youthLitRateFemale;
	float youthLitRateMale;
};



#endif



