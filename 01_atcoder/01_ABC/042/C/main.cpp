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

	int d[K];

	for (int i = 0; i < K; i++)
	{
		cin >> d[i];
	}

	//sort(d, d+K);

	//int tmp = N;

	std::vector<int> v;
	int a[10];

	memset(a, 0, sizeof(int) * 10);

	for (int i = 0; i < K; i++)
	{
		a[d[i]] = 1;
	}

	/*
	while(tmp)
	{
		int m_dig = tmp % 10;

		for (int j = 0; j < 10; j++)
		{
			if ((j >= m_dig) && (a[j] == 0))
			{
				v.push_back(j);
				break;
			}
		}

		tmp = tmp / 10;
	}

	int total = 0;
	for (int i = v.size()-1; i >= 0; i--)
	{

		if (total == 0)
		{
			total = v[i];
		}
		else
		{
			total = total * 10 + v[i];
		}
	}
	
	cout << total << endl;
	*/
	int m = 0;
	while(true)
	{
		int tmp = N + m;
		bool found = true;
		while(tmp)
		{
			int m_dig = tmp % 10;

			if (a[m_dig] == 1)
			{
				found = false;
				break;
			}
			tmp = tmp / 10;
		}

		if (found)
		{
			cout << N + m << endl;
			break;
		}
		m++;
	}
	return 0;
}