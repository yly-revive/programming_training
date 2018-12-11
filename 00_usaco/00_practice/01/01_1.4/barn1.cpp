/*
ID: ylyyanl1
TASK: barn1
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
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");
  
  int M, S, C;
  fin >> M >> S >> C;

  //int c[C];
  std::vector<int> c;
  for (int i = 0; i < C; i++)
  {
    int tmp;
    fin >> tmp;
    c.push_back(tmp);
  }
  
  sort(c.begin(), c.end());
  
  std::vector<int> distance;

  for (int i = 1; i < C; i++)
  {
    distance.push_back(c[i] - c[i-1]);
  }
  sort(distance.begin(), distance.end());

  int min_cost = 0;
  if (C <= M)
  {
    fout << C << endl;
    return 0;
  }
  for (int i = 0; i < C - M ; i++)
  {
    //cout << distance[i] << endl;
    min_cost += distance[i];
  }

  fout << min_cost + M << endl;
  
  /*
  int s[S];
  memset(s, 0, sizeof(int) * S);
  for (int i = 1; i < C; i++)
  {
    s[abs(c[i] - c[i-1])]++;
  }
  int count = 0;
  int min_cost = 0;

  
  for (int i = 0; i < S; i++)
  {
    cout << s[i] << endl;
  }
  
  for (int j = S - 1; j >= 0; j--)
  {
    
    if (s[j] > 0)
    {
      if (count >= M-1)
      {
        min_cost += s[j] * j;
      }
      else
      {
        if ( (s[j] + count) >= M - 1 )
        {
          
          min_cost += j * (s[j] - ( M - 1 - count ));
          count = M - 1;
          //continue;
        }
        else
        {
          count += s[j];
          //continue;
        }
      }
    }
  }
  
  fout << min_cost + M << endl;
  */
  return 0;
}
