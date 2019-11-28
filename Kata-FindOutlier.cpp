#include <iostream>
#include <vector>
// #include <numeric>
#include <string>
#include <math.h>
#include <map>
#include <iterator>
// #include <complex>

int FindOutlier(std::vector<int> arr)
{
    int old = 0, even = 0, result = 0;
    for(int x: arr) 
    {
      if( old != 2 & even != 2 )
      {
        (x & 1) ? even += 1 : old += 1;
      } else { break; }
    }
    for(int x: arr) 
    {
      if(old & 10)
      {
        if(x & 1)
        {
          result = x;
          break;
        } 
      }
      else 
      {
        if(x % 2 == 0)
        {
          result = x;
          break;
        } 
      }
    }
    return result;
}

int main()
{
  std::vector<int> vec = { 3, 7, 11, 6, 281, 121, 123 };
  std::cout << FindOutlier(vec) << std::endl;
  return 0;
}