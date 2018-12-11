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

bool check_num(int a, std::vector<int> set, int n)
{
  int tmp = a;
  //cout << "size = " << set.size() << endl;
  while(tmp)
  {
    bool is_in = false;
    int d = tmp % 10;
    for (int i = 0; i < n; i++)
    {
      //cout << set[i] << endl;
      if (set[i] == d)
      {
        is_in = true;
        break;
      }
    }
    if (!is_in)
    {
      return false;
    }
    tmp /= 10;
  }

  return true;

}

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  
  int N;
  std::vector<int> c_set;

  fin >> N;

  for (int i = 0; i < N; i++)
  {
    int tmp;
    fin >> tmp;
    c_set.push_back(tmp);
  }

  sort(c_set.begin(), c_set.end());
  /*
  for (int i = 0; i < N; i++)
  {
    cout << c_set[i] << endl;
  }
  */
  int total = 0;

  for (int m = 0; m < N; m++)
  {
    for (int n = 0; n < N; n++)
    {
      for (int l = 0; l < N; l++)
      {
        int tmp = 100 * c_set[m] + 10 * c_set[n] + c_set[l];

        int k = 1000 / tmp;

        for (int p = 0; p < N; p++)
        {
          if (c_set[p] > k)
          {
            break;
          }

          for (int q = 0; q < N; q++)
          {
            if (c_set[q] > k)
            {
              break;
            }
            int tmp_m = 10 * c_set[p] + c_set[q];
            //cout << "tmp_m:" << tmp_m << endl;
            if (check_num(tmp*c_set[p], c_set, N) && check_num(tmp*c_set[q], c_set, N) && check_num(tmp*tmp_m, c_set, N))
            {
              //cout << tmp << " " << tmp_m << endl;
              total++;
            }
          }
        }
      }
    }
  }
  fout << total <<endl;
  return 0;
}
