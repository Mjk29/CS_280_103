/*
Array Allocator
1. Use a function to dynamically allocate an array of integers.
2. The function should accept an integer argument indicating the number of elements to allocate.
3. It should return a pointer to the array
*/

#include <iostream>
using namespace std;

int* fun1 (int);

int main()
{
	int size;
	int* array;
	cout<<"Enter size of array \n";
	cin>>size;

	cout<<"Array is: \n";
	array=fun1(size);	
	
	for(int i=0; i<size; i++)
		cout<<*array+i<<" ";

	return 0;
}


int* fun1( int size)
{
	int* array=new int[size];
	int* pointer = array;
	for (int i=0; i<size; i++)
			{
				array[i]=i+1;
				//cout<<array[i]<<"\n";
				//cout<<*pointer+i<<"\n";
				}
	

	return array;
}