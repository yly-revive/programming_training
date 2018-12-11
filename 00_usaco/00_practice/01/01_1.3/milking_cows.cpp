/*
ID: ylyyanl1
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class milking
{
public:
  int begin;
  int end;
};

bool compare(milking time1, milking time2)
{
  if (time1.begin != time2.begin) 
  {
    return time1.begin < time2.begin;
  }

  return time1.end < time2.end;
}
/*
int compare(milking &time1, milking &time2, cmp_begin)
{
  if (cmp_begin)
  {
    if (time1.begin <= time2.begin)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if (time1.end <= time2.end)
    {
      return 1;
    }
    else
    {
      return 0;
    } 
  }
}
*/

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");
  
  int N;
  fin >> N;

  //milking time[N];
  std::vector<milking> v;
  for (int i = 0; i < N; i++)
  {
    milking tmp;
    fin >> tmp.begin >> tmp.end;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end(), compare);

  std::vector<milking> stack_milk;

  for (int i = 0; i < v.size(); i++)
  {
    //cout << v[i].begin << endl;
    if (stack_milk.size() == 0)
    {
      stack_milk.push_back(v[i]);
    }
    else
    {
      milking last_milk = stack_milk.back();
      if (v[i].begin > last_milk.end)
      {
        stack_milk.push_back(v[i]);
      }
      else if (v[i].end > last_milk.end)
      {
        //last_milk.end = v[i].end;
        stack_milk.back().end = v[i].end;
      }
    }
  }

  int least_one = 0;
  int no_one = 0;

  for (int i = 0; i < stack_milk.size(); i++)
  {
    //cout << stack_milk[i].begin << " " << stack_milk[i].end << endl;

    int tmp_least = stack_milk[i].end - stack_milk[i].begin;
    if (tmp_least > least_one)
    {
      least_one = tmp_least;
    }

    if (i > 0)
    {
      int tmp_no_one = stack_milk[i].begin - stack_milk[i - 1].end;
      if (tmp_no_one > no_one)
      {
        no_one = tmp_no_one;
      }
    }
  }

  //cout << least_one << " " << no_one << endl;
  fout << least_one << " " << no_one << endl;

  return 0;
}
