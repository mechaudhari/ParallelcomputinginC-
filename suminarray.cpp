//SOURCE: removeoddnumbers.cpp
//EXERCISE: Set 5 Question
//AUTHOR: Meenal Chaudhari
//DATE: 01/28/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: add all numbers in an array using only pointers

#include <iostream>
#include <string>
using namespace std;
int main()
	{
	int arr[5];
	int i, sum=0;
	int *ptr,*pt;
	cout<<"Enter the elements of array: ";
	pt = arr;
	for(i=0;i<5;i++)
		{
		*pt = i;
		pt++;
		//cin>>arr[i];
		}
	ptr = arr;
	for(i=0;i<5;i++)
		{
		sum=sum+*ptr;
		ptr++;
		}
	cout<<"The sum is:: "<<sum<<endl;
	cout<<"the third element is :"<<arr[3];
	return 0;
	}