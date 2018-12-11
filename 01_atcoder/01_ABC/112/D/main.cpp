#include <iostream>
using namespace std;

#include <cmath>

int main()
{
	long N, M;
	cin >> N >> M;

	/*
	for (int i = int(sqrt(M)); i > 0; i--)
	{
		if (M % i == 0)
		{
			long remainder = M / i;
			if (remainder >= N)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	*/
	/*
	for (long i = M; i > 0; i--)
	{
		if (M % i == 0)
		{
			long remainder = M / i;
			if (remainder >= N)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	*/
	int max = 1;
	for (int i = 1; i <= int(sqrt(M)); i++)
	{
		if (M % i == 0)
		{
			/*
			long remainder = M / i;
			if (remainder >= N)
			{
				cout << i << endl;
				return 0;
			}
			*/
			if (i >= N)
			{
				cout << M / i << endl;
				return 0;
			}
			else if ((i > max) && (M / i >= N))
			{
				max = i;
			}
		}
	}
	cout << max << endl;
	return 0;
}