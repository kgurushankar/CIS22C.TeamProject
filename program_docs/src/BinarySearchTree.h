// Binary Search Tree ADT
// Created by A. Student
// Modified by: Joseph Monge

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

template <class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{
private:
    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode<ItemType> *_insert(BinaryNode<ItemType> *nodePtr, BinaryNode<ItemType> *newNode);

    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode<ItemType> *_remove(BinaryNode<ItemType> *nodePtr, const ItemType target, bool &success);

    // delete target node from tree, called by internal remove node
    BinaryNode<ItemType> *deleteNode(BinaryNode<ItemType> *targetNodePtr);

    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode<ItemType> *removeLeftmostNode(BinaryNode<ItemType> *nodePtr, ItemType &successor);

    // search for target node
    BinaryNode<ItemType> *findNode(BinaryNode<ItemType> *treePtr, const ItemType &target) const;

public:
    // insert a node at the correct location
    bool insert(const ItemType &newEntry);
    // remove a node if found
    bool remove(const ItemType &anEntry);
    // find a target node
    bool getEntry(const ItemType &target, ItemType &returnedItem) const;
    // get max
    bool getMax(ItemType &anEntry);
    //get min
    bool getMin(ItemType &anEntry);
};

///////////////////////// public function definitions ///////////////////////////
//Inserting items within a tree
template <class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType &newEntry)
{
    BinaryNode<ItemType> *newNodePtr = new BinaryNode<ItemType>(newEntry);
    this->rootPtr = _insert(this->rootPtr, newNodePtr);
    this->count++;
    return true;
}

//Removing items within a tree
template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &target)
{
    bool isSuccessful = false;
    this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
    if (isSuccessful)
        this->count--;
    return isSuccessful;
}

//Finding entries within a tree
template <class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry, ItemType &returnedItem) const
{
    BinaryNode<ItemType> *obj;

    obj = findNode(this->rootPtr, anEntry);

    if (obj)
    {
        returnedItem = obj->getItem();
        return true;
    }
    return false;
}

//////////////////////////// private functions ////////////////////////////////////////////

//Implementation of the insert operation
template <class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType> *nodePtr,
                                                          BinaryNode<ItemType> *newNodePtr)
{
    if (!nodePtr)
    {
        return newNodePtr;
    }

    else if (nodePtr->getItem() > newNodePtr->getItem())
    {
        BinaryNode<ItemType> *tempPtr = _insert(nodePtr->getLeftPtr(), newNodePtr);
        nodePtr->setLeftPtr(tempPtr);
    }

    else
    {
        BinaryNode<ItemType> *tempPtr = _insert(nodePtr->getRightPtr(), newNodePtr);
        nodePtr->setRightPtr(tempPtr);
    }

    return nodePtr;
}

//Implementation for the search operation
template <class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType> *nodePtr,
                                                           const ItemType &target) const
{
    if (!nodePtr)
    {
        return NULL;
    }
    else if (nodePtr->getItem() == target)
    {
        return nodePtr;
    }
    else if (nodePtr->getItem() > target)
    {
        return findNode(nodePtr->getLeftPtr(), target);
    }
    else
    {
        return findNode(nodePtr->getRightPtr(), target);
    }
}

////////////////////////////////////////////////////////////////////////
// The follwoing functions will be needed for the team project
//Implementation of the remove operation
template <class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType> *nodePtr,
                                                          const ItemType target,
                                                          bool &success)

{
    if (nodePtr == 0)
    {
        success = false;
        return 0;
    }
    if (nodePtr->getItem() > target)
        nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
    else if (nodePtr->getItem() < target)
        nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
    else
    {
        nodePtr = deleteNode(nodePtr);
        success = true;
    }
    return nodePtr;
}
//Implementation of the delete operation
template <class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType> *nodePtr)
{
    if (nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = 0;
        return nodePtr;
    }
    else if (nodePtr->getLeftPtr() == 0)
    {
        BinaryNode<ItemType> *nodeToConnectPtr = nodePtr->getRightPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightPtr() == 0)
    {
        BinaryNode<ItemType> *nodeToConnectPtr = nodePtr->getLeftPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else
    {
        ItemType newNodeValue;
        nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}
//Implementation to remove the left leaf
template <class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType> *nodePtr,
                                                                     ItemType &successor)
{
    if (nodePtr->getLeftPtr() == 0)
    {
        successor = nodePtr->getItem();
        return deleteNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
        return nodePtr;
    }
}

//Implementation to find max
template <class ItemType>
bool BinarySearchTree<ItemType>::getMax(ItemType &anEntry)
{
    // if (this->count == 0)
    //     return false;
    BinaryNode<ItemType> *nodePtr = this->rootPtr;
    while (nodePtr->getRightPtr() != 0)
    {
        nodePtr = nodePtr->getRightPtr();
    }
    anEntry = nodePtr->getItem();
    return true;
}

//Implementation to find min
template <class ItemType>
bool BinarySearchTree<ItemType>::getMin(ItemType &anEntry)
{
    BinaryNode<ItemType> *nodePtr = this->rootPtr;
    while (nodePtr->getLeftPtr() != 0)
    {
        nodePtr = nodePtr->getLeftPtr();
    }
    anEntry = nodePtr->getItem();
    return true;
}
#endif
