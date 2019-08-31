/**************************************************************
 * File:    TableVal.h
 * Project: CSCE 221 - Project 4
 * Author : James Robinson
 * Date   : 4/24/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for primary table value
 * holds information at indexes in the PrimaryTable
 * has SecondaryTable member variable
 *************************************************************/

#ifndef TABLEVAL_H
#define TABLEVAL_H

#include "stdlib.h"
#include "SecondaryTable.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TableVal
{
	string location;
	float latitude;
	float longitude;
	int numCollisions;
	vector<TableVal*> collided;
	SecondaryTable* sTable;


/**********************************************************************
 * Name: operator<<
 * PreCondition: output stream and table value to be outputted
 *
 * PostCondition: outputted statistics of table value
 *********************************************************************/
	friend ostream& operator<<(ostream& os, TableVal* tv)
	{
		os << tv->location << " ";
		os << "(" << tv->latitude << " ";
		os << tv->longitude << ")" << endl;

		return os;
	}
};

#endif