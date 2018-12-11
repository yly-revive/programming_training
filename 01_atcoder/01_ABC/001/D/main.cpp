#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

class Timeblock
{
	public:
		int start;
		int end;
};

int round(int value, bool position)
{
	int rem = value % 5;
	int ret = value;

	if (!position)
	{
		if (rem != 0)
		{
			ret = value - rem;
		}
	}
	else
	{
		if (rem != 0)
		{
			ret = value - rem + 5;
			if (ret % 100 == 60)
			{
				ret = (ret / 100 + 1) * 100;
			}
		}
	}

	return ret;

}

int compare(Timeblock &a, Timeblock &b)
{
	if (a.start != b.start) return a.start < b.start;

	return a.end < b.end;
}

int main()
{
	cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	//string t[N];
	vector<Timeblock> t;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		Timeblock temp;
		temp.start = round( (tmp[0] - '0') * 1000 + (tmp[1] - '0') * 100 + (tmp[2] - '0') * 10 + (tmp[3] - '0'), false);
		temp.end = round( (tmp[5] - '0') * 1000 + (tmp[6] - '0') * 100 + (tmp[7] - '0') * 10 + (tmp[8] - '0'), true );
		
		t.push_back(temp);

	}

	sort(t.begin(), t.end(), compare);

	/*
	cout << "start:" << endl;
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i].start << "-" << t[i].end << endl;
	}

	cout << "end." << endl;
	*/

	std::vector<Timeblock> v;

	v.push_back(t[0]);
	for (int i = 1; i < t.size(); i++)
	{
		if (t[i].start > v.back().end)
		{
			v.push_back(t[i]);
		}
		else
		{
			if (t[i].end > v.back().end)
			{
				v.back().end = t[i].end;
			}
			
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << "-" << v
		printf("%04d-%04d\n", v[i].start, v[i].end);
	}

	
	return 0;
}