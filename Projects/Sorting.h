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

// Function/Class Declarations
// template <class T>
// void selectionsort(T* data, int size);
// template <class T>
// void insertionsort(T* data, int size);
// template <class T>
// void mergesort(T* data, int size, T* temp);
// template <class T>
// void quicksort(T* data, int size);

// Function/Class Implementations
template <class T>
void selectionsort(T* data, int size)
{
	// printArray(data, size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[i])
			{
				swap(data[i], data[j]);
			}
		}
	}
	// printArray(data, size);

}

template <class T>
void insertionsort(T* data, int size)
{
	//Ref: https://en.wikipedia.org/wiki/Insertion_sort
	// printArray(data, size);
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && data[j-1] > data[j])
		{
			swap(data[j], data[j-1]);
			j--;
		}
	}
	// printArray(data, size);
}

template <class T>
void mergesort(T* data, int size, T* temp)
{
	if (size > 1)
	{
		int mid = (size + 1) / 2;
		T* left = data;
		T* right = data + mid;

		mergesort(left, mid, temp);
		mergesort(right, size - mid, temp + mid);

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

		int tempsize1 = mid - 1;
		for (int i = l, j = s; i <= tempsize1; i++, j++)
		{
			// cout << "temp[" << j << "]: " << temp[j] << "\tleft[" << i << "]: " << left[i] << endl;
			temp[j] = left[i];
		}

		s = s + mid - l;

		int tempsize2 = size - mid - 1;
		for (int i = r, j = s; i <= tempsize2; i++, j++)
		{
			// cout << "temp[" << j << "]: " << temp[j] << "\tleft[" << i << "]: " << left[i] << endl;
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
	// cout << "Input: ";
	// printArray(data, size);
	if (size <= 1)
	{
		return;
	}


	int mid = (size + 1) / 2;

	// cout << "size: " << size << "\tmid=(size+1)/2: " << mid << endl;

	int temp = medianof3(data[0], data[mid], data[size - 1]);
	int pivot = 0;

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

	// cout << "temp: " << temp << endl;
	// cout << "pivot: " << pivot << "\tdata[0]: " << data[0] << "\tdata[mid]: " << data[mid] << "\tdata[size - 1]: " << data[size - 1] << endl;

	// cout << "Pre-swap (1):  ";
	// printArray(data, size);
	swap(data[pivot], data[0]);
	// cout << "Post-swap (1): ";
	// printArray(data, size);
	// cin.ignore();

	int left = 0;
	int right = size - 1;

	// static int var = 0;
	do
	{
		// cout << "Pre-swap (2):  " << "\tleft: " << left << "\tright: " << right << "\t";
		// printArray(data, size);
		// cout << "(" << (var + 1) << ") Test " << endl;
		// cout << "(" << (var + 2) << ") left: " << left << "\tright: " << right << endl;
		while (left < right && data[left] <= data[0])
		{
			left++;
		}
		// cout << "(" << (var + 3) << ") left: " << left << "\tright: " << right << endl;
		while (left < right && data[right] > data[0])
		{
			right--;
		}
		// cout << "(" << (var + 4) << ") left: " << left << "\tright: " << right << endl;
		// cout << "Pre-swap (2):  " << "\tleft: " << left << "\tright: " << right << "\t";
		// printArray(data, size);
		swap(data[left], data[right]);
		// cout << "Post-swap (2): " << "\tleft: " << left << "\tright: " << right << "\t";
		// printArray(data, size);
		// cin.ignore();
	}
	while (!(left >= right));
	// var = var + 4;
	
	if (data[left] > data[0])
	{
		left--;
	}

	// cout << "Pre-swap (3):  ";
	// printArray(data, size);
	swap(data[0], data[left]);
	// cout << "Post-swap (3):  ";
	// printArray(data, size);

	// cout << "Left: " << left << endl;
	// cin.ignore();

	quicksort(data, left);
	quicksort(data + left + 1, size - left - 1);

	// cout << "Output Result: ";
	// printArray(data, size);
}

// template <class T>
void csvfile(int mediantime, int size)
{
	ofstream myfile;
 	myfile.open ("example.csv");

 	myfile << ",SI,SD,SR,SC,II,ID,IR,IC,MI,MD,MR,MC,QI,QD,QR,QC\n";
 	// myfile << ",SI,SD,SR,SC\n";
 	// myfile << "1000,";
 	// for (int i = 0; i < 4, i++)
 	// {

 	// }
 	myfile << "2000\n";
 	myfile << "3000\n";
 	myfile << "4000\n";
 	myfile << "5000\n";
 	myfile << "6000\n";
 	myfile << "7000\n";
 	myfile << "8000\n";
 	myfile << "9000\n";
 	myfile << "10000\n";

 	for (int i = 0; i < 16; i++)
 	{

 	}

 	// myfile << "Writing this to a file.\n";

 	myfile.close();
}


#endif
