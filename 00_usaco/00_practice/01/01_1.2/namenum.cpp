/*
ID: ylyyanl1
TASK: namenum
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

int ret_key_alpha(char alpha)
{
  char first = alpha;
  if ((first <= 'C') && (first >= 'A'))
  {
    return 2;
  }
  else if ((first <= 'F') && (first >= 'D'))
  {
    return 3;
  }
  else if ((first <= 'I') && (first >= 'G'))
  {
    return 4;
  }
  else if ((first <= 'L') && (first >= 'J'))
  {
    return 5;
  }
  else if ((first <= 'O') && (first >= 'M'))
  {
    return 6;
  }
  else if ((first <= 'S') && (first >= 'P'))
  {
    return 7;
  }
  else if ((first <= 'V') && (first >= 'T'))
  {
    return 8;
  }
  else if ((first <= 'Y') && (first >= 'W'))
  {
    return 9;
  }
  else 
  {
    return 0;
  }
}
int ret_key(string value)
{
  char first = value[0];
  //cout << first << endl;
  return ret_key_alpha(first);
  
}

int main() {
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  
  ifstream fdict("dict.txt");

  long long N;
  fin >> N;

  map<int, std::vector<string> > v;

  string tmp;
  while(fdict >> tmp)
  {
    v[ret_key(tmp)].push_back(tmp);
  }

  long long tmp_n = N;
  std::vector<int> number;
  while(tmp_n)
  {
    number.push_back(tmp_n % 10);
    tmp_n = tmp_n / 10;
  }

  /*
  for (int i = number.size() - 1; i >= 0; i--)
  {
    cout << number[i] << endl;
  }
  cout << number.back() << endl;
  */
  std::vector<string> search = v[number.back()];
  int len = search.size();

  int num_len = number.size();

  std::vector<string> result;

  for (int i = 0; i < len; i++)
  {
    //fout << search[i] << endl;
    if (search[i].size() != num_len)
    {
      continue;
    }
    bool fit = true;
    string item = search[i];
    for(int j = num_len - 2; j >=0 ; j--)
    {
      if (number[j] != ret_key_alpha(item[num_len - j - 1]))
      {
        fit = false;
        break;
      }
    }

    if (fit)
    {
      result.push_back(item);
    }
  }

  for (int i = 0; i < result.size(); i++)
  {
    fout << result[i] << endl;
  }

  if (result.size() == 0)
  {
    fout << "NONE" << endl;
  }

  return 0;
}
