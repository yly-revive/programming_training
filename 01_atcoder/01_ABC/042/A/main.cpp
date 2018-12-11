#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C;
	
	cin >> A >> B >> C;

	int c_5 = 0;
	int c_7 = 0;
	if (A == 5)
	{
		c_5++;
	}
	else if (A == 7)
	{
		c_7++;
	}

	if (B == 5)
	{
		c_5++;
	}
	else if (B == 7)
	{
		c_7++;
	}
	if (C == 5)
	{
		c_5++;
	}
	else if (C == 7)
	{
		c_7++;
	}

	if ((c_5 == 2) && (c_7 == 1))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}