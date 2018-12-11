#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

//#include <bits/stdc++.h>

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
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}
	

	cout << sum << endl;

	return 0;
}