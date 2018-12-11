/*
ID: ylyyanl1
TASK: milk
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class milk
{
public:
  int price;
  int max_size;
  
};

bool compare(milk &a, milk &b)
{
  //if (a.price < b.price)
  return a.price < b.price;
  // return a.price <= b.price; // segmentation fault when sorting after
}


int main() {
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");
  
  int N, M;
  fin >> N >> M;

  vector<milk> item;

  for (int i = 0; i < M; i++)
  {
    milk tmp;
    fin >> tmp.price >> tmp.max_size;
    item.push_back(tmp);
  } 

  sort(item.begin(), item.end(), compare);  // if qsort O(nlogn)


  int total_cost = 0;
  int total_unit = 0;

  
  for (int i = 0; i < item.size(); i++)
  {
    if (total_unit >= N)
    {
      break;
    }

    milk tmp = item[i];
    int buy_unit = 0;
    if (tmp.max_size + total_unit > N)
    {
      buy_unit = N - total_unit;
    }
    else
    {
      buy_unit = tmp.max_size;
    }

    total_cost += buy_unit * tmp.price;
    total_unit += buy_unit;
  }

  fout << total_cost << endl;

  return 0;
}
