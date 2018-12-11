#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	cin.tie(NULL);

	int N, T;
	cin >> N >> T;

	int c[N], t[N];

	for (int i = 0; i < N; i++)
	{
		cin >> c[i] >> t[i];
	}

	int min_cost = 1001;
	for (int i = 0; i < N; i++)
	{
		if (t[i] <= T)
		{
			if (c[i] < min_cost)
			{
				min_cost = c[i];
			}
		}
	}

	if (min_cost == 1001)
	{
		cout << "TLE" << endl;
	}
	else
	{
		cout << min_cost;
	}
	
	return 0;
}