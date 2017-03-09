#ifndef LIST_HPP
#define LIST_HPP

#include <string>
using namespace std;

struct listException : public exception
{
	listException(const string& message)
	{
		m_message = message;
	}
	const char* what()
	{
		return m_message.c_str();
	}
private:
	string m_message;
};

class List
{
public:
	List();

	void Insert(string newItem, int position);
	void Delete(int position);
	string GetItem(int position);

private:
	string m_data[3];
	int m_itemCount;
	int m_arraySize;
};

#endif
