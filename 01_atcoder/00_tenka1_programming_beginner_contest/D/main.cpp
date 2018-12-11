#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int k = 2;
	bool found = false;
	while(true)
	{
		int number = k*(k-1)/2;
		if ( number < N )
		{
			k++;
			continue;
		}
		if (number > N)
		{
			break;
		}
		if (number == N)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		cout << k << endl;
		int a[k][k - 1];
		memset(a, 0, sizeof(int) * k * (k-1));
		for (int i = 0; i < k; i++)
		{
			int step = 1;
			int v_step = i - 1;
			int v_times = i - 1;
			for (int j = 0; j < k - 1; j++)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						a[i][j] = 1;
						cout << k - 1 << " ";
					}
					else
					{
						cout << " ";
						a[i][j] = a[i][j-1] + step;
						step++;
					}
					cout << a[i][j];
					
				}
				else
				{
					if (v_times > 0)
					{
						a[i][j] = a[i-1][j] + v_step;
						v_times--;
					}
					else if (v_times == 0)
					{
						a[i][j] = a[i-1][j];
						v_times--;
					}
					else
					{
						a[i][j] = a[i-1][j] + 1;
					}
					if (j > 0)
					{
						cout << " ";
					}
					else if (j == 0)
					{
						cout << k - 1 << " ";
					}
					cout << a[i][j];
				}
			}
			cout << endl;
		}

	}

	return 0;
}