#include <iostream>

#include "SortingTests.hpp"

int main()
{
  int a[10000];
  generateFewRandomArray(a,10000);
  std::cout << "mergesort took " << mergeSortTest(a,10000) << " micro secs.\n";
  std::cout << "insertion sort took " << sortTest(insertionSort,a,10000) << " micro secs.\n";
  std::cout << "selection sort took " << sortTest(selectionSort,a,10000) << " micro secs.\n";
  //std::copy(a,a+2,b);
  
  // for(auto x : a)
  // {
  //   std::cout << x << " ";
  // }
  
  return 0;
}
