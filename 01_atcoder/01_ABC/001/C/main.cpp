#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

///// failed because float problem
///// main_n passed

string ret_deg(int deg)
{
	float d = deg / 10.0;
	string ret = "N";
	if ((d >= 11.25) && (d < 33.75))
	{
		ret = "NNE";
	}
	else if ((d >= 33.75) && (d < 56.25))
	{
		ret = "NE";
	}
	else if ((d >= 56.25) && (d < 78.75))
	{
		ret = "ENE";
	}
	else if ((d >= 78.75) && (d < 101.25))
	{
		ret = "E";
	}
	else if ((d >= 101.25) && (d < 123.75))
	{
		ret = "ESE";
	}
	else if ((d >= 123.75) && (d < 146.25))
	{
		ret = "SE";
	}
	else if ((d >= 146.25) && (d < 168.75))
	{
		ret = "SSE";
	}
	else if ((d >= 168.75) && (d < 191.25))
	{
		ret = "S";
	}
	else if ((d >= 191.25) && (d < 213.75))
	{
		ret = "SSW";
	}
	else if ((d >= 213.75) && (d < 236.25))
	{
		ret = "SW";
	}
	else if ((d >= 236.25) && (d < 258.75))
	{
		ret = "WSW";
	}
	else if ((d >= 258.75) && (d < 281.25))
	{
		ret = "W";
	}
	else if ((d >= 281.25) && (d < 303.75))
	{
		ret = "WNW";
	}
	else if ((d >= 303.75) && (d < 326.25))
	{
		ret = "NW";
	}
	else if ((d >= 326.25) && (d < 348.75))
	{
		ret = "NNW";
	}

	return ret;
}

int ret_dis(int dis)
{
	float s = dis / 60.0;
	/*
	int tmp = s * 100;
	if (tmp % 10 >= 5)
	{
		s = (tmp / 10 + 1) / 10.0;
	}
	else
	{
		s = (tmp / 10) / 10.0;
	}
	*/
	s = floor(s*10+0.5) / 10;

	int di = 0;
	if ((s >= 0.3) && (s <= 1.5))
	{
		di = 1;
	}
	else if ((s >= 1.6) && (s <= 3.3))
	{
		di = 2;
	}
	else if ((s >= 3.4) && (s <= 5.4))
	{
		di = 3;
	}
	else if ((s >= 5.5) && (s <= 7.9))
	{
		di = 4;
	}
	else if ((s >= 8.0) && (s <= 10.7))
	{
		di = 5;
	}
	else if ((s >= 10.8) && (s <= 13.8))
	{
		di = 6;
	}
	else if ((s >= 13.9) && (s <= 17.1))
	{
		di = 7;
	}
	else if ((s >= 17.2) && (s <= 20.7))
	{
		di = 8;
	}
	else if ((s >= 20.8) && (s <= 24.4))
	{
		di = 9;
	}
	else if ((s >= 24.5) && (s <= 28.4))
	{
		di = 10;
	}
	else if ((s >= 28.5) && (s <= 32.6))
	{
		di = 11;
	}
	else if (s >= 32.7)
	{
		di = 12;
	}
	return di;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int deg, dis;
	
	cin >> deg >> dis;

	int di = ret_dis(dis);
	string s = "C";
	if (di != 0)
	{
		s = ret_deg(deg);
	}
	
	cout << s << " " << di << endl;

	
	return 0;
}