#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	if (S.size() == 2)
	{
		cout << S << endl;
	}
	else if (S.size() == 3)
	{
		reverse(S.begin(), S.end());
		cout << S << endl;
	}
	return 0;
}