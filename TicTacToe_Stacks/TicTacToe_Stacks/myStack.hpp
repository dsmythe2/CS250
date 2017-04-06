#ifndef MYSTACK_HPP
#define MYSTACK_HPP

#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

template <typename T>
class Node
{
public:
	Node()
	{
		m_ptrNext = nullptr;
		m_ptrPrev = nullptr;
	}
	T m_data;
	Node<T>* m_ptrNext;
	Node<T>* m_ptrPrev;
};

template <typename T>
class myStack
{
public:
	myStack()
	{
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
	}
	virtual ~myStack()
	{
		while (m_ptrFirst != nullptr)
		{
			pop();
		}
	}
	void push(T data)
	{
		try
		{
			Node<T>* newNode = new Node<T>();
			newNode->m_data = data;

			if (m_ptrFirst == nullptr)
			{
				m_ptrFirst = newNode;
				m_ptrLast = newNode;
			}
			else
			{
				m_ptrLast->m_ptrNext = newNode;
				newNode->m_ptrPrev = m_ptrLast;
				m_ptrLast = newNode;
			}
			m_itemCount++;
		}
		catch (const bad_alloc& ex)
		{
			throw string("Full Up");
		}
	}
	void pop()
	{
		if (m_ptrLast == nullptr)
		{
			throw out_of_range("The last pointer is a null pointer");
		}
		if (m_ptrFirst == m_ptrLast)
		{
			delete m_ptrLast;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
		}
		Node<T>* Penult = m_ptrLast->m_ptrPrev;
		Penult->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = Penult;
		m_itemCount--;
	}
	T top()
	{
		if (m_ptrLast == nullptr)
		{
			throw out_of_range("The last pointer is a null pointer.");
		}
		return m_ptrLast->m_data;
	}
	int size()
	{
		return m_itemCount;
	}

protected:
	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;
	int m_itemCount;
};

#endif
