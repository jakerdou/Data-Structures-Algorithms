/**************************************************************
 * File:    Node221.cpp
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the Node221 class.
 * Includes function definitions for functions declared in
 * .h file
 *************************************************************/
#ifndef NODE221_CPP
#define NODE221_CPP
#include <iostream>
#include "Node221.h"

using namespace std;

template<class T>
Node221<T>::Node221()
{
	//setting next and previous to nothing
	previous = nullptr;
	next = nullptr;
}

//Setter and Getter functions
template<class T>
Node221<T>* Node221<T>::GetPrevious()
{
	return previous;
}

template<class T>
Node221<T>* Node221<T>::GetNext()
{
	return next;
}

template<class T>
T Node221<T>::GetData()
{
	return data;
}

template<class T>
void Node221<T>::SetPrevious(Node221<T>* inputPrev)
{
	previous = inputPrev;
}

template<class T>
void Node221<T>::SetNext(Node221<T>* inputNext)
{
	next = inputNext;
}

template<class T>
void Node221<T>::SetData(T inputData)
{
	data = inputData;
}

#endif