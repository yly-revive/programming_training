/*
ID: ylyyanl1
TASK: palsquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
//#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
//#include <algorithm>

using namespace std;
/*
Palindromes are numbers that read the same forwards as backwards. The number 12321 is a typical palindrome.

Given a number base B (2 <= B <= 20 base 10), print all the integers N (1 <= N <= 300 base 10) such that the square of N is palindromic when expressed in base B; also print the value of that palindromic square. Use the letters 'A', 'B', and so on to represent the digits 10, 11, and so on.

Print both the number and its square in base B.
*/

/*
10
*/

/*
1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696
*/

bool check_palindrome(int n, int base)
{
  bool is_palindrome = true;
  //int square_n = n * n;

  std::vector<int> v;
  int tmp = n;
  while(tmp > 0)
  {
    v.push_back(tmp % base);
    tmp = tmp / base;
  }

  int len = v.size();
  for(int i = 0; i < len / 2; i++)
  {
    if (v[i] != v[len - i - 1])
    {
      is_palindrome = false;
      break;
    }
  }

  return is_palindrome;
}

string ret_value(int n, int base)
{
  std::vector<int> v;
  int tmp = n;
  while(tmp > 0)
  {
    v.push_back(tmp % base);
    tmp = tmp / base;
  }
  //std::reverse(v.begin(), v.end());

  string ret = "";
  for (int i = v.size() - 1; i >= 0; i--)
  {
    if (v[i] >= 10)
    {
      ret += char(v[i] + 'A' - 10);
    }
    else
    {
      ret += char(v[i] + 48);
    }
    //ret += v[i]
  }
  return ret;
}

int main() {
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");
  
  int B;
  fin >> B;

  for (int i = 1; i <= 300; i++)
  {
    int square = i * i;
    if (check_palindrome(square, B))
    {
      fout << ret_value(i, B) << " " << ret_value(square, B) << endl;
    }
  }

  return 0;
}
