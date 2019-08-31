/**************************************************************
 * File:    Stack221.h
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * Stack221 Class definition; child class of List221
 * A templated class that will store values of the templated
 * type in a linked list and follow a FIRST IN, LAST OUT
 * method of removing the objects
 *************************************************************/
#ifndef STACK221_H
#define STACK221_H
#include "List221.h"

template <class T>
class Stack221 : public List221<T>
{
public:
	Stack221();

/**********************************************************************
 * Name: Stack221 (Constructor)
 * PreCondition: Stack221 object to be copied
 *
 * PostCondition:  deep copy of inputted Stack221 object
 *********************************************************************/
	Stack221(const Stack221<T>& inputStack);

	~Stack221();

/**********************************************************************
 * Name: Top
 * PreCondition: none
 *
 * PostCondition: object of templated type on top of the Stack221
 *********************************************************************/
	T Top();

	//Overriden functions from List221
	int Size() const override;

	bool Empty() const override;

	bool Push(T obj) override;

	bool Pop() override;

	bool Clear() override;
};
#include "Stack221.cpp"
#endif