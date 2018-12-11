#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

// error

void ret_max(std::vector<int> arg, std::vector<int> &value, int start, int end, int num, int sum, int max)
{
	if (num == 0)
	{
		value.push_back(sum);
	}

	for (int i = start; i < end; i++)
	{
		if (num == max)
		{
			ret_max(arg, value, i + 1, end, num - 1, arg[i], max); 
		}
		else
		{
			ret_max(arg, value, i + 1, end, num - 1, sum & arg[i], max); 
		}
		
	}
}


int main(int argc, char **argv)
{
	int N, K;

	cin.tie(NULL);

	cin >> N >> K;

	int a[N];

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	std::vector<int> sum;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			int tmp_sum = 0;
			for (int k = 0; k < j; k++)
			{
				tmp_sum += a[i+k];
			}
			sum.push_back(tmp_sum);
		}
	}

	int max = 0;
	int len = sum.size();
	//cout << len<<endl;
	assert(len == (N * (N + 1) / 2));
	//int max = 1 << K;
	/*
	for (int i = 0; i < len; i++)
	{

	}
	*/

	std::vector<int> v;
	ret_max(sum, v, 0, len, K, 0, K);

	sort(v.begin(), v.end());

	int v_len = v.size();
	//cout << v_len << endl;
	
	//cout << v[5] << endl;

	cout << v[v_len - 1] << endl;

	return 0;

}