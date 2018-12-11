/*
ID: ylyyanl1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main() {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");
  
  int num;
  fin >> num;

  std::map<std::string, int> members;
  std::vector<string> v;

  for (int i = 0; i < num; i++)
  {
  	string tmp;
  	fin >> tmp;
  	members[tmp] = 0;
  	v.push_back(tmp);
  }

  while(!fin.eof())
  {
  	string s_name;
  	int money, s_num;
  	fin >> s_name >> money >> s_num;
  	if (s_num == 0) 
  	{
  		members[s_name] += money;
  		continue;
  	}
  	int average = money / s_num;

  	members[s_name] = members[s_name] - average * s_num;
  	for (int i = 0; i < s_num; i++)
  	{
  		string g_name;
  		fin >> g_name;
  		members[g_name] += average;
  	}
  }

  /*
  for (int i = 0; i < num; i++)
  {
  	fout << members
  }
  */
  
  /*
  for (auto it = members.begin(); it!= members.end(); it++)
  {
  	fout << it->first << " " << it->second << endl;
  }
  */
  int size = v.size();

  for (int i = 0; i < size; i++)
  {
  	fout << v[i] << " " << members[v[i]] << endl;
  }

  return 0;
}
