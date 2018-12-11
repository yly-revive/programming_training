/*
ID: ylyyanl1
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");
  
  int N;
  fin >> N;

  char c[N];

  for (int i = 0; i < N; i++)
  {
    fin >> c[i];
  }

  int total_max = 0;

  for (int i = 0; i < N; i++)
  {
    // for right part
    int broken_index = i;
    char right_first = c[i];
    int tmp_b_i = i;
    while(c[tmp_b_i] == 'w')
    {
      tmp_b_i = (tmp_b_i + 1) % N;
      if (tmp_b_i == i) 
      {
        fout << N << endl;
        return 0;
      }
    }
    right_first = c[tmp_b_i];

    int right_counter = 1;
    int j = (i+1) % N;
    while( (c[j] == right_first) || (c[j] == 'w') )
    {
      right_counter++;
      j = (j + 1) % N;
      if (right_counter >= N)
      {
        break;
      }
    }

    // for left part
    int left_first_index = ((i - 1) < 0) ? (i - 1 + N) : i - 1;
    char left_first = c[left_first_index];

    int tmp_bl_i = left_first_index;
    while(c[tmp_bl_i] == 'w')
    {
      tmp_bl_i = (tmp_bl_i - 1 + N) % N;
    } 
    left_first = c[tmp_bl_i];

    int k = (left_first_index - 1 + N) % N;
    int left_counter = 1;

    while( (c[k] == left_first) || (c[k] == 'w') )
    {
      left_counter++;
      k = (k - 1 + N) % N;

      if (left_counter >= N)
      {
        break;
      }
    }

    int tmp_total = right_counter + left_counter;
    if (tmp_total > N)
    {
      tmp_total = N;
    }

    if (tmp_total > total_max)
    {
      total_max = tmp_total;
      //cout << i << endl;
    }

  }

  fout << total_max << endl;

  return 0;
}
