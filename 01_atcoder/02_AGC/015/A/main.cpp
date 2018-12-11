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

	ll N, A, B;

	cin >> N >> A >> B;

	if (A > B)
	{
		cout << 0 << endl;
		return 0;
	}

	if ((N == 1) && (A != B))
	{
		cout << 0 << endl;
		return 0;
	}

	ll min = A * (N - 1) + B;
	ll max = A + B * (N-1);

	cout << max - min + 1 << endl;


	return 0;
}