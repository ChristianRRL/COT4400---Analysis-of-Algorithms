#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#include "Sorting.h"
#include "SortingHelper.h"
#include <stdlib.h>
// #include <stdio.h>
#include <fstream>

enum sort_t  {SELECTION, INSERTION, MERGE, QUICK};
enum input_t {INCREASING, DECREASING, CONSTANT, RANDOM};

#define DEFAULT_N     1000
#define DEFAULT_ALG   MERGE
#define DEFAULT_INPUT RANDOM

#define N_ARG         1
#define ALG_ARG       2
#define INPUT_ARG     3
#define MIN_ARGS      1
#define MAX_ARGS      4
#define PRINT_USAGE() cout << argv[0] << " [n] [algorithm] [input type]" << endl << endl << \
                              "n (optional):  size of array (default:  " << DEFAULT_N << ')' << endl << \
                              "algorithm (optional):  one of selectionsort, insertionsort, mergesort, or quicksort (simq, default mergesort)" << endl << \
                              "input type (optional):  one of increasing, decreasing, constant, or random (idcr, default random)" << endl;

int main(int argc, char** argv)
{
  int n = DEFAULT_N;
  sort_t alg = DEFAULT_ALG;
  input_t intype = DEFAULT_INPUT;
  int* data;
  int* temp;
  clock_t start;
  clock_t timing[3];

  //Parse input arguments
  if (argc < MIN_ARGS || argc > MAX_ARGS)
  {
    PRINT_USAGE();
    return -1;
  }

  if (argc > N_ARG)
    n = atoi(argv[N_ARG]);

  temp = zeroArray(n);
  if (argc > ALG_ARG)
  {
    switch (argv[ALG_ARG][0])
    {
    case 's':
    case 'S':
      alg = SELECTION;
      break;
    case 'i':
    case 'I':
      alg = INSERTION;
      break;
    case 'm':
    case 'M':
      alg = MERGE;
      break;
    case 'q':
    case 'Q':
      alg = QUICK;
      break;
    default:
      cout << "Sorting algorithm not recognized\n";
    }
  }

  if (argc > INPUT_ARG)
  {
    switch (argv[INPUT_ARG][0])
    {
    case 'i': //increasing
    case 'I':
    case 'a': //ascending
    case 'A':
      intype = INCREASING;
      break;
    case 'd':  //decreasing, descending
    case 'D':
      intype = DECREASING;
      break;
    case 'c':  //constant
    case 'C':
    case 'z':  //zero
    case 'Z':
      intype = CONSTANT;
      break;
    case 'r':  //random
    case 'R':
      intype = RANDOM;
      break;
    default:
      cout << "Input array type not recognized\n";
    }
  }

  // sortall(data, size);
  
  //Run sorting algorithm 3 times
  for (int i = 0; i < 3; i++)
  {
    // Initialize data
    switch (intype)
    {
    case INCREASING:
      data = increasingArray(n);
      break;
    case DECREASING:
      data = decreasingArray(n);
      break;
    case CONSTANT:
      data = zeroArray(n);
      break;
    case RANDOM:
      data = randomArray(n);
    }

    //Sort data
    // printArray(data, n);
    switch (alg)
    {
    case SELECTION:
      selectionsort(data, n);
      break;
    case INSERTION:
      insertionsort(data, n);
      break;
    case MERGE:
      mergesort(data, n, temp);
      break;
    case QUICK:
      quicksort(data, n);
    }
    timing[i] = clock() - start;
    // printArray(data, n);

    //Verify data is sorted
    if (isSorted(data, n))
      cout << "Array successfully sorted.\n";
    else
    {
      cout << "Array incorrectly sorted.\n";
      //Time to debug...
      return -1;
    }
  }

  //Output timing results
  int mediantime = 0;
  for (int i = 0; i < 3; i++)
    cout <<"Attempt " << i+1 << ":  " << setw(8) << (int) (timing[i] * 1000.0 / CLOCKS_PER_SEC) << " ms\n";
  cout <<  "Median time:     " << setw(8) << (int) (timing[medianof3(timing[0], timing[1], timing[2])-1] * 1000.0 / CLOCKS_PER_SEC) << " ms" << endl;
  mediantime = (int) (timing[medianof3(timing[0], timing[1], timing[2])-1] * 1000.0 / CLOCKS_PER_SEC);
  // csvfile(mediantime, n);
  // cout << "mediantime again: " << mediantime << endl;
  free(data);
  free(temp);

  //Windows:  pause so window doesn't vanish
  char c;
  cout << "Type 'q' to quit:  ";
  cin >> c;
  return 0;
}
