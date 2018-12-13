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

	string s[3];
	
	cin >> s[0] >> s[1] >> s[2];

	int i[3] = {0,0,0};

	int turn = 0;

	while(s[turn].size() > i[turn])
	{
		i[turn]++;
		turn = s[turn][i[turn] - 1] - 'a';
	}

	if (turn == 0)
	{
		cout << "A" << endl;
	}
	else if (turn == 1)
	{
		cout << "B" << endl;
	}
	else
	{
		cout << "C" << endl;
	}


	
	return 0;
}