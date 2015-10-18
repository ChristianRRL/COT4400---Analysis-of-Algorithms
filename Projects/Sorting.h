//File: MaxMinPour
//Author: Christian Rodriguez

/*Instructions:
	Implement four sorting functions: selectionsort, insertionsort, mergesort, and quicksort.
*/

#ifndef __SORTING_H
#define __SORTING_H

#include "SortingHelper.h"
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

// Function/Class Declarations
// template <class T>
// void selectionsort(T* data, int size);
// template <class T>
// void insertionsort(T* data, int size);
template <class T>
void mergesort(T* data, int size, T* temp);
template <class T>
void quicksort(T* data, int size);

// Function/Class Implementations
template <class T>
void selectionsort(T* data, int size)
{
	printArray(data, size);
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
	printArray(data, size);

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

// template <class T>
// void mergesort(T* data, int size, T* temp)
// {

// }

// //Merge Sort 
// template <class T> void mergesort(T* data, int size, T* temp)
// {
// 	if (size > 1)
// 	{
// 		int mid = (size / 2);
// 		mergesort(data, mid, temp);
// 		mergesort(data + mid, size - mid, temp);
// 		merge(data, size, temp);
// 	}
// }

// //Function to sort quicksort 
// template <class T> int part(T data[], int size)
// {
// 	T pivot = data[0];
// 	int low = 1;
// 	int high = size;
// 	while (low < high)
// 	{
// 		high--;
// 		while (data[low] < pivot && low < high)
// 			low++;
// 		while (data[high] > pivot && low < high)
// 			high--;
// 		if (low < high)
// 			swap(data[low], data[high]);
// 	}

// 	if ( low > 0) 
// 	{
// 		if (data[low] > pivot)
// 			low--;
// 			swap(data[low], data[0]);
// 	}
// 	return (low);
// }

// //Quick Sort 
// template <class T> void quicksort(T* data, int size)
// {
// 	printArray(data, size);

// 	if (size > 1)
// 	{
// 		int pivot = part(data, size);
// 		quicksort(data, pivot);
// 		cout << "data[0]: " << data[0] << "\tpivot: " << pivot << "\tdata + pivot + 1: " << data[2] << endl;
// 		quicksort(data + pivot + 1, size - pivot - 1);
// 	}
// }


template <class T>
void quicksort(T* data, int size)
{
	cout << "Input: ";
	printArray(data, size);
	if (size <= 1)
	{
		return;
	}

	int mid = (size + 1) / 2;
	int temp = medianof3(data[0], data[mid], data[size - 1]);
	int pivot = 0;

	if (temp == 1)
	{
		pivot = data[0];
	}
	if (temp == 2)
	{
		pivot = data[mid];
	}
	if (temp == 3)
	{
		pivot = data[size - 1];
	}

	cout << "pivot: " << pivot << "\tdata[0]: " << data[0] << "\tdata[mid]: " << data[mid] << "\tdata[size - 1]: " << data[size - 1] << endl;

	cout << "Pre-swap (1):  ";
	printArray(data, size);
	// if (data[0] >= data[pivot])
	// {
	swap(data[pivot], data[0]);
	// }
	cout << "Post-swap (1): ";
	printArray(data, size);
	cin.ignore();

	int left = 0;
	int right = size - 1;

	// static int var = 0;
	do
	{
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
		cout << "Pre-swap (2):  ";
		printArray(data, size);
		swap(data[left], data[right]);
		cout << "Post-swap (2): ";
		printArray(data, size);
		cin.ignore();
	}
	while (!(left >= right));
	// var = var + 4;
	
	if (data[left] > data[0])
	{
		left--;
	}

	cout << "Pre-swap (3):  ";
	printArray(data, size);
	swap(data[0], data[left]);
	cout << "Post-swap (3):  ";
	printArray(data, size);

	// static int temp1 = left;
	// tempLeft1++;

	cout << "Left: " << left << endl;
	cin.ignore();

	quicksort(data, left - 1);
	quicksort(data + left + 1, size - left - 1);

	cout << "Output Result: ";
	printArray(data, size);
}

// //ref: https://en.wikipedia.org/wiki/Quicksort
// template <class T>
// void partition(data, lo, hi)
// {
// 	int pivot = data[lo];
// 	int i = lo - 1;
// 	int j = hi + 1;

// 	while (1)
// 	{
// 		do
// 		{
// 			j--;
// 		}
// 		while (data[i] > pivot);

// 		do
// 		{
// 			i++;
// 		}
// 		while (data[j] < pivot);

// 		if (i < j)
// 		{
// 			swap(data[i], data[j]);
// 		}
// 		else
// 		{
// 			return;
// 		}
// 	}
// }

#endif
