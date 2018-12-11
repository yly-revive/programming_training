#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(int argc, char **argv)
{
	cin.tie(NULL);

	int N;
	cin >> N;

	int x[N], y[N], h[N];

	int i;
	for (i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i] >> h[i];
	}

	for (i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			long long ch = 0;
			long long limit = LONG_MAX;
			int k = 0;
			for (k = 0; k < N; k++)
			{
				if (h[k] == 0)
				{
					int tmp_limit = abs(x[k]-i) + abs(y[k] - j);
					if (ch > tmp_limit)
					{
						break;
					}
					if (tmp_limit < limit)
					{
						limit = tmp_limit;
					}
				}
				else 
				{
					if (ch == 0)
					{
						ch = abs(x[k] - i) + abs(y[k] - j) + h[k];

					}
					else if (ch != (abs(x[k] - i) + abs(y[k] - j) + h[k]))
					{
						break;
					}

					if ((ch > limit) || (ch < 1) )
					{
						break;
					}
				}
				
			}
			if (k >= N)
			{
				cout << i << " " << j << " " << ch << endl;
				return 0;
			}
			//cout << i << " " << j << " " << ch << endl;
		}

	}
	
	return 0;
}