/*
ID: ylyyanl1
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define LEAP_MONTH 29

int is_leap(int year);

int main() {
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");
  
  int N;
  fin >> N;

  int counter[7] = {0};
  int counter_day = 0;
  int month_counter[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  for(int i = 0; i < N; i++)
  {
    int tmp_year = 1900 + i;
    int isLeap = is_leap(tmp_year);
    
    for (int j = 1; j <= 12; j++)
    {
      if ( (i + j) == 1 )
      {
        counter_day = (12 % 7 + counter_day) % 7;
      }
      else
      {
        if (isLeap && (j - 1 == 2) )
        {
          counter_day = (LEAP_MONTH % 7 + counter_day) % 7;
        }
        else
        {
          int last_month_index = ((j - 2) >= 0) ? (j - 2) : j - 2 + 12;
          counter_day = (month_counter[last_month_index] % 7 + counter_day) % 7;
        }
      }
      counter[counter_day]++;
    }
  }
  
  fout << counter[5] << " " << counter[6];

  for (int i = 0; i < 5; i++)
  {
    fout << " " << counter[i];
  }

  fout << endl;

  return 0;
}

int is_leap(int year)
{
  return ( ( (year % 100 == 0) && (year % 400 == 0) ) || ( (year % 100 != 0) && (year % 4 == 0) ) ) ? 1 : 0;
}
