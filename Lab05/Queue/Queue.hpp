#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../DoublyLinkedList.hpp"

template <typename T>
class Queue : public DoublyLinkedList<T>
{
    public:
    Queue()
        : DoublyLinkedList<T>()
    {
    }

    virtual ~Queue()
    {
    }

    virtual void Push( T data )
    {
		//Queue pushes to the back of the line
		DoublyLinkedList<T>::PushBack(data);
    }

    virtual void Pop()
    {
		//next person pulled from the line would be pulled from the front
		DoublyLinkedList<T>::PopFront();
    }

    virtual T Take()
    {
		//getfront because the front of the line is who would come next
		return DoublyLinkedList<T>::GetFront();
    }
};

#endif
