#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

int main(int argc, char **argv)
{
	int N, T, A;

	cin.tie(NULL);

	cin >> N >> T >> A;

	int H[N];

	for (int i = 0; i < N; i++) 
	{
		cin >> H[i];
	}

	float h[N];

	for (int i = 0; i < N; i++)
	{
		h[i] = T - H[i] * 0.006;
	}

	int nearest_index = 0;
	float nearest_value = abs(h[0] - A);

	for (int i = 1; i < N; i++)
	{
		float tmp = abs(h[i] - A);
		if (tmp < nearest_value)
		{
			nearest_value = tmp;
			nearest_index = i;
		}
	}

	cout << nearest_index + 1;

	return 0;

}