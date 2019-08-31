/**************************************************************
 * File:    Stack221.cpp
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the Stack221 class.
 * Includes function definitions for functions declared in
 * .h file
 *************************************************************/
#ifndef STACK221_CPP
#define STACK221_CPP
#include <iostream>
#include "Stack221.h"
#include "Node221.h"
#include "Exceptions221.h"

template <class T>
Stack221<T>::Stack221()
{
	//sets front and back to nothing and the size to zero
	this->front = nullptr;
	this->back = nullptr;
	this->sizeTracker = 0;
}

template <class T>
Stack221<T>::Stack221(const Stack221<T>& inputStack)
{
	this->sizeTracker = 0;
	this->front = nullptr;
	this->back = nullptr;

	Node221<T>* cursor = inputStack.back;

	while (cursor != nullptr)
	{
		this->Push(cursor->GetData());
		cursor = cursor->GetPrevious();
	}
}

template <class T>
Stack221<T>::~Stack221(){}

template<class T>
int Stack221<T>::Size() const
{
	//returns size of stack
	return this->sizeTracker;
}

template<class T>
bool Stack221<T>::Empty() const
{
	// Returns true if empty
	if (this->front == nullptr && this->sizeTracker == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool Stack221<T>::Push(T obj)
{
	Node221<T>* tempNode = new Node221<T>;
	tempNode->SetData(obj);

	//Checks if empty then adds node to front of stack
	if (this->Empty())
	{
		this->front = tempNode;
		this->back = tempNode;
		(this->sizeTracker)++;
		return true;
	}
	else
	{
		tempNode->SetNext(this->front);
		(this->front)->SetPrevious(tempNode);
		this->front = tempNode;
		(this->sizeTracker)++;
		return true;
	}
}

template<class T>
bool Stack221<T>::Pop()
{
	//returns false if empty
	if (this->Empty())
	{
		return false;
	}
	//takes node off front of stack
	else
	{
		Node221<T>* tempNode = new Node221<T>;
		tempNode = this->front;

		//if there's more than one node in the stack
		if (tempNode != this->back) 
		{
			this->front = (this->front)->GetNext();
			(this->front)->SetPrevious(nullptr);
			
			delete tempNode;

			(this->sizeTracker)--;

			return true;
		}

		//if there's one node in the list
		else
		{
			this->front = nullptr;
			this->back = nullptr;

			delete tempNode;

			(this->sizeTracker)--;

			return true;
		}
	}
}

template<class T>
bool Stack221<T>::Clear()
{
	if (this->Empty())
	{
		return true;
	}
	//clears stack
	else if (!(this->Empty()))
	{
		int size = this->Size();
		for (int i = 0; i < size; i++)
		{
			this->Pop();
		}

		this->sizeTracker = 0;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
T Stack221<T>::Top()
{
	Exceptions221 E("Stack is empty, has no top value\n");
	try
	{
		//checking if stack is empty
		if (this->sizeTracker == 0)
		{
			throw E;
		}

		//returns data from top (front) of stack
		Node221<T>* tempNode;
		tempNode = this->front;
		return tempNode->GetData();
	}
	catch (Exceptions221 &E)
	{
		cout << E.GetMessage();
		//exit(0);
	}
}


#endif