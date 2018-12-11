/*
ID: ylyyanl1
TASK: combo
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool check_close(int a, int b, int n)
{
  if (abs(a-b) <= 2) return true;
  if (abs(a-b) >= n - 2) return true;
  return false;
}
// a=gold
bool check_num(int *a, int *b, int N)
{

  for (int i = 0; i < 3; i++)
  {
    /*
    if ( a[i] == b[i] )
    {
      continue;
    }
    else if ((a[i] + 1) % N == (b[i] % N))
    {
      continue;
    }
    else if ((a[i] + 2) % N == (b[i] % N))
    {
      continue;
    }
    else if ((a[i] + N - 1) % N == (b[i] % N))
    {
      continue;
    }
    else if ((a[i] + N - 2) % N == (b[i] % N))
    {
      continue;
    }
    else
    {
      return false;
    }
    */
    if (!check_close(a[i], b[i], N))
    {
      return false;
    }
  }

  return true;

}

bool check_num_nice(int *a, int *b, int N)
{

  return check_close(a[0], b[0], N) && check_close(a[1], b[1], N) && check_close(a[2], b[2], N);

}

int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");
  
  int N;
  int combi1[3];
  int combi2[3];

  fin >> N;

  fin >> combi1[0] >> combi1[1] >> combi1[2];
  fin >> combi2[0]>> combi2[1] >> combi2[2];

  fin.close();

  int total = 0;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      for (int k = 1; k <= N; k++)
      {
        int b[3] = {i,j,k};

        /*
        if (check_num(combi1, b, N) || check_num(combi2, b, N))
        {
          //fout << i << " " << j << " " << k << endl;
          total++;
        }
        */
        if (check_num_nice(combi1, b, N) || check_num_nice(combi2, b, N))
        {
          //fout << i << " " << j << " " << k << endl;
          total++;
        }
      }
    }
  } 
  
  fout << total << endl;
  fout.close();

  return 0;
}
