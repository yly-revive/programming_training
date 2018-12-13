#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

typedef long long ll ;
#define rep (i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	
	cin >> s;
	int n = s.size();

	ll c = 0;

	for (int i = 0; i < (1 << (n-1)); i++)
	{
		ll num = s[0] - '0';
		for(int j = 0; j < n-1; j++)
		{
			if (i & (1<<j))
			{
				c+=num;
				num=0;
			}
			num = num * 10 + (s[j+1] - '0');
		}
		c+=num;
	}
	cout << c << endl;

	
	return 0;
}