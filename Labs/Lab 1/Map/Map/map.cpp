#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	// Create a map that uses two strings. Name it colors.
	map<string, string> colors;

	// Populate several colors and their hex codes
	// red = FF0000, green = 00FF00, blue = 0000FF
	// magenta = FF00FF, yellow = FFFF00, cyan = 00FFFF
	
	colors["red"] = "F00";
	colors["green"] = "0F0";
	colors["blue"] = "00F";
	colors["magenta"] = "F0F";
	colors["yellow"] = "FF0";
	colors["cyan"] = "0FF";

	string color;
	cout << "Enter a color: ";
	cin >> color;

	// Display the hex value of the color, using the user's input as a key.
	cout << "Hex short code for " << color << " = " << colors[color];


	return 0;
}