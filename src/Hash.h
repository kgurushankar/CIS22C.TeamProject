

#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>
#include "LinkedList.h"
#include <cmath>
#include <string>
#define LOAD_FACTOR 75
using namespace std;
template <class ItemType>
class HashTable
{
private:
	LinkedList<ItemType> *hashList;
	int arraySize;
	int getHashIndex(string input);
	int calcPrime(int size);
	void resize();

public:
	//Constructor
	HashTable(int s = 127)
	{
		arraySize = calcPrime(s);
		hashList = new LinkedList<ItemType>[arraySize];
	}
	// Destructor
	~HashTable();
	//
	int getSize() { return arraySize; }
	bool isEmpty() { return arraySize == 0; }
	void insertHash(ItemType &item);
	bool deleteHash(ItemType &target);
	bool searchHash(ItemType &target, ItemType &returnedItem);
	void printHash(void visit(ItemType &));

	// The statistics functions
	double calcLoadFactor();
	int collisions();
	int amountLinkedLists();
	void longestLinkedList(void visit(ItemType &));
	double avgNumNodes();
};
template <class ItemType>
void HashTable<ItemType>::resize()
{
	HashTable<ItemType> newHashTable = HashTable<ItemType>(arraySize * 2 + 1); //keep it odd to try to avoid multiples of 2

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < hashList[i].getCount(); j++)
		{
			ItemType item;

			if (hashList[i].getEntry(j, item))
			{
				newHashTable.insertHash(item);
			}
		}
	}

	for (int i = 0; i < arraySize; i++)
		hashList[i].clear();

	arraySize = newHashTable.arraySize;
	hashList = newHashTable.hashList;

	newHashTable.arraySize = 0;
	newHashTable.hashList = NULL;
	// otherwise desctructor of newHashTable will destroy rehashed data
}
template <class ItemType>
int HashTable<ItemType>::calcPrime(int size)
{
	while (true)
	{
		bool isPrime = false;

		if (size < 2)
		{
			isPrime = false;
		}
		else
		{
			for (int i = 2; true; ++i)
			{
				int q = size / i;

				if (q < i)
				{
					isPrime = true;
					break;
				}

				if (size == q * i)
				{
					isPrime = false;
					break;
				}
			}
		}

		if (isPrime)
		{
			break;
		}

		size++;
	}

	return size;
}

template <class ItemType>
int HashTable<ItemType>::getHashIndex(string input)
{
	int index = 0;
	int cube;

	for (int i = 0; i < input.length(); i++)
	{
		cube = static_cast<int>(pow(input[i], 3.0));
		index += cube;
	}

	if (index >= arraySize)
		index = index % arraySize;

	return index;
}

template <class ItemType>
void HashTable<ItemType>::insertHash(ItemType &item)
{
	int hashKey = getHashIndex(item.hashString());
	hashList[hashKey].insertNode(item);
	if (calcLoadFactor() > LOAD_FACTOR)
	{
		resize();
	}
}

template <class ItemType>
bool HashTable<ItemType>::deleteHash(ItemType &target)
{
	int key = getHashIndex(target.hashString());
	return hashList[key].deleteNode(target);
}

template <class ItemType>
bool HashTable<ItemType>::searchHash(ItemType &target, ItemType &returnItem)
{
	int key = getHashIndex(target.hashString());
	return hashList[key].searchList(target, returnItem);
}

template <class ItemType>
void HashTable<ItemType>::printHash(void visit(ItemType &))
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Hash index " << i << ": ";
		hashList[i].tranverseForward(visit);
		if (hashList[i].isEmpty())
			cout << "Empty" << endl;
		else
			cout << endl;
	}
}

template <class ItemType>
HashTable<ItemType>::~HashTable()
{
	for (int i = 0; i < arraySize; i++)
	{
#ifdef DEBUG
		cout << "DEBUG - Destructor: Now deleting index " << i << endl;
#endif
		delete (hashList + i);
	}
}
template <class ItemType>
double HashTable<ItemType>::calcLoadFactor()
{
	int counter = 0;
	double loadFactor;
	for (int i = 0; i < arraySize; i++)
	{
		if (hashList[i].getCount() > 0)
			counter++;
	}
	loadFactor = static_cast<double>(counter) / arraySize * 100;
	return loadFactor;
}
template <class ItemType>
int HashTable<ItemType>::collisions()
{
	int numCollisions = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (hashList[i].getCount() > 0)
			numCollisions += hashList[i].getCount() - 1;
	}
	return numCollisions;
}
template <class ItemType>
void HashTable<ItemType>::longestLinkedList(void visit(ItemType &))
{
	int longest = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (hashList[i].getCount() > longest)
			longest = hashList[i].getCount();
	}
	for (int i = 0; i < arraySize; i++)
	{
		if (hashList[i].getCount() == longest)
		{
			cout << hashList[i].tranverseForward(visit);
			cout << endl;
		}
	}
}
template <class ItemType>
int HashTable<ItemType>::amountLinkedLists()
{
	int numLinkedLists = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (hashList[i].getCount() > 1)
			numLinkedLists++;
	}
	return numLinkedLists;
}
template <class ItemType>
double HashTable<ItemType>::avgNumNodes()
{
	return (static_cast<double>(collisions())) / amountLinkedLists();
}

#endif
