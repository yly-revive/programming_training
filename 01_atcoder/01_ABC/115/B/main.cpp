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
	std::vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());


	int total = 0;

	int i = 0;
	for (i = 0; i < N - 1; i++)
	{
		total += v[i];
	}

	total += v[N-1] / 2;

	cout << total << endl;

	return 0;
}