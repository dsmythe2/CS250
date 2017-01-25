#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "Page.h"

// Updated function call with vector
void LoadPages(vector <Page>& pages, const string& filename)
{
	ifstream input(filename);
	string line;
	string pageText = "";
	int lineCount = 0;
	int pageCount = 0;

	while (getline(input, line))
	{
		pageText = pageText + "\n" + line;

		lineCount++;
		if (lineCount == 27)
		{
			Page newPage;
			// Add page to book now
			newPage.text = pageText;
			pages.push_back(newPage);

			//pages[pageCount].text = pageText;
			pageCount++;

			// Reset the page text
			pageText = "";

			// Reset the line count
			lineCount = 0;
		}
		// Get rid of this chunk of code
		/*
		if (pageCount == 100)
		{
			// The book is full! Can't load any more.
			return;
		}
		*/
	}

	input.close();
}

// Updated function call with vector
void ReadBook(vector <Page>& pages)
{
	int currentPage = 0;
	// Updated varible with size of vector
	int totalPages = pages.size();

	bool done = false;

	while (!done)
	{
		pages[currentPage].Display();
		cout << "--- PAGE " << currentPage + 1 << " OF " << totalPages << "---------------------------------" << endl;
		cout << "(N)ext Page, (P)revious Page, (Q)uit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "Q" || choice == "q")
		{
			done = true;
		}
		else if (choice == "N" || choice == "n")
		{
			if (currentPage + 1 < totalPages)
			{
				currentPage++;
			}
		}
		else if (choice == "P" || choice == "p")
		{
			if (currentPage - 1 >= 0)
			{
				currentPage--;
			}
		}
	}
}

int main()
{
	//Page pages[100];
	vector < Page > pages;

	LoadPages(pages, "Aesop.txt");
	ReadBook(pages);

	return 0;
}