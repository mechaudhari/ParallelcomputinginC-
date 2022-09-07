//SOURCE: removeoddnumbers.cpp
//EXERCISE: Set 5 Question
//AUTHOR: Meenal Chaudhari
//DATE: 01/28/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: remove all odd numbers from an ordered list
#include <iostream.h>
using namespace std;
int main()
	{
	//Ordered array with odd numbers in it
	int ordArray[10] = {21,22,23,24,25,26,27,28,29,30};
	//Create pointer to the ordered array
	int* ordArrayPtr = ordArray;
	//Loop through the array
	for ( int i=0; i < 10; i++ )
		{
		//Test if the number is odd
		//If so, replace it with -1
		if ( *( ordArrayPtr + i ) % 2 != 0 )
			*( ordArrayPtr + i ) = -1;
		}
	//Display the array
	for ( int j=0; j < 10; j++ )
		cout << *(ordArrayPtr + j) << endl;
	//Keep console window alive after execution
	cin.get();
	return 0;
	}