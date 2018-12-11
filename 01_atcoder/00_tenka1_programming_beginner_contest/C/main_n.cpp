#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
typedef long long int ll;

int main(int argc, char **argv)
{
	cin.tie(0);
    ios::sync_with_stdio(false);

	int N;
	cin >> N;

	std::vector<int> A_v;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		A_v.push_back(tmp);
	}

	sort(A_v.begin(), A_v.end());

	ll max_v = 0;

	for (int i=0; i < N / 2; i++)
	{
		max_v -= A_v[i] * 2;
	}

	if (N % 2 == 0)
	{
		for (int i = N / 2; i < N; i++)
		{
			max_v += A_v[i] * 2;
		}
		//max_v = max_v - (A_v[N/2+1] - A_v[N/2]);
		max_v = max_v - (A_v[N/2] - A_v[N/2-1]);
	
	}
	else
	{
		for (int i = N / 2 + 1; i < N; i++)
		{
			max_v += A_v[i] * 2;
		}
		int tmp = min(A_v[N/2] - A_v[N/2 -1], A_v[N/2+1] - A_v[N/2]);
		//int tmp = max(A_v[N/2] - A_v[N/2 -1], A_v[N/2+1] - A_v[N/2]);
		//cout << "tmp=" << tmp << endl;
		max_v = max_v - tmp;
		//max_v = max_v + tmp;
	}
	
	cout << max_v;

	return 0;
	
}

