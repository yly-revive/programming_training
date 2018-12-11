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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
		
	cin >> N;

	int l[2*N];
	for (int i = 0; i < 2*N; i++)
	{
		cin >> l[i];
	}

	sort(l, l + 2*N);

	/*
	for (int i = 0; i < 2 * N; i++)
	{
		cout << l[i] << endl;
	}
	*/

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += l[2*i];
	}
	
	cout << sum << endl;

	return 0;
}