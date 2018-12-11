#include <iostream>

#include "SortingTests.h"

int main()
{
  int a[5] = {4,2,5,3,1};
  mergeSort(a,0,4);
  int b[5];
  //std::copy(a,a+2,b);
  
  for(auto x : a)
  {
    std::cout << x << " ";
  }
  
  return 0;
}
