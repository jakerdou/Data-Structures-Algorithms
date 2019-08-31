/**************************************************************
 * File:    Node221.h
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * Node221 Class definition
 * Templated class meant to be instances in Stack221 and 
 * Queue221 class.
 * Holds data of templated type as well as points to next 
 * and previous node in the list
 *************************************************************/
#ifndef NODE221_H
#define NODE221_H

template <class T>
class Node221
{
public:
	Node221();

/**********************************************************************
 * Name: GetPrevious
 * PreCondition: None
 *
 * PostCondition:  Node221 pointer to previous node in list
 *********************************************************************/
	Node221* GetPrevious();

/**********************************************************************
 * Name: GetNext
 * PreCondition: None
 *
 * PostCondition:  Node221 pointer to next node in list
 *********************************************************************/
	Node221* GetNext();

/**********************************************************************
 * Name: GetData
 * PreCondition: None
 *
 * PostCondition:  object of templated data type representing data 
 * stored in node
 *********************************************************************/
	T GetData();

/**********************************************************************
 * Name: SetPrevious
 * PreCondition: pointer to Node221 indicating previous
 *
 * PostCondition:  none
 *********************************************************************/
	void SetPrevious(Node221<T>* inputPrev);

/**********************************************************************
 * Name: SetNext
 * PreCondition: pointer to Node221 indicating next
 *
 * PostCondition:  none
 *********************************************************************/
	void SetNext(Node221<T>* inputNext);

/**********************************************************************
 * Name: SetData
 * PreCondition: object of templated data type
 *
 * PostCondition:  none
 *********************************************************************/
	void SetData(T inputData);

private:
	Node221* previous;
	Node221* next;
	T data;
};

#include "Node221.cpp"
#endif