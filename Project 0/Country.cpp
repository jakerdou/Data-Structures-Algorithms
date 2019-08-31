/*****************************************
** File: Country.cpp
** Project: CSCE 221 Project 0, Spring 2019
** Author: James Robinson
** Date: 1/23/19
** Section: 510
** E-mail: jakerdou@tamu.edu
**
** 
** This is the cpp file for the Country class
** It has various member variables and the 
** getter/setter functions defined in this file
** 
** 
** 
***********************************************/

#include "Country.h"

//The functions below are the setter functions
void Country::SetName(string inputName)
{
	name = inputName;
}

void Country::SetPopulation(long inputPopulation)
{
	population = inputPopulation;
}

void Country::SetLiteracyRate(float inputLitRate)
{
	literacyRate = inputLitRate;
}

void Country::SetPrimaryCompletionMale(float inputCompletionRate)
{
	primaryCompletionMale = inputCompletionRate;
}

void Country::SetPrimaryCompletionFemale(float inputCompletionRate)
{
	primaryCompletionFemale = inputCompletionRate;
}

void Country::SetPrimaryCompletionTotal(float inputCompletionRate)
{
	primaryCompletionTotal = inputCompletionRate;
}

void Country::SetEducationGDPSpent(float inputAmtSpent)
{
	educationGDPSpent = inputAmtSpent;
}

void Country::SetYouthLitRateFemale(float inputLitRate)
{
	youthLitRateFemale = inputLitRate;
}

void Country::SetYouthLitRateMale(float inputLitRate)
{
	youthLitRateMale = inputLitRate;
}

//The functions below are the getter functions
string Country::GetName()
{
	return name;
}

long Country::GetPopulation()
{
	return population;
}

float Country::GetLiteracyRate()
{
	return literacyRate;
}

float Country::GetPrimaryCompletionMale()
{
	return primaryCompletionMale;
}

float Country::GetPrimaryCompletionFemale()
{
	return primaryCompletionFemale;
}

float Country::GetPrimaryCompletionTotal()
{
	return primaryCompletionTotal;
}

float Country::GetEducationGDPSpent()
{
	return educationGDPSpent;
}

float Country::GetYouthLitRateFemale()
{
	return youthLitRateFemale;
}

float Country::GetYouthLitRateMale()
{
	return youthLitRateMale;
}
