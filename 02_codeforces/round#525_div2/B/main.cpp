/*
ID: ylyyanl1
TASK: crypt1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  
  
  int n, k;

  cin >> n >> k;

  //int a[n];
  std::vector<int> a;

  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  /* time limited
  for (int i = 0; i < k; i++)
  {
    int min = 0;
    bool found_nonzero = false;
    for (int j = i; j < a.size(); j++)
    {
      if ((a[j] != 0) && (min == 0) )
      {
        cout << a[j] << endl;
        min = a[j];
        a[j] = 0;
        found_nonzero = true;
      }
      else if (a[j] != 0)
      {
        a[j] -= min;
      }
    }

    if (!found_nonzero)
    {
      cout << 0 << endl;
    }
  }
  */

  int min = 0;
  int j = 0;
  for (int i = 0; i < k; i++)
  {
    while(j < n && (a[j] - min == 0)) j++;
    if (j < n)
    {
      cout << a[j] - min << endl;
      min = a[j];
      j++;
    }
    else
    {
      cout << 0 << endl;
    }
  }

  return 0;
}
