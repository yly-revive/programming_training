#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

ll ret_total(int x, int y, int a, int b, int h)
{
	if ((x + a >= h) && (y < b))
	{
		return 0;
	}

	if ((x == 0) && (y == 0))
	{
		return 0;
	}

	if (x == 0)
	{
		return 1;
	}

	if (y == 0)
	{
		return 1;
	}

	return (ret_total(x-1, y, a, b, h) + ret_total(x, y-1, a, b, h)) % 1000000007;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int H, W, A, B;
	cin >> H >> W >> A >> B;

	/*
	int a[H][W];
	memset(a, 0, sizeof(int) * H * W);

	cout << "t" << endl;
	
	for (int i = 1; i < H; i++)
	{
		if (i < H - A)
		{
			a[i][0] = 1;
		}
	}
	//cout << "start = " << a[H-1][W-1] << endl;
	for (int i = 1; i < W; i++)
	{
		a[0][i] = 1;
	}

	for (int i = 1; i < H; i++)
	{
		for (int j = 1; j < W; j++)
		{
			if ((i >= H - A) && (j < B))
			{
				continue;
			}
			ll tmp = a[i-1][j] + a[i][j-1];
			a[i][j] = tmp % 1000000007;
		}
	}

	cout << a[H-1][W-1] << endl;
	*/

	/*
	ll a[2][W];
	memset(a, 0, sizeof(ll) * 2 * W);
	for (int i = 1; i < W; i++)
	{
		a[0][i] = 1;
	}

	int h = 1;
	while(h < H)
	{
		if (h + A < H - 1)
		{
			a[1][0] = 1;
		}

		for (int i = 1; i < W; i++)
		{
			if ((h + A >= H - 1) && (i < B))
			{
				a[1][i] = 0;
				continue;
			}
			a[1][i] = (a[0][i] + a[1][i-1]) % 1000000007;
		}

		memcpy(a[0], a[1], sizeof(ll) * W);
		memset(a[1], 0, sizeof(ll) * W);
		h++;
	}

	cout << a[0][W-1] << endl;
	*/
	cout << ret_total(H-1,W-1, A, B, H) << endl;

	return 0;
}