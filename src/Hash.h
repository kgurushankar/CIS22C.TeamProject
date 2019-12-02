
#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <list>
#include "LinkedList.h"
using namespace std;
template <class ItemType>
class HashTable
{
private:
	LinkedList<ItemType> *hashList;
	int size;
	int count;
	int load;

public:
	HashTable(int s = 128)
	{
		count = 0;
		load = 0;
		size = s;
		hashList = new LinkedList<ItemType>[size];
	}
	~HashTable();
	int getCount() { return count; }
	int getSize() { return size; }
	bool isEmpty() { return count == 0; }
	bool insertHash(ItemType &item);
	bool deleteHash(ItemType &target);
	bool searchHash(ItemType &target, ItemType &returnedItem);
	int hash(int key);
	int badHash(int key);
	void printHash(void visit(ItemType &));
};
#endif
template <class ItemType>
int HashTable<ItemType>::hash(int key)
{
	return key % size;
}

template <class ItemType>
int HashTable<ItemType>::badHash(int key)
{
	return key % size;
}

template <class ItemType>
bool HashTable<ItemType>::insertHash(ItemType &item)
{
	int hashKey = hash(item.getKey());
	if (hashList[hashKey].isEmpty())
	{
		load++;
	}
	count++;
	return hashList[hashKey].insertNode(item);
}

template <class ItemType>
bool HashTable<ItemType>::deleteHash(ItemType &target)
{
	return hashList[hash(target.getKey())].deleteNode(target);
}
template <class ItemType>
bool HashTable<ItemType>::searchHash(ItemType &target, ItemType &returnItem)
{
	return hashList[hash(target.getKey())].searchList(target, returnItem);
}
template <class ItemType>
void HashTable<ItemType>::printHash(void visit(ItemType &))
{
	for (int i = 0; i < getCount(); i++)
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
	for (int i = 0; i < size; i++)
	{
		cout << "DEBUG - Destructor: Now deleting index " << i << endl;
		delete hashList[i];
	}
}