#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	
	cin >> N;

	int a[N];

	float sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	//sum += 0.5;

	int bb = 0;
	if (sum >= 0)
	{
		bb = (sum / N + 0.5);
	}
	else
	{
		bb = (sum / N - 0.5);
	}
	
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		ret += pow((a[i] - bb), 2);
	}

	cout << ret << endl;

	
	return 0;
}