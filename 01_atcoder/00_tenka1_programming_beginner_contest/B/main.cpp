#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)

int ret_cookie(int c)
{
	if (c % 2)
	{
		return c - 1;
	}
	
	return c;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ll A, B;
	int K;

	cin >> A >> B >> K;

	/*
	int times = 1;
	while(times <= K)
	{
		if (times % 2)
		{
			A = ret_cookie(A);
			A /= 2;
			B += A; 
		}
		else
		{
			B = ret_cookie(B);
			B = B / 2;
			A += B;
		}
		times++;
	}
	*/
	for (int i = 0; i < K; i++)
	{
		if (i % 2 == 0)
		{
			B += A / 2;
			A = A / 2;
		}
		else
		{
			A += B / 2;
			B = B / 2;
		}
	}

	cout << A << " " << B << endl;

	return 0;
}