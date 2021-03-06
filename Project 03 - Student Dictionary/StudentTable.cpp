#include "StudentTable.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* DONE */ StudentTable::StudentTable()
{
    m_collisionMethod = LINEAR; // default
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        // Initialize students
        m_students[i].key = -1;
        m_students[i].value = "";
    }
}

/* DONE */ void StudentTable::SetCollisionMethod( CollisionMethod cm )
{
    cout << "Collision method: " << cm << endl << endl;
    m_collisionMethod = cm;
}

/* Insert
Take in the studentId (key) and name (value), and
use your hash function to figure out an index
for this new value.
Then, set the values of the Student object in the array.
*/
void StudentTable::Insert( int studentId, const string& name )
{
    // Generate index from the studentId
    // Insert into the m_students array

	int index;
	if (m_collisionMethod == LINEAR)
	{
		index = LinearProbe(studentId);
	}
	else if (m_collisionMethod == QUADRATIC)
	{
		int val = 0;
		index = QuadraticProbe(studentId, val);
	}
	else if (m_collisionMethod == DOUBLE)
	{
		index = HashFunction(studentId);
	}

	m_students[index].value = name;
	m_students[index].key = studentId;
}

/* DONE */ void StudentTable::Output( const string& filename )
{
    cout << "Output table to: " << filename << endl << endl;

    ofstream output( filename );
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        output << i << ".";
        if ( i < 10 )
        {
            output << "   ";
        }
        else if ( i < 100 )
        {
            output << "  ";
        }
        else
        {
            output << " ";
        }

        if ( m_students[i].key != -1 )
        {
            output << "Student ID: " << m_students[i].key << " \t Student Name: " << m_students[i].value;
        }
        output << endl;
    }
    output.close();
}

/* HashFunction
Take in the key and generate an index.
This function should handle collisions, and
the returned index should be the index of an
available "slot" in the array.

Use an if statement to decide which collision
method to use.

if ( m_collisionMethod == LINEAR ) // ...
*/
int StudentTable::HashFunction( int key )
{
	if (m_collisionMethod == LINEAR)
	{
		return LinearProbe(key);
	}
	else if (m_collisionMethod == QUADRATIC)
	{
		int value = 1;
		return QuadraticProbe(key, value);
	}
	else if(m_collisionMethod == DOUBLE)
	{
		return HashFunction2(key);
	}
    return -1; // TEMP
}

/* Linear probing
    You can use my function prototype or write your own.
*/
int StudentTable::LinearProbe( int key )
{
	while (m_students[key].value != "")
	{
		if (key >= TABLE_SIZE)
		{
			key = 0;
		}
		else
		{
			key++;
		}
	}
	return key;
}

/* Quadratic probing
    You can use my function prototype or write your own.
*/
int StudentTable::QuadraticProbe( int key, int& addValue )
{
	while (m_students[key].value != "")
	{
		if (key >= TABLE_SIZE)
		{
			key = 0;
		}
		else
		{
			addValue++;
		}
	}
	return key;
}

/* Double hashing
    You can use my function prototype or write your own.
*/
int StudentTable::HashFunction2( int key )
{
	int key2 = (key % 17) + 1;
	while (m_students[key].value != "")
	{
		if (key >= TABLE_SIZE)
		{
			key = 0;
		}
		else
		{
			key += key2;
		}
	}
	return key;
}
