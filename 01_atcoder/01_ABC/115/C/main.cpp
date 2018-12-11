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

	int N, K;
	cin >> N >> K;

	std::vector<ll> v;

	for (int i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	std::vector<ll> v2;
	for (int i = K-1; i < N; i++)
	{
		int diff = v[i] - v[i - (K-1)];
		v2.push_back(diff);
	}

	sort(v2.begin(), v2.end());

	cout << v2[0] << endl;

	return 0;
}