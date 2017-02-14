#include "SmartStaticArray.hpp"

void SmartStaticArray::Start()
{
	SmartStaticArray arr;

	arr.Size();
	arr.Push("45");
	
}

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push(const string& newItem)
{
	bool checkArray = true;
	SmartStaticArray arr;

	//Test to see if the array is full, if not add new item
	if (m_itemCount == MAX_SIZE)
	{
		cout << "Array is full and cannot have a new item added" << endl;
		checkArray = false;
	}
	else
	{
		arr[m_itemCount] = newItem;
		cout << newItem << " added to the array" << endl;
		m_itemCount++;
	}
	return checkArray;
}


bool SmartStaticArray::Insert(int index, const string& newItem)
{
	bool checkArray = true;
	SmartStaticArray arr;

	//Test if the array is full, insert new item if not

	if (m_itemCount == MAX_SIZE)
	{
		cout << "Error: Array is full, cannot insert new item" << endl;
		checkArray = false;
	}
	else
	{
		for (int i = m_itemCount - 1; i > index; i--)
		{
			arr[i] = arr[i + 1];
			cout << "Index " << i << " changed to " << i + 1 << endl;
		}
		arr[index] = newItem;
		m_itemCount++;
	}
	return checkArray;
}


bool SmartStaticArray::Extend(const SmartStaticArray& other)
{
	bool testArray = true;
	SmartStaticArray arr1, arr2, arr3;

	arr1.Push("1");
	arr1.Push("2");
	arr1.Push("3");
	arr1.Push("4");

	arr3.Push("1");
	arr3.Push("2");
	arr3.Push("3");
	arr3.Push("4");

	if (arr1.Extend(arr2) != true)
	{
		cout << "Extend function did not work" << endl;
		testArray = false;
	}

	if ((arr1 == arr3) == false)
	{
		cout << "Extending the array did not work correctly" << endl;
		testArray = false;
	}

	SmartStaticArray arr4, arr5;
	for (int i = 0; i < MAX_SIZE - 2; i++)
	{
		arr4.Push("Hello");
		arr5.Push("World");
	}

	if (arr4.Extend(arr5) != false)
	{
		cout << "Error: Tried to extend past the array size, should have returned false" << endl;
		testArray = false;
	}

	if (testArray)
	{
		cout << "Extend tests passed" << endl;
	}
	
	return testArray;
}


bool SmartStaticArray::Pop()
{
	bool checkArray = true;
	SmartStaticArray arr;
	 
	//Test to see if there are items in the array, if so remove the item in the front
	if (m_itemCount == 0)
	{
		cout << "Cannot pop the array as it is empty" << endl;
		checkArray = false;
	}
	else
	{
		for (int i = m_itemCount - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
			cout << "Index " << i << " changed to " << i - 1 << endl;
		}
		m_itemCount--;
	}
	return checkArray;
}


bool SmartStaticArray::Remove(int index)
{
	bool testArray = true;
	SmartStaticArray arr;

	if (index > m_itemCount - 1)
	{
		cout << "Array does not contain an entry and specified index" << endl;
		testArray = false;
	}
	else
	{
		//start at the index array and begin replacing
		for (int i = index; i < MAX_SIZE; i++)
		{
			arr[i] = arr[i + 1];
			cout << "Index " << i << " has been replaced with " << i + 1 << endl;
		}
	}	
	m_itemCount--;
	return testArray;
}


string SmartStaticArray::Get(int index) const
{
	SmartStaticArray arr;

	//return value of the array at the index
	return arr[index];
}


int SmartStaticArray::Size() const
{
	//m_itemCount should indicate what the current size of the array is
	cout << "Current size of the array is " << m_itemCount << endl;
	return m_itemCount;
}


bool SmartStaticArray::IsFull() const
{
	bool checkArray = true;

	//Check to see if array is full

	if (m_itemCount != MAX_SIZE)
	{
		cout << "Array is not full" << endl;
		checkArray = false;
	}
	else
	{
		cout << "Arry is currently full" << endl;
	}
	return checkArray;
}

bool SmartStaticArray::IsEmpty() const
{
	bool checkArray = true;

	//Check to see if the array is empty
	if (m_itemCount != 0)
	{
		cout << "The array is not empty" << endl;
		checkArray = false;
	}
	else
	{
		cout << "The array is currently empty" << endl;
	}
	return checkArray;
}


string SmartStaticArray::operator[](int index)
{
	SmartStaticArray arr;

	return arr[index]; 
}


SmartStaticArray& SmartStaticArray::operator=(const SmartStaticArray& other)
{
	SmartStaticArray arr, arr2;
	
	for (int i = 0; i < m_itemCount; i++)
	{
		arr[i] = arr2[i];
	}
	return arr2;
}

bool SmartStaticArray::operator==(const SmartStaticArray& other)
{
	bool testArray = true;
	SmartStaticArray arr, arr2;

	for (int i = 0; i < m_itemCount; i++)
	{
		if (arr[i] != arr2[i])
		{
			cout << "Error: Array 1 does not equal Array 2" << endl;
			testArray = false;
		}
	}
	return testArray;
}


bool SmartStaticArray::operator!=(const SmartStaticArray& other)
{
	return !(*this == other);
}