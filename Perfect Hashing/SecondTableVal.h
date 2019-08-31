/**************************************************************
 * File:    SecondTableVal.h
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for secondary table value.
 * holds info for the indexes of the SecondaryTable
 * 
 *************************************************************/

#ifndef SECONDTABLEVAL_H
#define SECONDTABLEVAL_H

#include "stdlib.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct SecondTableVal
{
	string location;
	float latitude;
	float longitude;
	int numCollisions;


/**********************************************************************
 * Name: operator<<
 * PreCondition: output stream and second table value to be outputted
 *
 * PostCondition: outputted statistics of second table value
 *********************************************************************/
	friend ostream& operator<<(ostream& os, SecondTableVal* sv)
	{
		os << sv->location << " ";
		os << "(" << sv->latitude << " ";
		os << sv->longitude << ")" << endl;

		return os;
	}
};

#endif