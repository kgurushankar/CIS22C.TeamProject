#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>
template <class ItemType>
class ListNode
{
private:
	ItemType value;
	ListNode<ItemType> *next;
	ListNode<ItemType> *back;

public:
	//Constructor
	ListNode(){};
	ListNode(ItemType v, ListNode *n, ListNode *b)
	{
		value = v;
		next = n;
		back = b;
	}

	//Setter
	void setNext(ListNode *n) { next = n; }
	void setBack(ListNode *b) { back = b; }
	void setItem(ItemType c) { value = c; }

	//Getter
	ListNode *getNext() const { return next; }
	ListNode *getBack() const { return back; }
	ItemType getItem() const { return value; }
};
#endif