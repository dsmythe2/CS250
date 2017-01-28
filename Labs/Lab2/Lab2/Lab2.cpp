#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> LoadData(const string& filename)
{
	// Don't modify this function
	vector<string> list;
	ifstream input(filename);

	string buffer;
	while (getline(input, buffer))
	{
		list.push_back(buffer);
	}

	input.close();

	cout << list.size() << " items loaded" << endl;

	return list;
}

int LinearSearch(const vector<string>& list, string findMe, int& cycleCounter)
{
	// Go from 0, 1, 2, ... to the last item, searching for findMe in the list vector. 
	// Return the position that the item is found at,
	// or -1 if the item is not found.
	cycleCounter = 0;

	for (int i = 0; i < list.size(); i++)
	{
		cycleCounter++;
		if (list[i] == findMe)
		{
			return i;
		}
		if (i == list.size() - 1)
		{
			return -1;
		}
	}
	return cycleCounter;
}

int CustomSearch(const vector<string>& list, string findMe, int& cycleCounter)
{
	// Implement your own search algorithm.
	// Return the position that the item is found at,
	// or -1 if the item is not found.

	cycleCounter = 0;
	for (int i = list.size() - 1; i >= 0; i--)
	{
		cycleCounter++;
		if (list[i] == findMe)
		{
			return i;
		}
		if (i == 0)
		{
			return -1;
		}
	}
	return cycleCounter;
}

int BinarySearch(const vector<string>& list, string findMe, int& cycleCounter)
{
	// Implement the Binary Search algorithm.
	// https://en.wikipedia.org/wiki/Binary_search_algorithm#Algorithm
	// Return the position that the item is found at,
	// or -1 if the item is not found.

	cycleCounter = 0;
	int left = 0;
	int right = list.size() - 1;
	int mid;

	while (left <= right)
	{
		cycleCounter++;
		mid = (left + right) / 2;
		if (list[mid] == findMe)
		{
			return mid;
		}
		else if (cycleCounter == list.size() && list[mid] != findMe)
		{
			return -1;
		}
		else if (list[mid] < findMe)
		{
			left = mid++;
		}
		else if (list[mid] > findMe)
		{
			right = mid--;
		}
	}
	return cycleCounter;
}

int main()
{
	// Don't modify main()
	vector<string> countries = LoadData("countrylist.txt");

	string searchItems[4] = { "Austria", "Yemen", "Curacao", "CS250Land" };

	int cycleCounter;

	// Linear search
	cout << endl << "LINEAR SEARCH" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Linear search - looking for \"" << searchItems[i] << "\"... ";
		int foundPosition = LinearSearch(countries, searchItems[i], cycleCounter);
		cout << "Found at position " << foundPosition << " in " << cycleCounter << " cycles" << endl;
	}

	// Custom search
	cout << endl << "CUSTOM SEARCH" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Custom search - looking for \"" << searchItems[i] << "\"... ";
		int foundPosition = CustomSearch(countries, searchItems[i], cycleCounter);
		cout << "Found at position " << foundPosition << " in " << cycleCounter << " cycles" << endl;
	}

	// Binary search
	cout << endl << "BINARY SEARCH" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Binary search - looking for \"" << searchItems[i] << "\"... ";
		int foundPosition = BinarySearch(countries, searchItems[i], cycleCounter);
		cout << "Found at position " << foundPosition << " in " << cycleCounter << " cycles" << endl;
	}

	while (true)
	{
		return 0;
	}
}