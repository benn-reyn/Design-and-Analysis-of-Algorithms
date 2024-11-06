#include "cpsc3120homework03part01.h"
#include <vector>
#include <algorithm>

using namespace std;

int assemblyLine( vector<int> line1 , vector<int> line2 , vector<int> t12 , vector<int> t21 ){
  
int n = line1.size();

vector<int> path1(n);
vector<int> path2(n);
path1 [0] = line1 [0];
path2 [0] = line2 [0];

for (int i = 1; i < n; i++)
  {
      path1[i] = min((path1[i-1] + line1[i]), (path2[i-1] + line1[i] + t21[i-1]));
      path2[i] = min((path2[i-1] + line2[i]), (path1[i-1] + line2[i] + t12[i-1]));
  }

return min(path1[n-1], path2[n-1]);

}
