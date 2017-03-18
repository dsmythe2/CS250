#include "List.hpp"

List::List()
{
	m_itemCount = 0;
	m_arraySize = 3;
}

void List::Insert(string newItem, int position)
{
	if (position < 0 || position >= m_itemCount)
	{
		throw listException("Postion selected out of range[0]!");
	}
	else
	{
		m_data[position] = newItem;
		m_itemCount++;
	}	
}

void List::Delete(int position)
{
	if (position < 0 || position >= m_itemCount)
	{
		throw listException("Postion selected out of range[1]!");
	}
	else
	{
		m_data[position] = "";
		m_itemCount--;
	}	
}

string List::GetItem(int position)
{
	if (position < 0 || position >= m_itemCount)
	{
		throw listException("Position entered is out of range[2]");
	}
	else
	{
		return m_data[position];
	}
}