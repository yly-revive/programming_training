#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

int compare(string &s1, string &s2)
{
	if (s1.size() != s2.size()) return s1.size() < s2.size();

	int i = 0;
	while(s1[i] == s2[i])
	{
		i++;
		if (i >= s1.size())
		{
			break;
		}
	}
	if (i == s1.size())
	{
		return 0;
	}
	else
	{
		return s1[i] < s2[i];
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	string s[N];

	//rep(i,N)
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}

	sort(s, s+N, compare);
		
	//cout << "S;" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << s[i];
	}

	cout << endl;
	
	return 0;
}