#include "cpsc3120homework03part02.h"
#include <vector>
#include <climits>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int matrixChainMultiplication( vector< vector<int> > matrices ){
  
  int n = matrices.size();
  vector<vector<int>> multTable(n, vector<int>(n, 0));

  for (int l = 2; l <= n; l++)
  {
    for (int i = 0; i <= n - l; i++)
    {
      int j = i + l - 1;
      for (int k = i; k < j; k++)
      {
        int cost = multTable[i][k] + multTable[k + 1][j] + matrices[i][0] * matrices[k][1] * matrices[j][1];
        if (multTable[i][j] == 0 || multTable[i][j] > cost)
          multTable[i][j] = cost;
      }
    }
  }
  return multTable[0][n - 1];
}
