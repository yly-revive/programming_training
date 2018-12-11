/*
ID: ylyyanl1
TASK: dualpal
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
/*
A number that reads the same from right to left as when read from left to right is called a palindrome. The number 12321 is a palindrome; the number 77778 is not. Of course, palindromes have neither leading nor trailing zeroes, so 0220 is not a palindrome.

The number 21 (base 10) is not palindrome in base 10, but the number 21 (base 10) is, in fact, a palindrome in base 2 (10101).

Write a program that reads two numbers (expressed in base 10):

N (1 <= N <= 15)
S (0 < S < 10000)
and then finds and prints (in base 10) the first N numbers strictly greater than S that are palindromic when written in two or more number bases (2 <= base <= 10).
Solutions to this problem do not require manipulating integers larger than the standard 32 bits.
*/

/*
A single line with space separated integers N and S.
3 25
*/

/*
N lines, each with a base 10 number that is palindromic when expressed in at least two of the bases 2..10. The numbers should be listed in order from smallest to largest.
26
27
28
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


int main() {
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");
  
  int N, S;
  fin >> N >> S;
  int count = 0;

  int loop_val = S + 1;
  while(count < N)
  {
  	int times = 0;
  	int i = 2;
  	for (i = 2; i <= 10; i++)
  	{
  		if (check_palindrome(loop_val, i))
  		{
  			times++;
  			if (times >= 2)
  			{
  				break;
  			}
  		}
  	}
  	if (i <= 10)
  	{
  		fout << loop_val << endl;
  		count++;
  	}
  	loop_val++;
  }

  return 0;
}
