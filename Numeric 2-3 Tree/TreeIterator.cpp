#ifndef TREE_ITERATOR_CPP
#define TREE_ITERATOR_CPP

#include <iostream>
#include "Tree.h"

template <typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator()
{
	nodePtr = nullptr;
	data = NULL;

	
    //has to be null here but can use member funcs of tree in get first and others
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::iterator::setNodePtr(Node<DataType>* ptr)
{
	nodePtr = ptr;
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::iterator::setData(DataType inputData)
{
	data = inputData;
}

template <typename DataType, typename Compare>
Node<DataType>* Tree<DataType, Compare>::iterator::getNodePtr()
{
	return nodePtr;
}

template <typename DataType, typename Compare>
DataType Tree<DataType, Compare>::iterator::getData()
{
	return data;
}

template <typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(const iterator &other)
{
    /* Your code here... */
	this->nodePtr = other.nodePtr;
	this->data = other.data;

}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator=(const iterator &other)
{
    /* Your code here... */
	this->nodePtr = other.nodePtr;
	this->data = other.data;

    return *this;
}

template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator==(const iterator &other) const
{
	if (nodePtr == other.nodePtr && data == other.data) { return true; }
	return false;
}

template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator!=(const iterator &other) const
{
	if (nodePtr == other.nodePtr && data == other.data) { return false; }
	return true;
}

template <typename DataType, typename Compare>
DataType Tree<DataType, Compare>::iterator::operator*() const
{
    /* Your code here... */
	return data;
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator++()
{
	Tree<DataType, Compare> tempTree;
	iterator placeholder;

    //How many data does the node have?
	if (nodePtr->numberData == 1)
	{
		//Does it have subtrees?
		//CASE 2
		if (tempTree.isLeaf(nodePtr))
		{
			
			placeholder = findParentSucc(*this);

			//need to put in placeholder to put in this node
			
		}
		//CASE 1
		else
		{
			placeholder = *this;
			placeholder.nodePtr = placeholder.nodePtr->rightChild;

			placeholder = leftMost(placeholder);
		}
	}
	else if (nodePtr->numberData == 2)
	{
		
		if (tempTree.isLeaf(nodePtr))
		{
			//CASE 5
			if (data == nodePtr->dataL)
			{
				placeholder = *this;
				placeholder.data = nodePtr->dataR;
			}
			//CASE 6
			else if (data == nodePtr->dataR)
			{
				placeholder = findParentSucc(*this);
			}
		}
		else
		{
			//CASE 3
			if (data == nodePtr->dataL)
			{
				placeholder = *this;
				placeholder.nodePtr = placeholder.nodePtr->middleChild;

				placeholder = leftMost(placeholder);
			}
			//CASE 4
			else if (data == nodePtr->dataR)
			{
				placeholder = *this;
				placeholder.nodePtr = placeholder.nodePtr->rightChild;

				placeholder = leftMost(placeholder);
			}
		}
		
	}

	nodePtr = placeholder.nodePtr;
	data = placeholder.data;

    return *this;
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::iterator::operator++(int unused)
{
	return this->operator++();
}


template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::iterator::findParentSucc(iterator iter)
{
	Tree<DataType, Compare> tempTree;

	int position = 2;
	while (position == 2)
	{
		Node<DataType>* p = (iter.getNodePtr())->parent;
		position = tempTree.positionOfChild(p, iter.getNodePtr());
		iter.setNodePtr(p);
	}

	//How many data elements?
	if (iter.getNodePtr()->numberData == 1)
	{
		iter.setData(iter.getNodePtr()->dataL);
	}
	else if (iter.getNodePtr()->numberData == 2)
	{
		//if it was the left child
		if (position == 0)
		{
			iter.setData(iter.getNodePtr()->dataL);
		}
		else if (position == 1)
		{
			iter.setData(iter.getNodePtr()->dataR);
		}
	}

	return iter;
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::iterator::leftMost(iterator iter)
{
	Tree<DataType, Compare> tempTree;
	while (!(tempTree.isLeaf(iter.nodePtr)))
	{
		iter.nodePtr = iter.nodePtr->leftChild;
	}
	iter.data = iter.nodePtr->dataL;

	return iter;
}


#endif
