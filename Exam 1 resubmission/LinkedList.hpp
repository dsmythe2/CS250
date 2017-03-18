#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node
{
    Node()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    Node* ptrNext;
    Node* ptrPrev;

    int data;
};

class CoordPairLinkedList
{
    public:
    CoordPairLinkedList()
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~CoordPairLinkedList()
    {
        Free();
    }

    /* START OF STUDENT SECTION **************************************/

    /*
      Push two items to the Linked List at a time: x and y
    */
    void Push2( int x, int y )
    {
      Node* newNodeX = new Node;
      newNodeX->data = x;

      Node* newNodeY = new Node;
      newNodeY->data = y;

      // Do the thing!
	  if (m_ptrFirst == nullptr)
	  {
		  m_ptrFirst = newNodeX;
		  m_ptrLast = newNodeY;

		  newNodeX->ptrNext = newNodeY;
		  newNodeY->ptrPrev = newNodeX;
	  }
	  else
	  {
		  newNodeX->ptrPrev = m_ptrLast;
		  newNodeX->ptrNext = newNodeY;
		  newNodeY->ptrPrev = newNodeX;
		  newNodeY->ptrNext = nullptr;
		  m_ptrLast->ptrNext = newNodeX;
		  m_ptrLast = newNodeY;		  
	  }
	  m_itemCount += 2;
    }

    /*
      Remove a pair of items from the list at a time
    */
    bool Pop2()
    {
        if ( m_ptrLast == nullptr ) { return false; }

        // These might be useful:
        // Node* secondFromLast = m_ptrLast->ptrPrev;
        // Node* thirdFromLast = secondFromLast->ptrPrev;
        // Node* fourthFromLast = thirdFromLast->ptrPrev;

		else if (m_ptrLast == m_ptrFirst)
		{
			return false;
		}

		else
		{
			Node* secondFromLast = m_ptrLast->ptrPrev;
			Node* thirdFromLast = secondFromLast->ptrPrev;
			
			if (secondFromLast == m_ptrFirst)
			{
				delete m_ptrFirst;
				m_ptrFirst = nullptr;

				delete m_ptrLast;
				m_ptrLast = nullptr;

				//m_ptrFirst->ptrPrev = nullptr;
				//m_ptrLast->ptrNext = nullptr;

				/* 
					if list is emptied do we not still need to set up the ptrPrev and ptrNext?
				nullPtr <-> m_ptrFist(nullPtr) <-> m_ptrLast(nullPtr) <-> nullPtr
				
				*/
			}
			else
			{
				delete m_ptrLast;
				delete secondFromLast;
				m_ptrLast = thirdFromLast;
				m_ptrLast->ptrNext = nullptr;
			}
			m_itemCount -= 2;
		}

		return true;
    }

    /* END OF STUDENT SECTION **************************************/

    bool Pop()
    {
        if ( m_ptrLast == nullptr )
        {
            // do nothing
            return false;
        }

        if ( m_ptrLast == m_ptrFirst )
        {
            delete m_ptrLast;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
        }
        else
        {
            // Remove the last item and update the 2nd-
            // to-last item to be the new last
            Node* penultimate = m_ptrLast->ptrPrev;
            delete m_ptrLast;
            m_ptrLast = penultimate;
            penultimate->ptrNext = nullptr;
            m_itemCount--;
        }

        return true;
    }

    void Display()
    {
        cout << endl << "Display List:" << endl;
        int counter = 0;
        Node* ptrCurrent = m_ptrFirst;
        while ( ptrCurrent != nullptr )
        {
          cout << counter << ": " << ptrCurrent->data << "\t\t";
          if ( counter % 3 == 0 && counter != 0 ) { cout << endl; }
          ptrCurrent = ptrCurrent->ptrNext;
          counter++;
        }
        cout << endl;
    }

    int Size() const
    {
        return m_itemCount;
    }

    bool IsEmpty() const
    {
        return ( m_ptrFirst == nullptr );
    }

    int Get( int index ) const
    {
        if ( index < 0 || index >= m_itemCount )
        {
            // Return a new T item...
            return 0;
        }

        // Locate item
        Node* ptrCurrent = m_ptrFirst;
        int counter = 0;
        while ( counter != index )
        {
            ptrCurrent = ptrCurrent->ptrNext;
            counter++;
        }

        return ptrCurrent->data;
    }

    int operator[]( int index )
    {
        return Get( index );
    }

    private:
    void Free()
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node* m_ptrFirst;
    Node* m_ptrLast;
    int m_itemCount;
};

#endif
