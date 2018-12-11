#include <utility>    // for std::swap
#include <algorithm>  // for std::copy
#include <cmath>      // for round
#include <chrono>     // for timing functions
#include <cstdlib>    // for rand and srand

#include "SortingTests.h"

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/

void selectionSort(int a[], size_t size) {
  for (size_t i = 0; i < size-1; ++i) {
    bool swapped = false;
    for (size_t j = 0; j < size-i-1; ++j) {
      if (a[j] > a[j+1]){
        std::swap(a[j],a[j+1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

void insertionSort(int a[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = i; j > 0; --j) {
      if (a[j] < a[j-1]) {
        std::swap(a[j],a[j-1]);
      } else {
        break;
      }
    }
  }
}

void mergeSort(int a[], int from, int to) {
  if (to-from <= 0) {
    return;
  }
  size_t left_size = (to-from+1)/2;
  size_t right_size = round((to-from+1)/2.0);

  //split
  int* left = new int[left_size];
  int* right = new int[right_size];

  // it copies [first,last)
  std::copy(a,a+left_size,left);
  std::copy(a+left_size,a+to+1,right);

  mergeSort(left,0,left_size-1);
  mergeSort(right,0,right_size-1);

  //merge
  size_t left_index = 0, right_index = 0;
  for (size_t cur_index = 0; cur_index < left_size+right_size; ++cur_index) {
    if (left_index < left_size && right_index >= right_size) {
      a[cur_index] = left[left_index++];
    } else if (left_index >= left_size && right_index < right_size) {
      a[cur_index] = right[right_index++];
    } else if (left[left_index] < right[right_index]) {
      a[cur_index] = left[left_index++];
    } else {
      a[cur_index] = right[right_index++];
    }
  }

  delete[] left;
  delete[] right;
}


/*********************************************************************/
/****************** ARRAY POPULATING FUNCTIONS ***********************/
/*********************************************************************/