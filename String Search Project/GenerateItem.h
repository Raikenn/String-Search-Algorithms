#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class GenerateItem
{
public:
	
	//functions
	GenerateItem();
	void GenerateStock(int Stock);
	vector<string> GetVector();

private:

	//create a vector to store items
	vector<string> myVector;
	//variables
	int num;
	string currentItem;
	//store words to use in generating items
	string age[2] = { "Old ","Young " };
	string coat[3] = { "Short Haired ", "Medium Haired ", "Long Haired " };
	string breed[20] = { "Affenpinscher", "American Foxhound", "Beagle", "Basset Hound", "Bloodhound", "Boxer", "Chihuahua", "Chow Chow", "Corgi", "Dachshund", "Dalmatian", "Doberman", "German Shepherd", "Greyhound", "Poodle", "Pug", "Shiba Inu", "Siberian Husky", "Schnauzer" "Whippet" };
	

};