#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

int main(int argc, char **argv)
{
	int N;

	cin.tie(NULL);

	cin >> N;

	int a[N];
	std::vector<int> v;
	int sum = 0;
	float ave = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
		sum += a[i];
	}

	ave = ((float)sum) / N;

	sort(v.begin(), v.end());

	int j = 0;
	for (j = 0; j < N; j++)
	{
		if (v[j] >= ave)
		{
			break;
		}
	}

	std::vector<int> value;
	float left = abs(v[j - 1] - ave);
	float right = abs(v[j] - ave);
	if (right > left)
	{
		value.push_back(v[j-1]);
	}
	else if (right < left)
	{
		value.push_back(v[j]);
	}
	else
	{
		value.push_back(v[j-1]);
		value.push_back(v[j]);
	}

	for (int i = 0; i < N; i++)
	{
		if ((a[i] == value[0]) || ((value.size() == 2) && (a[i] == value[1])))
		{
			cout << i << endl;
			break;
		}
	}

	return 0;

}