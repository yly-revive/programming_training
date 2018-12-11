#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)

int main()
{
	cin.tie(NULL);
	string S;
	cin >> S;

	int len = S.size();
	int min = 1000;

	int arr[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = S[i] - 48;
	}


	for (int j = 0; j < len - 2; j++)
	{
		int tmp = arr[j] * 100 + arr[j+1] * 10 + arr[j+2];
		int tmp_min = abs(tmp - 753);

		if (tmp_min < min)
		{
			min = tmp_min;
		}
	}
	cout << min << endl;
	return 0;
}