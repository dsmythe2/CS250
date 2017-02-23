#include "SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	bool testPush = true;

	if (m_itemCount == MAX_SIZE)
	{
		testPush = false;
	}
	else
	{
		m_data[m_itemCount] = newItem;
		m_itemCount++;
	}

	return testPush;
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	bool testInsert = true;

	if (index > this->Size() || index < 0)
	{
		testInsert = false;
	}
	else
	{
		for (int i = this->Size(); i > index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = newItem;
		m_itemCount++;
	}
	return testInsert;
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	bool testExtend = true;

	if (this->Size() + other.Size() > MAX_SIZE)
	{
		testExtend = false;
	}
	else
	{
		for (int i = 0; i < other.Size(); i++)
		{
			this->Push(other.Get(i));
		}
	}
	return testExtend;
}


bool SmartStaticArray::Pop()
{
	bool testPop = true;

	if (m_itemCount == 0)
	{
		testPop = false;
	}
	else
	{
		m_itemCount--;
	}
	return testPop;
}


bool SmartStaticArray::Remove( int index )
{
	bool testRemove = true;

	if (index >= m_itemCount || index < 0)
	{
		testRemove = false;
	}
	else
	{
		for (int i = index; i < MAX_SIZE - 1; i++)
		{
			if (i == MAX_SIZE - 1)
			{
				m_data[i] = "";
			}
			else
			{
				m_data[i] = m_data[i + 1];
			}
		}
		m_itemCount--;
	}
	return testRemove;
}


string SmartStaticArray::Get( int index ) const
{
	if (index >= MAX_SIZE || index < 0)
	{
		return "";
	}
	else
	{
		return m_data[index];
	}
}


int SmartStaticArray::Size() const
{
	return m_itemCount;
}


bool SmartStaticArray::IsFull() const
{
	bool testFull = true;
	
	if (m_itemCount != MAX_SIZE)
	{
		testFull = false;
	}
	
	return testFull;
}

bool SmartStaticArray::IsEmpty() const
{
	bool testEmpty = true;

	if (m_itemCount != 0)
	{
		testEmpty = false;
	}
	return testEmpty;
}


string SmartStaticArray::operator[]( int index )
{
	return this->Get(index);
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->m_data[i] = other.Get(i);
	}
	this->m_itemCount = other.Size();

	return *this; 
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	bool testOp = true;

	if (this->Size() != other.Size())
	{
		testOp = false;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (this->Get(i) != other.Get(i))
		{
			testOp = false;
		}
	}
	return testOp;
}


bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
	return !( *this == other );
}
