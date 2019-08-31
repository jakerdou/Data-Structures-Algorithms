/**************************************************************
 * File:    Tree.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * .h file for the Tree class
 * 2-3 tree that can insert and search
 * 
 *************************************************************/

#ifndef TREE_H
#define TREE_H

#include <iterator>
#include <ostream>
#include <utility>
#include "Node.h"

/* 
 * 2-3 Tree class 
 * All nodes in a 2-3 tree either have 1 or 2 keys.
 * Internal nodes that have 1 key have 2 children.
 * Internal nodes that have 2 keys have 3 children.
 * All leaves are at the same level.
 * 
 * For every 2 node n, all modes to the left of n have
 * value less than or equal to n's value, and all values
 * to the right of n have value greater than or equal to
 * n's value.
 *
 * For every 3 node n with key's k1 and k2, all nodes in
 * n's left subtree have value less than k1, all nodes in
 * n's middle subtree have value between, possibly equal to,
 * k1 and k2, and all nodes in n's right subtree have value
 * greater than or equal to k2.
 *
 * Template params:
 * DataType - type of data to be stored in the tree.
 * Compare - functor to compare data so it is stored
 * in sorted order. Calling Compare()(a, b) returns
 * true if a is less than b, and false otherwise.
 */
template <typename DataType, typename Compare = std::less<DataType> >
class Tree
{
private:
	Node<DataType>* root;

	int treeSize;

public:

/**********************************************************************
 * Name: sortThreeData
 * PreCondition: three objects of DataType
 *
 * PostCondition: array of sorted DataType
 *********************************************************************/
	DataType* sortThreeData(DataType one, DataType two, DataType three);
	
/**********************************************************************
 * Name: split
 * PreCondition: The node you want to split, incoming node causing the
 * split, and where that node is coming from
 *
 * PostCondition: a correctly split node
 *********************************************************************/
	Node<DataType>* split(Node<DataType>* nodeToSplit, Node<DataType>* causedSplit, int position);

/**********************************************************************
 * Name: putIn2Node
 * PreCondition: the 2 Node you want to add the data toAdd to
 *
 * PostCondition: 3 Node with the correct data
 *********************************************************************/
	void putIn2Node(Node<DataType>* n, DataType toAdd);

/**********************************************************************
 * Name: isLeaf
 * PreCondition: a node
 *
 * PostCondition: boolean that is true if has no children
 *********************************************************************/
	bool isLeaf(Node<DataType>* n);

/**********************************************************************
 * Name: positionOfChild
 * PreCondition: parent of node and a node
 *
 * PostCondition: integer that is 0, 1, or 2 depending on whether or
 * not the child is the left, middle, or right child respectively
 *********************************************************************/
	int positionOfChild(Node<DataType>* parent, Node<DataType>* n);

/**********************************************************************
 * Name: makeNode
 * PreCondition: data to put in node
 *
 * PostCondition: node with the data in it
 *********************************************************************/
	Node<DataType>* makeNode(DataType data);

    /* Iterator for the tree */
    class iterator;

    /* Default Constructor - construct an empty tree */
    Tree();

    /* Copy constructor */
    Tree(const Tree<DataType, Compare> &other);

    /* Copy assignment */
    Tree &operator=(const Tree<DataType, Compare> &other);

    /* Destructor */
    ~Tree();

    /* Insert the given data into the tree */
    void insert(DataType data);

/**********************************************************************
 * Name: insert
 * PreCondition: node to insert at and data to insert
 *
 * PostCondition: calls insertUp with leaf to insert at
 *********************************************************************/
	void insert(Node<DataType>* checkNode, DataType data);

/**********************************************************************
 * Name: sortThreeData
 * PreCondition: node to insert and data to insert
 *
 * PostCondition: 2-3 tree with correctly inserted data
 *********************************************************************/
	void insertUp(Node<DataType>* checkNode, DataType data);
    
    /* Return whether or not the tree is empty */
    bool empty() const;

    /* Return the number of data items stored in the tree */
    size_t size() const;

	void SetRoot(Node<DataType>*);

	Node<DataType>* GetRoot();

    /* Return an iterator pointing to the first element in the tree */
    iterator begin();

    /* Return an iterator past the end of the tree */
    iterator end();

    /* Return an iterator pointing to the first item in the tree equal to key */
    template <typename KeyType>
    iterator find_first(KeyType key);

    /* Return an iterator pointing to the last item in the tree equal to key */
    template <typename KeyType>
    iterator find_last(KeyType key);

    /* 
     * Return a pair of iterators pointing to the first item 
     * in the tree equal to key, and past the last item 
     * in the tree equal to key.
     */
    template <typename KeyType>
    std::pair<iterator, iterator> find_range(KeyType key);

    /* Level order print of the tree */
    template <typename DataType_, typename Compare_>
    friend std::ostream &operator<<(std::ostream &stream,
                                    const Tree<DataType_, Compare_> &tree);
};

/* Tree iterator that performs in-order traversals */
template <typename DataType, typename Compare>
class Tree<DataType, Compare>::iterator 
    : public std::iterator<std::forward_iterator_tag, DataType>
{
private:
	
	Node<DataType>* nodePtr;
	//the specific data member the iterator is pointing to
	DataType data;
public:

	void setNodePtr(Node<DataType>* ptr);

	void setData(DataType inputData);

	Node<DataType>* getNodePtr();

	DataType getData();

/**********************************************************************
 * Name: findParentSucc
 * PreCondition: iterator that isn't null
 *
 * PostCondition: an iterator of the closest parent of the inputted
 * iterator that has the inputted iterator in its left or middle subtree
 *********************************************************************/
	iterator findParentSucc(iterator iter);

/**********************************************************************
 * Name: leftMost
 * PreCondition: iterator that isn't null
 *
 * PostCondition: iterator of left most element of left subtree of
 * inputted iterator
 *********************************************************************/
	iterator leftMost(iterator iter);
	
    /* Default constructor - creates past-the-end iterator */
    iterator();

    /* Copy constructor */
    iterator(const iterator &other);

    /* Copy assignment */
    iterator &operator=(const iterator &other);

    /* Return whether or not two iterators are pointing at the same place */
    bool operator==(const iterator &other) const;

    /* Return whether or not two iterators are not pointing at the same place */
    bool operator!=(const iterator &other) const;

    /* Return the data the iterator is pointing to */
    DataType operator*() const;

    /* Advance to the current data's successor */
    iterator &operator++();

    /* Advance to the current data's successor */
    iterator operator++(int unused);
};

#include "Tree.cpp"
#include "TreeIterator.cpp"

#endif
