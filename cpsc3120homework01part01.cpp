/*
Bennie Reynolds
Design of Algorithms and DataStructures
This program implements the functions maxSubSlow, maxSubFaster, and maxSubFastest
*/
#include "cpsc3120homework01part01.h"
#include <vector>
#include <cmath>

using namespace std;

int maxSubSlow( const vector<int> &numbers )
{
  int max = numbers[0];
  int current = 0;
  int n = numbers.size();

  for (int j = 0; j < n; j++)
  {
    for (int k = j; k < n; k++)
    {
    current = 0;
      for (int i = j; i <= k; i++)
        current = current + numbers[i];
    if (current > max)  
      max = current;
    }
  }
return max;
};

int maxSubFaster( const vector<int> &numbers )
{
  int n = numbers.size();
  int s = 0;
  std::vector<int> preSum(n + 1, 0);

  for (int i = 1; i < n; i++)
  {
    preSum[i] = preSum[i - 1] + numbers[i - 1];
  }
    
    int max = 0;

    for (int j = 1; j < n; j++)
    {
      for (int k = j; k < n; k++)
      {
      s = preSum[k] - preSum[j - 1];
      if (s > max)
        max = s;
      }
    }
  return max;
}

int maxSubFastest( const vector<int> &numbers )
{
  int max = numbers[0];
  int current = 0;
  
  for (const int &n : numbers)
  {
    if (current < 0)
      current = 0;

    current += n;
    if (current > max)
      max = current;

  }
  return max;
}

