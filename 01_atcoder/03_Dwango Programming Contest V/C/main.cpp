#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

#include <string>
// TLE

struct A{
	int d_i;
	int m_i;
	int s_i;
	int d_m;
	int m_s;
};


int main(int argc, char **argv)
{
	int N, Q;
	string S;

	cin.tie(NULL);

	cin >> N;
	//getline(cin, S);
	cin >> S;

	//cout << "3333" << endl;
	cin >> Q;

	int k[Q];

	std::vector<int> v;
	
	for (int i = 0; i < Q; i++)
	{
		cin >> k[i];
		v.push_back(k[i]);
	}

	std::vector<int> v_d, v_m, v_c;
	//std::vector<A> v_d;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'D')
		{	/*
			A tmp;
			tmp.d_i = i;
			tmp.d_m = 0;
			tmp.m_s = 0;
			v_d.push_back(tmp);
			*/
			v_d.push_back(i);
		}
		else if (S[i] == 'M')
		{
			/*
			int len = v_d.size() - 1;
			if (tmp[len].d_m == 0)
			{
				tmp[len].d_m = 1;
				tmp[len].m_i = i;
			}
			*/
			v_m.push_back(i);
		}
		else if (S[i] == 'C')
		{
			v_c.push_back(i);
		}
	}

	//cout << v_d.size() << " " << v_m.size() << " " << v_c.size() << endl;

	for (int i = 0; i < Q; i++)
	{	
		int tmp_q = 0;
		for (int j = 0; j < v_d.size(); j++)
		{
			int tmp_d = v_d[j];
			int max = tmp_d + k[i];

			for (int n = 0; n < v_m.size(); n++)
			{
				int tmp_m = v_m[n];
				if (tmp_m <= tmp_d)
				{
					continue;
				}

				if (tmp_m >= max)
				{
					break;
				}

				for (int m = 0; m < v_c.size(); m++)
				{
					int tmp_c = v_c[m];
					if(tmp_c <= tmp_m)
					{
						continue;
					}
					if (tmp_c >= max)
					{
						break;
					}
					tmp_q++;
				}	
			}
		}
		cout << tmp_q << endl;
	}

	return 0;

}