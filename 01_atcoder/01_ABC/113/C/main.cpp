#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

class Node
{
public:
	int p;
	int y;
	int index;
	int no;

	Node(){};
	bool operator <(const Node & nodeObj) const
	{
		//return (p <= nodeObj.p) && (y < nodeObj.y) ;
		if (p < nodeObj.p)
		{
			return true;
		}
		else if ( p == nodeObj.p )
		{
			if (y < nodeObj.y)
			{
				return true;
			}
		}
		return false;
	}
};

bool comp1(const Node& a, const Node& b) 
{
	return (a.p <= b.p) && (a.y <= b.y);
}

bool comp(const Node& a, const Node& b) {
  
  return a.index < b.index;
}

int main(int argc, char **argv)
{
	int N, M;
	cin >> N >> M;

	std::vector<Node> city;

	for (int i = 0; i < M; i++)
	{
		Node tmp;
		cin >> tmp.p >> tmp.y;
		tmp.index = i;
		city.push_back(tmp);
	}

	sort(city.begin(), city.end());
	//sort(city.begin(), city.end(), comp1);
	/*
	for(int i = 0; i < M; i++)
	{
		cout << city[i].index << " ";
	}
	cout << endl;
	*/
	int pre_p = 0, cnt_y = 0;

	for (int i = 0; i < M; i++)
	{
		if (pre_p != city[i].p)
		{
			cnt_y = 1;
			pre_p = city[i].p;
		}
		else
		{
			cnt_y++;
		}
		
		city[i].no = cnt_y;
	}


	sort(city.begin(), city.end(), comp);

	for (int i = 0; i < M; i++)
	{
		printf("%06d%06d", city[i].p, city[i].no);
		if (i < M - 1)
		{
			printf("\n");
		}
	}

	return 0;

}