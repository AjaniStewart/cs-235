#include <utility>    // for std::swap
#include <algorithm>  // for std::copy
#include <cmath>      // for round
#include <chrono>     // for timing functions
#include <cstdlib>    // for rand and srand

#include "SortingTests.hpp"

using namespace std::chrono;

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/

void selectionSort(int a[], size_t size) {
  for (size_t start_index = 0; start_index < size-1; ++start_index) {
    int smallest_index = start_index;
    for (size_t current_index = start_index+1; current_index < size; ++current_index) {
      if (a[current_index] < a[smallest_index]){
        smallest_index = current_index;
      }
    }
    std::swap(a[start_index],a[smallest_index]);
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

//from learncpp.com
//https://www.learncpp.com/cpp-tutorial/59-random-number-generation/

int getRandomNumber(int min = 0, int max = 10000) {
  // static used so that this is calculated once
  static const double fraction = 1.0 / (RAND_MAX + 1.0);
  //evenly distribute the random number across the range
  return min + static_cast<int>((max-min+1)*(std::rand()*fraction));
}

void generateRandomArray(int values[], size_t size) {
  //set inital seed value to system clock
  for (size_t i = 0; i < size; ++i) {
    values[i] = getRandomNumber();
  }
}

void generateAscendingArray(int values[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    values[i] = i;
  }
}

void generateDescendingArray(int values[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    values[i] = size-i;
  }
}

void generateLastTenRandomArray(int values[], size_t size) {
  generateAscendingArray(values,size-10);
  for (size_t i = size-10; i < size; ++i) {
    values[i] = getRandomNumber();
  }
}

void generateFewRandomArray(int values[], size_t size) {
  
  for (size_t i = 0;i < size; ++i) {
    values[i] = getRandomNumber(0,size/10);
  }
}

/*****************************************************************/
/****************** RUNTIME TEST FUNCTIONS ***********************/
/*****************************************************************/

double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size) {
  double total_time = 0;
  int* values_copy = values;
  for (int i = 0; i < 10; ++i) {
    auto start_time = high_resolution_clock().now();
    sortingFunction(values_copy,size);
    auto end_time = high_resolution_clock().now();
    duration<float,std::micro> run_time = duration_cast<microseconds>(end_time-start_time);
    total_time += run_time.count();
    values_copy = values;
  }
  return total_time/10.0;
}

double mergeSortTest(int values[], size_t size) {
  double total_time = 0;
  int* values_copy = values;
  for (int i = 0; i < 10; ++i) {
    auto start_time = high_resolution_clock().now();
    mergeSort(values_copy,0,size-1);
    auto end_time = high_resolution_clock().now();
    duration<float,std::micro> run_time = duration_cast<microseconds>(end_time-start_time);
    total_time += run_time.count();
    values_copy = values;
  }
  return total_time/10.0;
}