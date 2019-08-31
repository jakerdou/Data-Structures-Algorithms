/**************************************************************
 * File:    Queue221.cpp
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the Queue221 class.
 * Includes function definitions for functions declared in 
 * .h file
 *************************************************************/
#ifndef QUEUE221_CPP
#define QUEUE221_CPP
#include <iostream>
#include "Queue221.h"
#include "Node221.h"
#include "Exceptions221.h"

template <class T>
Queue221<T>::Queue221()
{
	//sets front and back to nothing and the size to zero
	this->front = nullptr;
	this->back = nullptr;
	this->sizeTracker = 0;
}

template <class T>
Queue221<T>::Queue221(const Queue221<T>& inputQueue)
{
	this->sizeTracker = 0;
	this->front = nullptr;
	this->back = nullptr;

	Node221<T>* cursor = inputQueue.front;

	while (cursor != nullptr)
	{
		this->Push(cursor->GetData());
		cursor = cursor->GetNext();
	}
}

template <class T>
Queue221<T>::~Queue221(){}

template<class T>
int Queue221<T>::Size() const
{
	//returns the size of the queue
	return this->sizeTracker;
}

template<class T>
bool Queue221<T>::Empty() const
{
	//returns true if empty
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
bool Queue221<T>::Push(T obj)
{
	Node221<T>* tempNode = new Node221<T>;

	tempNode->SetData(obj);

	//checks if empty then adds item to back of queue
	if (this->Empty())
	{
		this->front = tempNode;
		this->back = tempNode;
		(this->sizeTracker)++;
		return true;
	}
	else
	{
		(this->back)->SetNext(tempNode);
		tempNode->SetPrevious(this->back);
		this->back = tempNode;
		(this->sizeTracker)++;
		return true;
	}
}

template<class T>
bool Queue221<T>::Pop()
{
	//returns false if empty
	if (this->Empty())
	{
		return false;
	}
	//takes node off of back of queue
	else
	{
		Node221<T>* tempNode = new Node221<T>;
		tempNode = this->front;

		//if there's more than one node in the queue
		if (tempNode != this->back)
		{
			this->front = (this->front)->GetNext();
			(this->front)->SetPrevious(nullptr);

			delete tempNode;

			(this->sizeTracker)--;

			return true;
		}

		//if there's one node in the queue
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
bool Queue221<T>::Clear()
{
	if (this->Empty())
	{
		return true;
	}
	//clears queue
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
T Queue221<T>::Front()
{
	Exceptions221 E("Queue is empty, has no front value\n");
	try
	{
		//checks if queue is empty
		if (this->sizeTracker == 0)
		{
			throw E;
		}

		//returns data from front of queue
		Node221<T>* tempNode;
		tempNode = this->front;
		return tempNode->GetData();
	}
	catch (Exceptions221 &E)
	{
		cout << E.GetMessage();
	}
}

template<class T>
T Queue221<T>::Back()
{
	
	Exceptions221 E("Queue is empty, has no back value\n");
	try
	{
		//checks if queue is emtpy
		if (this->sizeTracker == 0)
		{
			throw E;
		}

		//returns data from back of queue
		Node221<T>* tempNode;
		tempNode = this->back;
		return tempNode->GetData();
	}
	catch (Exceptions221 &E)
	{
		cout << E.GetMessage();
	}	
}


#endif