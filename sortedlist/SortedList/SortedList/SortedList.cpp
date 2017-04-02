#include <iostream>
#include <string>
using namespace std;

#include "SortedList.hpp"

bool TestSize()
{
	SortedList<int> sl1;
	
	if (sl1.Size() != 0)
	{
		cout << "Failure: Size is not 0" << endl;
		return false;
	}

	SortedList<int> sl2;
	sl2.SortedPush(3);
	
	if (sl2.Size() != 1)
	{
		cout << "Failure: Size is not 1" << endl;
		return false;
	}

	SortedList<int> sl3;
	sl3.SortedPush(3);
	sl3.SortedPush(4);
	sl3.SortedPush(5);

	if (sl3.Size() != 3)
	{
		cout << "Failure: Size is not 3" << endl;
		return false;
	}

	cout << "All TestSizes Passed" << endl;
	return true;
}

bool testPush()
{
	SortedList<int> sl1;
	sl1.SortedPush(1);
	sl1.SortedPush(3);
	sl1.SortedPush(4);
	sl1.SortedPush(2);

	if (sl1[1] != 2)
	{
		cout << "Failure: 2 is not correct" << endl;
		return false;
	}

	SortedList<int> sl2;
	sl2.SortedPush(4);
	sl2.SortedPush(2);

	if (sl2[0] != 2)
	{
		cout << "Failure: Index 0 is not 2" << endl;
		return false;
	}

	SortedList<int> sl3;
	sl3.SortedPush(4);
	sl3.SortedPush(2);
	sl3.SortedPush(3);
	sl3.SortedPush(1);

	if (sl3[3] != 4)
	{
		cout << "Failure: Index 3 is not 4" << endl;
		return false;
	}

	cout << "All TestPushs Passed" << endl;
	return true;
}

bool TestGet()
{
	SortedList<int> sl1;
	sl1.SortedPush(1);
	sl1.SortedPush(3);
	sl1.SortedPush(2);
	sl1.SortedPush(4);

	if (sl1.GetAt(2) != 3)
	{
		cout << "Failure: Expected 3, but did not get" << endl;
		return false;
	}

	SortedList<int> sl2;
	sl2.SortedPush(4);
	sl2.SortedPush(1);

	if (sl2.GetAt(0) != 1)
	{
		cout << "Failure: Index 0 was supposed to return 1" << endl;
		return false;
	}

	SortedList<int> sl3;
	sl3.SortedPush(2);
	sl3.SortedPush(1);
	sl3.SortedPush(4);
	sl3.SortedPush(3);

	if (sl3.GetAt(3) != 4)
	{
		cout << "Failure: Index 3 should be 4" << endl;
		return false;
	}

	cout << "All TestGets Passed" << endl;
	return true;
}

int main()
{
	bool done = false;
	while (!done)
	{
		cout << "1. Test Size" << endl;
		cout << "2. Test Push" << endl;
		cout << "3. Test Get" << endl;
		cout << "4. Quit" << endl;
		cout << ">> ";

		string choice;
		cin >> choice;

		if (choice == "1")
		{
			cout << "TestSize Result: " << TestSize() << endl;
		}
		else if (choice == "2")
		{
			cout << "TestPush result: " << testPush() << endl;
		}
		else if (choice == "3")
		{
			cout << "testGet result: " << TestGet() << endl;
		}
		else if (choice == "4")
		{
			done = true;
		}

	}
	return 0;
}