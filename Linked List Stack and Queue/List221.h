/**************************************************************
 * File:    List221.h
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * List221 Class definition
 * A templated abstract class that is a linked list
 * Parent class of Stack221 and Queue221.
 * Has pointers to Node221 that are the front and 
 * back of the list
 *************************************************************/

#ifndef LIST221_H
#define LIST221_H

#include "Node221.h"

template <class T>
class List221
{

public: 
	List221() {}

	~List221() {}

/**********************************************************************
 * Name: Size
 * PreCondition: none
 *
 * PostCondition: returns int representing size of List221
 *********************************************************************/
	virtual int Size() const = 0;

/**********************************************************************
 * Name: Empty
 * PreCondition: none
 *
 * PostCondition: returns boolean representing if List221 is empty 
 * (true for empty)
 *********************************************************************/
	virtual bool Empty() const = 0;
	
/**********************************************************************
 * Name: Push
 * PreCondition: object of templated type to be pushed into List221
 *
 * PostCondition: none
 *********************************************************************/
	virtual bool Push(T obj) = 0;

/**********************************************************************
 * Name: Pop
 * PreCondition: none
 *
 * PostCondition: returns boolean indicating whether or not node on 
 * top of List221 was able to be popped (false for failure)
 *********************************************************************/
	virtual bool Pop() = 0;
	
/**********************************************************************
 * Name: Clear
 * PreCondition: none
 *
 * PostCondition: returns boolean indicating whether or not node on
 * top of List221 was able to be cleared (false for failure)
 *********************************************************************/
	virtual bool Clear() = 0;

protected:
	Node221<T>* front;
	Node221<T>* back;

	//int that tracks size of list
	int sizeTracker;
	
};

#endif
