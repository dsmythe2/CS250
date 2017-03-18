#include <iostream>
using namespace std;

#include "List.hpp"

int main()
{
	List myList;

	string menu[] = { "Insert", "Delete", "Get Item" };

	while (true)
	{
		cout << endl << "-------------------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i << ". " << menu[i] << endl;
		}

		int choice;
		cout << "Which? ";
		cin >> choice;

		if (choice == 0)
		{
			int position;
			string newItem;

			cout << "Index: ";
			cin >> position;

			cout << "New value: ";
			cin >> newItem;

			try
			{
				myList.Insert(newItem, position);
			}
			catch(listException ex)
			{
				cout << "Insert Exception! " << ex.what() << endl;
			}

			
		}
		else if (choice == 1)
		{
			int position;

			cout << "Index: ";
			cin >> position;

			try
			{
				myList.Delete(position);
			}
			catch(listException ex)
			{
				cout << "Delete Exception! " << ex.what() << endl;
			}
			
		}
		else if (choice == 2)
		{
			int position;

			cout << "Index: ";
			cin >> position;

			try
			{
				string item = myList.GetItem(position);
				cout << "Item is " << item << endl;
			}
			catch (listException ex)
			{
				cout << "Get Exception! " << ex.what() << endl;
			}
		}
	}

	return 0;
}