#include "SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray() : m_itemCount(0), m_arraySize(0), m_data(nullptr)
{
}

SmartDynamicArray::~SmartDynamicArray()
{
	Free();
}

//passed
bool SmartDynamicArray::Push( const string& newItem )
{
	if (m_itemCount == m_arraySize)
	{
		Resize();
	}
	m_data[m_itemCount] = newItem;
	m_itemCount++;
	
	return true;
}

// 30 of 31...test 27 "Expected A, B, Z, C, X, D but got A, B, Z, C, Z, D"
bool SmartDynamicArray::Insert( int index, const string& newItem )
{
	bool testArray = true;

	if (index < 0 || index > this->Size())
	{
		testArray = false;
	}
	
	else if (m_itemCount == m_arraySize)
	{
		Resize();

		int i = m_arraySize - 1;
		while (i > index)
		{
			m_data[i] = m_data[i - 1];
			i--;
		}

		m_data[index] = newItem;
		m_itemCount++;
		testArray = true;
	}
	else
	{
		int i = m_arraySize - 1;
		while (i > index)
		{
			m_data[i] = m_data[i - 1];
			i--;
		}

		m_data[index] = newItem;
		m_itemCount++;
		testArray = true;
	}	
	return testArray;
}


bool SmartDynamicArray::Extend( const SmartDynamicArray& other )
{
	Resize(m_itemCount + other.Size());

	for (int i = 0; i < other.Size(); i++)
	{
		this->Push(other.Get(i));
	}
	return true;
}

//passed
bool SmartDynamicArray::Pop()
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

//passed
bool SmartDynamicArray::Remove( int index )
{
	bool testRemove = true;
	if (index < 0 || index >= m_itemCount)
	{
		testRemove = false;
	}
	else
	{
		for (int i = index; i < m_arraySize - 1; i++)
		{
			if (i == m_arraySize - 1)
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

//passed
string SmartDynamicArray::Get( int index ) const
{
	if (index >= m_arraySize || index < 0)
	{
		return "";
	}
	else
	{
		return m_data[index];
	}
	
}

//passed
int SmartDynamicArray::Size() const
{
	return m_itemCount;
}


int SmartDynamicArray::GetMaxSize() const
{
	return m_arraySize;
}

//passed
bool SmartDynamicArray::IsFull() const
{
	if (m_itemCount == m_arraySize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//passed
bool SmartDynamicArray::IsEmpty() const
{
	if (m_itemCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//passed
string SmartDynamicArray::operator[]( int index )
{
	return this->Get(index);
}

//passed
SmartDynamicArray& SmartDynamicArray::operator=( const SmartDynamicArray& other )
{
	Free();
	Resize(other.Size());

	for (int i = 0; i < m_arraySize; i++)
	{
		this->m_data[i] = other.Get(i);
	}
    return *this; 
}

bool SmartDynamicArray::operator==( const SmartDynamicArray& other )
{
	return false; // temp
}


bool SmartDynamicArray::operator!=( const SmartDynamicArray& other )
{
	return false; // temp
}

void SmartDynamicArray::Free()
{
}

void SmartDynamicArray::Resize()
{
	Resize(m_arraySize + 10);
}


void SmartDynamicArray::Resize( int newSize )
{
	string* arr2 = new string[newSize];

	for (int i = 0; i < this->Size(); i++)
	{
		arr2[i] = this->m_data[i];
	}
	Free();
	m_data = arr2;
	m_arraySize = newSize;
}




