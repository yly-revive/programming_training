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

//// TLE
ll f(ll b, ll n)
{
	if (b > n)
	{
		return n;
	}
	else
	{
		return f(b, n / b) + (n % b);
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ll n, s;
	
	cin >> n >> s;

	//cout << f(10, 87654);

	int count = 0;

	if (s == n)
	{
		count = 2;
	}

	ll mem = n + 1;

	for (ll i = 2; i < n; i++)
	{
		if (f(i, n) == s)
		{
			count++;
			if ((count == 1) || ((n == s) && (count == 3)))
			{
				mem = i;
			}
			
		}

		if (count >= 2)
		{
			break;
		}
	}

	if (count >= 2)
	{
		cout << mem << endl;
	}
	else 
	{
		cout << "-1" << endl;
	}
	
	return 0;
}