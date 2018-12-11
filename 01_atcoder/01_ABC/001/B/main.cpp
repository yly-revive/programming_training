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
	//ios::sync_with_stdio(false);

	int m;
	
	cin >> m;

	if (m < 100)
	{
		printf("00\n");
	}
	else if (m <= 5000)
	{
		printf("%02d\n", int((m / 1000.0) * 10));
	}
	else if ((m >= 6000) && (m <=30000))
	{
		printf("%02d\n", int((m / 1000.0) + 50));
	}
	else if ((m>=35000) && (m <= 70000))
	{
		float tmp = m / 1000.0;
		printf("%02d\n", int((tmp - 30)) / 5 + 80);
	}
	else if (m >= 70000)
	{
		printf("89\n");
	}

	
	return 0;
}