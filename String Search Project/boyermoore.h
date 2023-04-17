#pragma once
#include "GenerateItem.h"
using namespace std;
# define NO_OF_CHARS 256
class boyermoore
{
public:


	boyermoore();
	void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]);
	void search(vector<string> myVector, string pat);


};

