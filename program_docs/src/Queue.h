/**~*~*
   Queue template
*~**/
#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>
using namespace std;

// Structure for the queue nodes
template <class T>
struct QueueNode
{
    T value;         // Value in the node
    QueueNode *next; // Pointer to next node
};

template <class T>
class Queue
{

private:
    QueueNode<T> *front; // Pointer to the queue front
    QueueNode<T> *rear;  // Pointer to the queue rear
    int count;

public:
    //Constructor
    Queue();
    // Destructor
    ~Queue();

    // Queue operations
    bool enqueue(T);
    bool dequeue(T &);
    bool isEmpty();
    int getCount();
    bool queueFront(T &);
    bool queueRear(T &);
    void print();
    // template <class T>
    // friend ostream &operator<<<T>(ostream &, Queue<T> &);
};
/**~*~*
   Constructor
*~**/
template <class T>
Queue<T>::Queue()
{
    front = rear = NULL;
    count = 0;
}

/**~*~*
  Member function getCount returns
  the number of elements in the queue
*~**/
template <class T>
int Queue<T>::getCount()
{
    return count;
}

/**~*~*
  Member function isEmpty returns true if the stack
  is empty, or false otherwise.
*~**/
template <class T>
bool Queue<T>::isEmpty()
{
    return count == 0;
}

/**~*~*
  Member function enqueue inserts the argument into
  the queue.
*~**/
template <class T>
bool Queue<T>::enqueue(T item)
{
    QueueNode<T> *newNode; // Pointer to a new node

    // Allocate a new node and store num there.
    newNode = new QueueNode<T>;
    if (!newNode)
        return false;
    newNode->value = item;

    // Update links and counter
    newNode->next = NULL;

    if (front == NULL) // insert to an empty queue
        front = rear = newNode;
    else
        rear->next = newNode;

    count++;
    rear = newNode;

    return true;
}

/**~*~*
  Member function dequeue deletes the value at the front
  of the queue, and copies it into the variable
  passed as an argument.
*~**/
template <class T>
bool Queue<T>::dequeue(T &item)
{
    QueueNode<T> *pDel; // Temporary pointer

    // empty queue
    if (count == 0)
        return false;

    // delete the value at the front of the queue
    item = front->value;
    pDel = front;

    if (count == 1)
        rear = NULL;
    front = front->next;

    count--;
    delete pDel;

    return true;
}

/**~*~*
  Member function queueFront copies the value at the front
  of the queue into the variable passed as an argument.
*~**/
template <class T>
bool Queue<T>::queueFront(T &item)
{
    if (front == NULL)
        return false;

    item = front->value;

    return true;
}

/**~*~*
  Member function queueRear copies the value at the rear
  of the queue into the variable passed as an argument.
*~**/
template <class T>
bool Queue<T>::queueRear(T &item)
{
    if (rear == NULL)
        return false;

    item = rear->value;
    return true;
}

/**~*~*
  Prints data to cout
*~**/
template <class T>
void Queue<T>::print()
{
    QueueNode<T> *node = front;
    if (isEmpty())
    {
        cout << "Empty Queue";
    }
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
}

/**~*~*
   Destructor
*~**/
template <class T>
Queue<T>::~Queue()
{
    QueueNode<T> *currNode, *nextNode;

    // Position nodePtr at the top of the stack.
    currNode = front;
    // Traverse the list deleting each node.
    while (currNode) //while (currNode != NULL)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

// template <class T>
// ostream &operator<<<T>(ostream &out, Queue<T> &q)
// {
//     QueueNode<T> *node = q.front;
//     if (q.isEmpty())
//     {
//         out << "Empty Queue";
//         return out;
//     }
//     while (node != NULL)
//     {
//         out << node->value;
//         node = node->next;
//     }
//     return out;
// }

#endif
