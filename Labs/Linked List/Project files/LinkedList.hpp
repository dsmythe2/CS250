#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    Node()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    Node<T>* ptrNext;
    Node<T>* ptrPrev;

    T data;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList() // done
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList() // done
    {
        Free();
    }

    void Push( const T& newItem )
    {
		Node<T>* newNode = new Node<T>;
		newNode->data = newItem;

		if (m_ptrFirst == nullptr)
		{
			m_ptrFirst = newNode;
			m_ptrLast = newNode;
		}
		else
		{
			newNode->ptrPrev = m_ptrLast;
			m_ptrLast->ptrNext = newNode;
			m_ptrLast = newNode;
		}
		m_itemCount++;
    }

    bool Insert( int index, const T& newItem )
    {
		bool testInsert = true;
		if (index < 0 || index > m_itemCount)
		{
			testInsert = false;
		}
		else if (index == m_itemCount)
		{
			this->Push(newItem);
			m_itemCount++;
		}
		else
		{
			Node<T>* ptrCurrent = m_ptrFirst;
			int count = 0;
			while (count < index)
			{
				ptrCurrent = ptrCurrent->ptrNext;
				count++;
			}

			Node<T>* ptrNew = new Node<T>;
			ptrNew->data = newItem;

			ptrNew->ptrNext = ptrCurrent;
			ptrNew->ptrPrev = ptrCurrent->ptrPrev;
			ptrNew->ptrPrev->ptrNext = ptrNew;
			ptrCurrent->ptrPrev = ptrNew;
			m_itemCount++;
		}
		return testInsert;
    }

    void Extend( const LinkedList& other )
    {
		Node<T>* ptrCurrent = other.m_ptrFirst;

		int count = 0;
		while (count < other.Size())
		{
			this->Push(other.Get(count));
			count++;
		}
    }

    bool Pop()
    {
		bool testPop = true;
		if (m_itemCount == 0)
		{
			testPop = false;
		}
		if(m_itemCount == 1)
		{
			delete m_ptrLast;
			m_ptrLast = m_ptrFirst = nullptr;
			m_itemCount--;
		}
		else
		{
			m_ptrLast = m_ptrLast->ptrPrev;
			delete m_ptrLast->ptrPrev;
			m_ptrLast->ptrNext = nullptr;
			m_itemCount--;
		}
		return testPop;
    }

    bool Remove( int index )
    {
		bool testRemove = true;
		if (index < 0 || index >= m_itemCount)
		{
			testRemove = false;
		}
		if (m_itemCount == 1)
		{
			this->Pop();
			m_itemCount--;
		}
		if (index == 0)
		{
			m_ptrFirst = m_ptrFirst->ptrNext;
			delete m_ptrFirst->ptrPrev;
			m_itemCount--;
		}
		else
		{
			Node<T>* ptrCurrent = m_ptrFirst;
			int count = 0;
			while (count < index)
			{
				ptrCurrent = ptrCurrent->ptrNext;
				count++;
			}
			ptrCurrent->ptrPrev->ptrNext = ptrCurrent->ptrNext;
			ptrCurrent->ptrNext->ptrPrev = ptrCurrent->ptrPrev;
			delete ptrCurrent;
			m_itemCount--;
		}
		return testRemove;
    }

    T Get( int index ) const
    {
		if (index < 0 || index >= m_itemCount)
		{
			return T();
		}
		
		Node<T>* ptrCurrent = m_ptrFirst;
		int count = 0;
		while (count < index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			count++;
		}
		return ptrCurrent->data;
    }

    int Size() const // done
    {
        return m_itemCount;
    }

    bool IsEmpty() const // done
    {
        return ( m_ptrFirst == nullptr );
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {
		Free();
		Node<T>* ptrCurrent = other.m_ptrFirst;

		int count = 0;

		while (count < other.Size())
		{
			this->Push(other.Get(count));
			count++;
		}
		return *this;
    }

    bool operator==( const LinkedList& other )
    {
		bool testOp = true;
		if (this->Size() != other.Size())
		{
			testOp = false;
		}
		Node<T>* ptrCurrent = this->m_ptrFirst;
		Node<T>* ptrOther = other.m_ptrFirst;

		int count = 0;
		while (count < this->Size())
		{
			if (ptrCurrent->data != ptrOther->data)
			{
				testOp = false;
			}
			ptrCurrent = ptrCurrent->ptrNext;
			ptrOther = ptrOther->ptrNext;
			count++;
		}
		return testOp;
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif
