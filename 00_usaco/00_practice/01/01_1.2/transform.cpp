/*
ID: ylyyanl1
TASK: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
//#include <string>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

char *rotate90(char *a, int N)
{
  char *tmp = new char[N*N];
  memset(tmp, 0, sizeof(char) * N * N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      tmp[j * N + N-1-i] = a[i * N + j];
    }
  }
  return tmp;
}

char *rotate180(char *a, int N)
{
  char *m = rotate90(a, N);
  char *n = rotate90(m, N);
  return n;
}

char *rotate270(char *a, char N)
{
  char *m = rotate180(a, N);
  char *n = rotate90(m, N);
  return n;
}

char *reflection(char *a, char N)
{
  char *tmp = new char[N*N];
  memset(tmp, 0, sizeof(char) * N * N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      tmp[i * N + N-1-j] = a[i * N + j];
    }
  }

  return tmp;
}

int check(char *a, char *b, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (a[i * N + j] != b[i * N + j])
      {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");
  
  int N;
  fin >> N;

  char array[N * N];
  char new_array[N * N];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      fin >> array[i * N + j];
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      fin >> new_array[i * N + j];
    }
  }

  int ret = 7;

  //char *nn = new char[N*N];
  //memset(nn, 0, sizeof(char) * N * N);
  /*
  char *nn = rotate90(array, N);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      fout << nn[i * N + j] << " ";
    }
    fout << endl;
  }
  */

  if (check(new_array, rotate90(array, N), N) == 1)
  {
    ret = 1;
  }
  else if (check(new_array, rotate180(array, N), N) == 1)
  {
    ret = 2;
  }
  else if (check(new_array, rotate270(array, N), N) == 1)
  {
    ret = 3;
  }
  else if (check(new_array, reflection(array, N), N) == 1)
  {
    ret = 4;
  }
  else if (check(new_array, rotate90(reflection(array, N), N), N) == 1)
  {
    ret = 5;
  }
  else if (check(new_array, rotate180(reflection(array, N), N), N) == 1)
  {
    ret = 5;
  }
  else if (check(new_array, rotate270(reflection(array, N), N), N) == 1)
  {
    ret = 5;
  }
  else if (check(array, new_array, N) == 1)
  {
    ret = 6;
  }
  else
  {
    ret = 7;
  }

  fout << ret << endl;

  return 0;
}
