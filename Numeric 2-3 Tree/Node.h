/**************************************************************
 * File:    Node.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * Nodes to be inserted in the 2-3 tree
 *
 *
 *************************************************************/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Node structure for use in 2-3 trees */
template <typename DataType>
struct Node
{

	DataType dataL;
	DataType dataR;
	int numberData;

	Node<DataType>* leftChild;
	Node<DataType>* middleChild;
	Node<DataType>* rightChild;

	Node* parent;
	   
	Node() 
	{ 
		parent = nullptr;
	
	}

};

#endif
