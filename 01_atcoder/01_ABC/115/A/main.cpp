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

	int D;
	cin >> D;

	if (D == 25)
	{
		cout << "Christmas" << endl;
	}
	else if (D == 24)
	{
		cout << "Christmas Eve" << endl;
	}
	else if (D == 23)
	{
		cout << "Christmas Eve Eve" << endl;
	}
	else if (D == 22)
	{
		cout << "Christmas Eve Eve Eve" << endl;
	}

	return 0;
}