#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)


int main()
{
	cin.tie(NULL);

	ll N;
	cin >> N;

	/*
	if (N < 357) 
	{
		cout << 0 << endl;
	}
	else if (N < 375)
	{
		cout << 1 << endl;;
	}
	else if (N < 537)
	{
		cout << 2 << endl;
	}
	else if (N < 573)
	{
		cout << 3 << endl;
	}
	else if (N < 735) 
	{
		cout << 4 <<endl;
	}
	else if (N < 753)
	{
		cout << 5 << endl;
	}
	else if (N < 1000)
	{
		cout << 6 << endl;
	}
	*/

	/* slow
	int count = 0;
	for (ll i = 300; i < N; i++)
	{
		bool ok = true;
		ll tmp = i;
		int cnt_3 = 0;
		int cnt_5 = 0;
		int cnt_7 = 0;
		while(tmp > 0)
		{
			int x = tmp % 10;
			if ((x != 3) && (x != 5) && (x != 7))
			{
				ok = false;
				break;
			}
			if (x == 3)
			{
				cnt_3++;
			}
			else if (x == 5)
			{
				cnt_5++;
			}
			else if (x == 7)
			{
				cnt_7++;
			}
			tmp = tmp / 10;
		}
		if (ok && (cnt_3 >= 1) && (cnt_7 >= 1) && (cnt_5 >= 1))
		{
			//cout << i << endl;
			count++;
		}
	}
	*/
	
	/*
	int count = 0;
	std::vector<int> v;
	int tmp_n = N;
	while(tmp_n > 0)
	{
		v.push_back(tmp_n % 10);
		tmp_n = tmp_n / 10;
	}

	int size = tmp_n.size();
	if 

	cout << count << endl;
	*/


	/* slow
	int count = 0;
	//std::vector<int> v;
	//v.push_back(3);
	//v.push_back(5);
	//v.push_back(7);

	for (int i = 2; i < 10; i++)
	{
		bool bre = false;
		ll tmp_m = pow(10,i);
		//cout << tmp_m << endl;
		if (tmp_m > N)
		{
			break;
		}
		for (ll j = tmp_m; j < 10*tmp_m; j++)
		{
			if (j > N)
			{
				bre = true;
				break;
			}
			int n = j / tmp_m;
			if ((n != 3) && (n != 5) && (n != 7))
			{
				j = (n + 1) * tmp_m;
				continue;
			}
			bool ok = true;
			ll tmp = j;
			int cnt_3 = 0;
			int cnt_5 = 0;
			int cnt_7 = 0;
			while(tmp > 0)
			{
				int x = tmp % 10;
				if ((x != 3) && (x != 5) && (x != 7))
				{
					ok = false;
					break;
				}
				if (x == 3)
				{
					cnt_3++;
				}
				else if (x == 5)
				{
					cnt_5++;
				}
				else if (x == 7)
				{
					cnt_7++;
				}
				tmp = tmp / 10;
			}
			if (ok && (cnt_3 >= 1) && (cnt_7 >= 1) && (cnt_5 >= 1))
			{
				//cout << j << endl;
				count++;
			}

		}
		if (bre)
		{
			break;
		}
	}
	cout << count << endl;
	*/
	return 0;
}