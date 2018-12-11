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

	int N;
	cin >> N;

	std::vector<ll> v;
	for (int i = 0; i < 3 * N; ++i)
	{
		/* code */
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(begin(v), end(v));

	ll total = 0;
	for (int i = N; i < 3 * N; i=i+2)
	{
		total += v[i];
	}

	cout << total << endl;

	return 0;
}