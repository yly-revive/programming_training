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
class alp
{
public:
	int start;
	int end;
	int count;

	alp()
	{
		start = 0;
		end = 0;
		count = 0;
	}
};

/* TLE
int t_start = -1;
int t_end = -1;

bool check(string s, int start, int end)
{
	alp a[26];
	if (end - start < 1)
	{
		return false;
	}
	for (int i = start; i <= end; i++)
	{
		int index = s[i-1] - 97;

		//cout << index << endl;
		if (a[index].count == 0)
		{
			a[index].start = i;
		}

		a[index].count++;
		a[index].end = i;
	}

	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i].count > a[max].count)
		{
			max = i;
		}
	}
	//cout << "max="<< max << endl;
	if (a[max].count <= (end - start + 1) / 2)
	{
		if (!check(s, start + 1, end))
		{
			check(s, start, end - 1);
		}
	}
	else
	{
		t_start = start;
		t_end = end;
		return true;
	}
	return false;
}
*/

#if 0
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	
	cin >> s;

	
	alp a[26];

	for (int i = 1; i <= s.size(); i++)
	{
		int index = s[i-1] - 97;

		//cout << index << endl;
		if (a[index].count == 0)
		{
			a[index].start = i;
		}

		a[index].count++;
		a[index].end = i;
	}

	/*
	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i].count > a[max].count)
		{
			max = i;
		}
	}
	//cout << "max="<< max << endl;
	if (a[max].count < s.size() / 2)
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	cout << a[max].start << " " << a[max].end << endl;
	*/

	for (int i = 0; i < 26; i++)
	{
		int span = a[i].end - a[i].start + 1;
		if (a[i].count > span / 2)
		{
			cout << a[i].start << " " << a[i].end << endl;
		}
	}
	/*
	check(s, 1, s.size());

	cout << t_start << " " << t_end << endl;
	*/
	return 0;
}
#endif

// ac
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	
	cin >> s;

	int i = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (i < s.size() - 1)
		{
			if (s[i+1] == s[i])
			{
				cout << i+1 << " " << i+2 << endl;
				break;
			}
			else if (i < s.size() - 2)
			{
				if (s[i] == s[i+2])
				{
					cout << i+1 << " " << i + 3 << endl;
					break;
				}
			}
		}
	}

	if (i == s.size())
	{
		cout << "-1 -1" << endl;
	}
}