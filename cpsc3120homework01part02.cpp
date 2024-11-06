/*
Bennie Reynolds
Design of Algorithms and DataStructures
This program implements the function removeMultiplesofThree
*/
#include "cpsc3120homework01part02.h"
#include <vector>


using namespace std;

void removeMultiplesOfThree( vector<int> &numbers )
{
  int n = numbers.size();
  int i = 0;

  do {
    if (numbers[i] % 3 == 0)
    {
      numbers.erase(numbers.begin() + i);
      n = numbers.size();
    }
    else  
      i++;
  } while (i < n);
}


