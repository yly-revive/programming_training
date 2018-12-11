#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

#if false
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//cout << "S" << endl;
	string S;
	cin >> S;

	int layer = S.size();
	int total = 0;

	for (int i = 0; i < layer; i++)
	{
		for (int j = 0; j < layer; j++)
		{
			if ( i == j )
			{
				continue;
			}

			if (i < j)
			{
				if (S[i] == 'U')
				{
					total++;
				}
				else if (S[i] == 'D')
				{
					/*
					//bool up = false;
					int k = 0;
					for (k = 0; k < i; k++)
					{
						if (S[k] == 'U')
						{
							break;
						}
					}
					if (k < i)
					{
						total += 2;
					}
					*/
					total += 2;
				}
			}
			else if (i > j)
			{
				if (S[i] == 'D')
				{
					total++;
				}
				else if (S[i] == 'U')
				{	
					/*
					int k = 0;
					for (k = i+1; k < layer; k++)
					{
						if (S[k] == 'D')
						{
							break;
						}
					}
					if (k < layer)
					{
						total += 2;
					}
					*/
					total += 2;
				}
			}
		}
	}

	cout << total << endl;

	return 0;
}
#endif

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	//cout << "T" << endl;
	int layer = S.size();
	ll total = 2 * (layer-1);

	for (int i = 1; i < layer - 1; i++)
	{
		if (S[i] == 'U')
		{
			total += layer - (i+1);

			total += i*2;
			
		}
		else if (S[i] == 'D')
		{
			total += i;
			
			total += 2 * (layer - i - 1);
			
		}

	}

	cout << total << endl;

	return 0;
}

