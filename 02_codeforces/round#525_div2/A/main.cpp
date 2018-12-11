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
  
  
  int x;

  cin >> x;

  //int a, b;

  for (int i = 1; i <= x; i++)
  {
    for (int j = i; j <= x; j++)
    {
      if ((j % i == 0) && (i * j > x) && (j / i < x))
      {
        cout << j << " " << i << endl;
        return 0;
      }
    }
  }

  cout << "-1" << endl;

  return 0;
}
