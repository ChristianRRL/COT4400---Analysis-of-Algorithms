//File: MaxMinPour
//Author: Christian Rodriguez

/*Instructions:
	Implement four sorting functions: selectionsort, insertionsort, mergesort, and quicksort.
*/

#ifndef __SORTING_H
#define __SORTING_H

#include "SortingHelper.h"
// #include <iostream>
#include <fstream>

using namespace std;

// Function/Class Implementations
template <class T>
void selectionsort(T* data, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		// let j be the min value in the array data[i..n-1]
		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[i])
			{
				swap(data[i], data[j]);
			}
		}
	}
}

template <class T>
void insertionsort(T* data, int size)
{
	for (int i = 1; i < size; i++)
	{
		// let j = location of predecessor of data[i] in data[0..i-1]
		int j = i;
		while (j > 0 && data[j-1] > data[j])
		{
			swap(data[j], data[j-1]);
			j--;
		}
	}
}

template <class T>
void mergesort(T* data, int size, T* temp)
{
	// base case of recursive function
	if (size > 1)
	{
		int mid = (size + 1) / 2;
		T* left = data;
		T* right = data + mid;

		// left side being split recursively
		mergesort(left, mid, temp);
		// right side being split recursively
		mergesort(right, size - mid, temp + mid);

		// perform insertions into temp array
		int l = 0, r = 0, s = 0;
		while (l < mid && r < (size - mid))
		{
			if (left[l] < right[r])
			{
				temp[s] = left[l];
				l++;
			}
			else
			{
				temp[s] = right[r];
				r++;
			}
			s++;
		}

		// copy left into temp array
		int tempsize1 = mid - 1;
		for (int i = l, j = s; i <= tempsize1; i++, j++)
		{
			temp[j] = left[i];
		}

		// reset s to new number
		s = s + mid - l;

		// copy right into temp array
		int tempsize2 = size - mid - 1;
		for (int i = r, j = s; i <= tempsize2; i++, j++)
		{
			temp[j] = right[i];
		}

		for (int i = 0; i < size; i++)
		{
			data[i] = temp[i];
		}
	}
}

template <class T>
void quicksort(T* data, int size)
{
	// base case of recursive function
	if (size <= 1)
	{
		return;
	}

	int mid = (size + 1) / 2;

	int temp = medianof3(data[0], data[mid], data[size - 1]);
	int pivot = 0;

	// set pivot the the mediam of the numbers
	if (temp == 1)
	{
		pivot = 0;
	}
	if (temp == 2)
	{
		pivot = mid;
	}
	if (temp == 3)
	{
		pivot = size - 1;
	}

	// perform first swap
	swap(data[pivot], data[0]);

	int left = 0;
	int right = size - 1;

	// shift left and right elements while performing swaps
	do
	{
		while (left < right && data[left] <= data[0])
		{
			left++;
		}
		while (left < right && data[right] > data[0])
		{
			right--;
		}
		swap(data[left], data[right]);
	}
	while (!(left >= right));
	
	if (data[left] > data[0])
	{
		left--;
	}

	// perform third swap
	swap(data[0], data[left]);

	// recursively iterate through left side
	quicksort(data, left);
	// recursively iterate through right side
	quicksort(data + left + 1, size - left - 1);
}

// create csv file
void csvfile(int mediantime, int size)
{
	ofstream myfile;
 	myfile.open ("example.csv");

 	myfile << ",SI,SD,SR,SC,II,ID,IR,IC,MI,MD,MR,MC,QI,QD,QR,QC\n";
 	myfile << "10000\n";
 	myfile << "20000\n";
 	myfile << "30000\n";
 	myfile << "40000\n";
 	myfile << "50000\n";
 	myfile << "60000\n";
 	myfile << "70000\n";
 	myfile << "80000\n";
 	myfile << "90000\n";
 	myfile << "100000\n";

 	myfile.close();
}


#endif
