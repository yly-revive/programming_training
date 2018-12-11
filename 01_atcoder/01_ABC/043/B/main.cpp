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

	string S;
	
	std::vector<char> v;

	cin >> S;

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '0')
		{
			v.pb('0');
		}
		else if (S[i] == '1')
		{
			v.pb('1');
		}
		else if (S[i] == 'B')
		{
			if (v.size() > 0)
			{
				v.pop_back();
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	
	return 0;
}