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

	string w;
	
	cin >> w;

	char a[26];

	memset(a, 0, sizeof(char)*26);

	for (int i = 0; i < w.size(); i++)
	{
		int index = w[i] - 'a';
		a[index] = a[index] ^ 0x01; 
	}

	bool is_be = true;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != 0)
		{
			is_be = false;
			break;
		}
	}

	if (is_be)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
	
}