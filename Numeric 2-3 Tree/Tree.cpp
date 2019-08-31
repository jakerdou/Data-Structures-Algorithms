/**************************************************************
 * File:    Tree.cpp
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .cpp file for the Tree class
 * 2-3 tree that can insert and search
 *
 *************************************************************/

#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include "Tree.h"
#include "Node.h"

/* Stubs for the tree's methods */
using namespace std;

template<typename DataType, typename Compare>
DataType * Tree<DataType, Compare>::sortThreeData(DataType one, DataType two, DataType three)
{
	Compare comparator;

	DataType* m = new DataType[3];
	if (comparator(three, one))
	{
		m[0] = three;
		m[1] = one;
		m[2] = two;
	}
	else if (!comparator(three, two)) //LOOK AT THIS IF DOESN'T WORK
	{
		m[0] = one;
		m[1] = two;
		m[2] = three;
	}
	else
	{
		m[0] = one;
		m[1] = three;
		m[2] = two;
	}
	return m;
}

template<typename DataType, typename Compare>
Node<DataType>* Tree<DataType, Compare>::split(Node<DataType>* nodeToSplit, Node<DataType>* causedSplit, int position)
{
	Node<DataType>* nodeStorage[4];

	if (position == 0)
	{
		nodeStorage[0] = causedSplit->leftChild;
		nodeStorage[1] = causedSplit->rightChild;
		nodeStorage[2] = nodeToSplit->middleChild;
		nodeStorage[3] = nodeToSplit->rightChild;
	}
	else if (position == 2)
	{
		nodeStorage[0] = nodeToSplit->leftChild;
		nodeStorage[1] = nodeToSplit->middleChild;
		nodeStorage[2] = causedSplit->leftChild;
		nodeStorage[3] = causedSplit->rightChild;
	}
	else
	{
		nodeStorage[0] = nodeToSplit->leftChild;
		nodeStorage[1] = causedSplit->leftChild;
		nodeStorage[2] = causedSplit->rightChild;
		nodeStorage[3] = nodeToSplit->rightChild;
	}

	//sort the data passed in
	DataType* m = sortThreeData(nodeToSplit->dataL, nodeToSplit->dataR, causedSplit->dataL);

	Node<DataType>* promoted = makeNode(m[1]);
	Node<DataType>* left = makeNode(m[0]);
	Node<DataType>* right = makeNode(m[2]);

	//reassign data to correct positions
	promoted->leftChild = left;
	promoted->rightChild = right;
	left->parent = promoted;
	right->parent = promoted;
	
	if (nodeStorage[0] != NULL)
	{
		left->leftChild = nodeStorage[0];
		left->rightChild = nodeStorage[1];
		(nodeStorage[0])->parent = left;
		(nodeStorage[1])->parent = left;
		right->leftChild = nodeStorage[2];
		right->rightChild = nodeStorage[3];
		(nodeStorage[2])->parent = right;
		(nodeStorage[3])->parent = right;
	}
	return promoted;
}

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::putIn2Node(Node<DataType>* n, DataType toAdd)
{
	Compare comparator;

	if (comparator(toAdd, n->dataL))
	{
		n->dataR = n->dataL;
		n->dataL = toAdd;
	}
	else
	{
		n->dataR = toAdd;
	}
	n->numberData = 2;

}

template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::isLeaf(Node<DataType>* n)
{
	if (n->leftChild == NULL && n->rightChild == NULL && n->middleChild == NULL)
	{
		return true;
	}
	return false;
}

template<typename DataType, typename Compare>
int Tree<DataType, Compare>::positionOfChild(Node<DataType>* parent, Node<DataType>* n)
{
	if (parent->leftChild == n) { return 0; }
	else if (parent->middleChild == n) { return 1; }
	return 2;
}

template<typename DataType, typename Compare>
Node<DataType>* Tree<DataType, Compare>::makeNode(DataType data)
{
	Node<DataType>* node = new Node<DataType>;
	node->dataL = data;
	node->numberData = 1;

	node->rightChild = NULL;
	node->parent = NULL;
	node->leftChild = NULL;
	node->middleChild = NULL;

	return node;
}

template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree()
{
	root = nullptr;
	treeSize = 0;    
}

template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other)
{
	root = other.root;
}

template <typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other)
{
	root = other.root;
}

template <typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree()
{
	delete root;
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data)
{
	if (root == NULL)
	{
		root = makeNode(data);
	}
	else if (isLeaf(root))
	{
		if (root->numberData == 1)
		{
			putIn2Node(root, data);
		}
		else
		{
			root = split(root, makeNode(data), 0);
		}
	}
	else
	{
		insert(root, data);
	}
	treeSize++;
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(Node<DataType>* checkNode, DataType data)
{
	Compare comparator;

	if (isLeaf(checkNode))
	{
		insertUp(checkNode, data);
	}
	else if (checkNode->numberData == 1)
	{
		if (comparator(data, checkNode->dataL))
		{
			insert(checkNode->leftChild, data);
		}
		else
		{
			insert(checkNode->rightChild, data);
		}
	}
	else if (checkNode->numberData == 2)
	{
		if (comparator(data, checkNode->dataL))
		{
			insert(checkNode->leftChild, data);
		}
		else if (comparator(data, checkNode->dataR))
		{
			insert(checkNode->middleChild, data);
		}
		else
		{
			insert(checkNode->rightChild, data);
		}
	}
	
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insertUp(Node<DataType>* checkNode, DataType data)
{
	//if leaf is has one data
	if (checkNode->numberData == 1)
	{
		putIn2Node(checkNode, data);
	}
	else
	{
		int position = positionOfChild(checkNode->parent, checkNode);

		Node<DataType>* promoted;

		promoted = split(checkNode, makeNode(data), position);

		while (checkNode->parent != root)
		{
			if (checkNode->parent->numberData == 1)
			{
				//insert value in the parent then rearrange
				putIn2Node(checkNode->parent, promoted->dataL);

				int position = positionOfChild(checkNode->parent, checkNode);
				if (position == 0)
				{
					checkNode->parent->leftChild = promoted->leftChild;
					checkNode->parent->middleChild = promoted->rightChild;
				}

				else if (position == 2)
				{
					checkNode->parent->middleChild = promoted->leftChild;
					checkNode->parent->rightChild = promoted->rightChild;
				}

				promoted->rightChild->parent = checkNode->parent;
				promoted->leftChild->parent = checkNode->parent;
				//done inserting at this level
				break;

			}
			//split the rest of the parents
			else
			{
				position = positionOfChild(checkNode->parent, checkNode);
				checkNode = checkNode->parent;
				promoted = split(checkNode, promoted, position);
			}
			
		}
		//is root
		if (checkNode->parent == root)
		{
			//where the split comes from
			position = positionOfChild(checkNode->parent, checkNode);
			//root has 1 data
			if (checkNode->parent->numberData == 1)
			{
				putIn2Node(checkNode->parent, promoted->dataL);
				//checkNode is left child
				if (position == 0)
				{
					checkNode->parent->leftChild = promoted->leftChild;
					checkNode->parent->middleChild = promoted->rightChild;
				}
				//checkNode is right child
				else if (position == 2)
				{
					checkNode->parent->middleChild = promoted->leftChild;
					checkNode->parent->rightChild = promoted->rightChild;
				}
				promoted->leftChild->parent = checkNode->parent;
				promoted->rightChild->parent = checkNode->parent;
			}
			else
			{
				//split and update root
				position = positionOfChild(checkNode->parent, checkNode);
				checkNode = checkNode->parent;
				root = split(checkNode, promoted, position);
			}
		}

	}

}

template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const
{
	if (this->size() == 0) { return true; }
    
    return false;
}

template <typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const
{
	return treeSize;
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::SetRoot(Node<DataType>* inputRoot)
{
	root = inputRoot;
}

template<typename DataType, typename Compare>
Node<DataType>* Tree<DataType, Compare>::GetRoot()
{
	return root;
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin()
{
    /* Your code here... */   
	iterator iter;
	iter.setNodePtr(root);

	//need to make go all the way to the left

	while (!(isLeaf( iter.getNodePtr())))
	{
		iter.setNodePtr((iter.getNodePtr())->leftChild);
	}
	iter.setData((iter.getNodePtr())->dataL);

    return iter;
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::end()
{
	   
	iterator iter;
	iter.setNodePtr(root);

	//need to make go all the way to the left

	while (!(isLeaf(iter.getNodePtr())))
	{
		iter.setNodePtr((iter.getNodePtr())->rightChild);
	}
	if ((iter.getNodePtr())->numberData == 2)
	{
		iter.setData((iter.getNodePtr())->dataR);
	}
	else
	{
		iter.setData((iter.getNodePtr())->dataL);
	}
	
	return iter;

}

template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator 
Tree<DataType, Compare>::find_first(KeyType key)
{
    //so you just go through the tree until you find the value, then when you find it you try and go through the left subtree to find the least element. you would go through the right subtree to find the greatest element

	
	typename Tree<DataType, Compare>::iterator first;

	//couldn't figure out how to compare KeyType to the Nodes
	/*
	typename Tree<DataType, Compare>::iterator lastFound;

	Node<DataType>* cursor = root;

	if (empty())
	{
		return first;
	}
	else
	{
		if (cursor->numberData == 1)
		{
			if (cursor->dataL == key)
			{

			}
		}
		else if (cursor->numberData == 2)
		{
			if (cursor->dataL == key)
			{

			}
			else if (cursor->dataR == key)
			{

			}
		}
	}

	*/
    return first;
}

template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator 
Tree<DataType, Compare>::find_last(KeyType key)
{
	//so you just go through the tree until you find the value, then when you find it you try and go through the left subtree to find the least element. you would go through the right subtree to find the greatest element


	typename Tree<DataType, Compare>::iterator first;

	//couldn't figure out how to compare KeyType to the Nodes
	/*
	typename Tree<DataType, Compare>::iterator lastFound;

	Node<DataType>* cursor = root;

	if (empty())
	{
		return first;
	}
	else
	{
		if (cursor->numberData == 1)
		{
			if (cursor->dataL == key)
			{

			}
		}
		else if (cursor->numberData == 2)
		{
			if (cursor->dataL == key)
			{

			}
			else if (cursor->dataR == key)
			{

			}
		}
	}

	*/
	return first;
}

template <typename DataType, typename Compare>
template <typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
          typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key)
{
    /* Your code here... */
    return std::make_pair(iterator(), iterator());
}

template <typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream, const Tree<DataType, Compare> &tree)
{
	Tree<DataType, Compare> newTree;
	newTree.SetRoot(tree.root);

	newTree.begin();

	typename Tree<DataType, Compare>::iterator iter = newTree.begin();

	int height = 1;

	while (iter.getNodePtr() != newTree.root)
	{
		iter.setNodePtr(iter.getNodePtr()->parent);
		iter.setData(iter.getNodePtr()->dataL);
		height++;
	}

	stream << "Level 0\n";

	stream << iter.getData() << endl;

	for (int i = 1; i < height; i++)
	{
		cout << "Level " << i << endl;
		iter = newTree.begin();

		for (iter; iter != newTree.end(); iter++)
		{
			typename Tree<DataType, Compare>::iterator parentCounter = iter;
			
			int numParents = 0;
			while (parentCounter.getNodePtr() != newTree.root)
			{
				parentCounter.setNodePtr(parentCounter.getNodePtr()->parent);
				parentCounter.setData(parentCounter.getNodePtr()->dataL);
				numParents++;
			}
			if (numParents == i)
			{
				stream << iter.getData() << endl;
			}
		}
	}


    return stream;
}

#endif
