#ifndef STACK_HPP
#define STACK_HPP

#include "../DoublyLinkedList.hpp"

template <typename T>
class Stack : public DoublyLinkedList<T>
{
    public:
    Stack()
        : DoublyLinkedList<T>()
    {
    }

    virtual ~Stack()
    {
    }

    virtual void Push( T data )
    {
		//Stack pushed to back of the list
		DoublyLinkedList<T>::PushBack(data);
    }

    virtual void Pop()
    {
		//Stack pops from the back of the stack (pringles can)
		DoublyLinkedList<T>::PopBack();
    }

    virtual T Take()
    {
		//To "take" we need to get the back of the list as that will get pulled out first (pringles can)
		return DoublyLinkedList<T>::GetBack();
    }
};

#endif
