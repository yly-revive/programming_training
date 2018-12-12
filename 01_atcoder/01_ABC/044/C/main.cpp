#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

typedef long long ll ;
#define rep (i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/


///// this model got 200 points since ac when N <= 16, when N > 16 and N <= 50 TLE occurred

int find(int index, int remaining_value, int remaining_num, int a[], int max_idx)
{
	if (remaining_num == 0)
	{
		if (remaining_value == 0)
		{
			return 1;
		} 
		else
		{
			return 0;
		}
	}

	if (index >= max_idx - 1)
	{
		if (remaining_num > 1)
		{
			return 0;
		}
		else if (remaining_value == a[index])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	return find(index+1, remaining_value, remaining_num, a, max_idx) + find(index+1, remaining_value - a[index], remaining_num - 1, a, max_idx);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, A;
	
	cin >> N >> A;

	int x[N];

	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
	{

		//for (int j = 0; j <= N; j++)
		//{
		//	sum += find(j, i * A, i, x, N);
		//}
		sum += find(0, i * A, i, x, N);
		
	}

	cout << sum << endl;
	
	return 0;
}