#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	// Create a queue of floats, named transactions	
	queue<float> transactions;

	// Push some + and - floats into the transactions queue.	
	float input = 1.00;

	cout << "Input your transactions (Enter \".00\" when complete)" << endl;

	while (input != .00)
	{
		cout << "Transaction: ";
		cin >> input;
		transactions.push(input);
	}


	// Loop through all the transactions - while the queue is empty.
	// Within the loop, whatever amount is at the front of the queue,
	// add it to the balance and then pop it off the queue.
	while (!transactions.empty())
	{
		float amount = transactions.front();
		
		if (transactions.front() == .00)
		{
			transactions.pop();
		}
		else
		{
			cout << "Transaction: " << amount << " added to the register." << endl;
			balance += amount;
			transactions.pop();
		}
	}


	cout << "Final balance: $" << balance << endl;

	return 0;
}