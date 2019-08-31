/**************************************************************
 * File:    Driver.cpp
 * Project: CSCE 221 - Project 1
 * Author : 
 * Date   : 
 * Section: 
 * E-mail:  
 *
 * Driver File that will include test cases and error throwing
 * for the Stack221 and Queue221 Classes
 * 
 *************************************************************/
#include <iostream>
#include "List221.h"
#include "Stack221.h"
#include "Queue221.h"
#include "Node221.h"
#include "Exceptions221.h"


int main(int argc, char *argv[]) {
	using namespace std;

	//ACTUAL DRIVER CODE INCLUDED WHEN DOWNLOADED
	/*
	Stack221<int> *myStack4 = new Stack221<int>();
	Queue221<int> myQueue;

	try
	{
		for (int i = 0; i < 10;)
		{
			myStack4->Push(i);
			myQueue.Push(i++);
		}
	cout << "Queue size: " << myQueue.Size() << endl;
	cout << "Queue cleared = " << myQueue.Clear() << endl;

	}
	catch (Exceptions221 &E)
	{
		cout << "Exception: " << E.GetMessage() << endl;
	}

	delete myStack4;
	*/

	/************************************************************/

		//CODE THAT CHECKS FOR EXCEPTIONS BEING THROWN
	/*
	Stack221<int> myTestStack;
	Queue221<int> myTestQ;

	myTestQ.Front();
	myTestQ.Back();
	myTestStack.Top();

	myTestQ.Push(1);
	Queue221<int> myTestQ2(myTestQ);
	*/

	/************************************************************/

	//START OF MY TEST CASES THAT I USED WHILE WRITING CODE
	/*
	cout << "\nPERSONAL TEST CASES\n";

	//Node testing
	cout << "\nNODE TESTING\n";
	Node221<int> myNode;
	Node221<int> nextNode, prevNode;
	myNode.SetData(5);
	prevNode.SetData(4);
	nextNode.SetData(6);

	prevNode.SetNext(&myNode);
	myNode.SetPrevious(&prevNode);
	myNode.SetNext(&nextNode);
	nextNode.SetPrevious(&myNode);

	cout << "Values in nodes: " << myNode.GetPrevious()->GetData() << " " << myNode.GetData() << " " << myNode.GetNext()->GetData() << endl;

	cout << "\nSTACK TESTING\n";

	//Stack testing
	Stack221<int> myStack;
	
	if (myStack.Empty())
	{
		cout << "Stack is empty\n";
	}

	Stack221<int>* myHStack = new Stack221<int>;
	myHStack->Push(9);
	cout << "Value on top is " << myHStack->Top() << endl;

	myHStack->Push(8);

	myHStack->Push(7);

	cout << "After adding 2 nodes, the value on top is: " << myHStack->Top() << endl;

	cout << "Size of the stack is: " << myHStack->Size() << endl;

	myHStack->Pop();
	cout << "After popping, value on top is: " << myHStack->Top() << endl;

	cout << "Size of the stack is: " << myHStack->Size() << endl;

	myHStack->Clear();

	cout << "After clearing, size of the stack is: " << myHStack->Size() << endl << endl;

	int testSize = 3;

	for (int i = 0; i < testSize; i++)
	{
		myHStack->Push(i);
	}

	cout << "*Add " << testSize << " values*\n";
	for (int i = 0; i < testSize; i++)
	{
		cout << "Value on top is: " << myHStack->Top() << "\n*POP*\n";
		myHStack->Pop();
	}
	cout << "Size is " << myHStack->Size() << endl << endl;

	for (int i = 0; i < testSize; i++)
	{
		myStack.Push(i);
	}
	cout << "*Add " << testSize << " values to regular stack and construct copy*\n";
	Stack221<int> myStack2(myStack);
	for (int i = 0; i < testSize; i++)
	{
		cout << "Value on top is of copy constructed stack is: " << myStack2.Top() << "\n*POP*\n";
		myStack2.Pop();
	}


	cout << endl << "QUEUE TESTING\n";

	Queue221<int> myQ;

	cout << "Empty() returned " << myQ.Empty() << endl;

	for (int i = 0; i < testSize; i++)
	{
		myQ.Push(i);
	}
	cout << "*Add " << testSize << " values to regular queue*\n";

	cout << "Size is: " << myQ.Size() << endl;
	for (int i = 0; i < testSize; i++)
	{
		cout << "Value at front of queue is: " << myQ.Front();
		cout << " , Back: "<< myQ.Back() <<  "\n*POP*\n";
		myQ.Pop();
	}

	cout << "Size is: " << myQ.Size() << endl;
	*/
}
