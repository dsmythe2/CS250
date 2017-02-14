#ifndef _SMART_STATIC_ARRAY_HPP
#define _SMART_STATIC_ARRAY_HPP

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 5;

class SmartStaticArray
{
public:
	void Start();

	SmartStaticArray();

	bool Push(const string& newItem);
	bool Insert(int index, const string& newItem);
	bool Extend(const SmartStaticArray& other);

	bool Pop();
	bool Remove(int index);

	string Get(int index) const;

	int Size() const;
	bool IsFull() const;
	bool IsEmpty() const;

	string operator[](int index);
	SmartStaticArray& operator=(const SmartStaticArray& other);
	bool operator==(const SmartStaticArray& other);
	bool operator!=(const SmartStaticArray& other);

private:
	string m_data[MAX_SIZE];
	int m_itemCount;
};

#endif