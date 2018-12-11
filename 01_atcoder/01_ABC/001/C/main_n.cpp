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

// passed

string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"}; 
string ret_deg(int deg)
{

	int index = ((deg * 10+1125) / 2250) % 16;

	return dir[index];
}

int ret_dis(int dis)
{
	/*
	float s = dis / 60.0;
	
	s = floor(s*10+0.5) / 10;
	*/
	int s = dis; 
	int di = 0;
	if ((s >= 0.25*60) && (s < 1.55*60))
	{
		di = 1;
	}
	else if ((s >= 1.55*60) && (s < 3.35*60))
	{
		di = 2;
	}
	else if ((s >= 3.35*50) && (s < 5.45*60))
	{
		di = 3;
	}
	else if ((s >= 5.45 * 60) && (s < 7.95*60))
	{
		di = 4;
	}
	else if ((s >= 7.95 * 60) && (s < 10.75*60))
	{
		di = 5;
	}
	else if ((s >= 10.75*60) && (s < 13.85*60))
	{
		di = 6;
	}
	else if ((s >= 13.85*60) && (s < 17.15 * 60))
	{
		di = 7;
	}
	else if ((s >= 17.15*60) && (s < 20.75*60))
	{
		di = 8;
	}
	else if ((s >= 20.75*60) && (s < 24.45*60))
	{
		di = 9;
	}
	else if ((s >= 24.45*60) && (s < 28.45*60))
	{
		di = 10;
	}
	else if ((s >= 28.45*60) && (s < 32.65*60))
	{
		di = 11;
	}
	else if (s >= 32.65*60)
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