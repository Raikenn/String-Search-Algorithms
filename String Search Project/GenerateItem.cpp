#include "GenerateItem.h"


GenerateItem::GenerateItem() {
	srand(time(0));
}
 void GenerateItem::GenerateStock(int Stock)
{

	 //loop for how many items are given
	for (int i = 0; i < Stock; i++)
	{
		//make sure current item is empty
		currentItem = "";
		//rand for each number to give every value in array a equal chance
		//.append adds each word into current item
		num = rand() % 2;
		currentItem.append(age[num]);
		
		num = rand() % 3;
		currentItem.append(coat[num]);
		
		num = rand() % 20;
		currentItem.append(breed[num]);
		//pushes each selected word onto the vector
		myVector.push_back(currentItem);

	}
	// how many items the user has entered
	cout << "you have entered " << myVector.size() << " Stock" << endl;
	// get the total size of the vector and output that number of items
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
		
	}
	
	

}


 //simple function to return the vector for further use in the program
 vector<string> GenerateItem::GetVector()
 {

	 return  myVector;

 }