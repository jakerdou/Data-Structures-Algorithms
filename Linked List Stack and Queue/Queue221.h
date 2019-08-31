/**************************************************************
 * File:    Queue221.h
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * Queue221 Class definition; child class of List221
 * A templated class that will store values of the templated
 * type in a linked list and follow a FIRST IN, FIRST OUT
 * method of removing the objects
 *************************************************************/
#ifndef QUEUE221_H
#define QUEUE221_H

#include "List221.h"

template <class T>
class Queue221 : public List221<T>
{
public:
	Queue221();

/**********************************************************************
 * Name: Queue221 (Constructor)
 * PreCondition: Queue221 object to be copied
 *
 * PostCondition:  deep copy of inputted Queue221 object
 *********************************************************************/
	Queue221(const Queue221<T>& inputQueue);

	~Queue221();

/**********************************************************************
 * Name: Front
 * PreCondition: none
 *
 * PostCondition: object of templated data type at front of Queue221
 *********************************************************************/
	T Front();

/**********************************************************************
 * Name: Back
 * PreCondition: none
 *
 * PostCondition: object of templated data type at back of Queue221
 *********************************************************************/
	T Back();

	//Overriden functions from List221
	int Size() const override;

	bool Empty() const override;

	bool Push(T obj) override;

	bool Pop() override;

	bool Clear() override;
};
#include "Queue221.cpp"
#endif