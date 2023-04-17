#include "boyermoore.h"
#include "RabinKarp.h"
#include <chrono>

//Sources Used:
//https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
//https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
//Lecture Slides



int main()
{
	GenerateItem stocklist;
	boyermoore boyermoore;
	RabinKarp RabinKarp;
	int Stock;
	int again = 1;
	int algorithm;
	int q = 271;
	string pat;
	while (again == 1)
	{
		cout << "please enter How much stock you would like\n";
		cin >> Stock;
		stocklist.GenerateStock(Stock);
		cout << "1 = Boyermoore | 2 = RabinKarp\n";
		cin >> algorithm;
		cout << "what would you like to search for?\n";
		cin >> pat;

		if (algorithm == 1)
		{
			//using <chrono> to measure the time it takes for the search to execute
			auto StartTime = chrono::high_resolution_clock::now();
			boyermoore.search(stocklist.GetVector(), pat);
			auto timeTaken = chrono::high_resolution_clock::now() - StartTime;
			cout << endl << "\nTime Taken: " << timeTaken / chrono::milliseconds(1) << "ms.";
			cout << endl << "would you like to try again? 1 = yes | 2 = No\n";
			cin >> again;
			if (again == 2)
			{
				exit;
			}
		}

		else if (algorithm == 2)
		{
			auto StartTime = chrono::high_resolution_clock::now();
			RabinKarp.search(pat, stocklist.GetVector(), q);
			auto timeTaken = chrono::high_resolution_clock::now() - StartTime;
			cout << endl << "Time Taken: " << timeTaken / chrono::milliseconds(1) << "ms.";
			cout << endl << "would you like to try again? 1 = yes | 2 = No\n";
			cin >> again;
			if (again == 2)
			{
				exit;
			}
		}

		else
		{
			cout << "please enter a valid input";
		}
	}
	
}