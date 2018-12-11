#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
typedef long long int ll;

int main(int argc, char **argv)
{
	int N;
	cin >> N;

	//int A[N];
	std::vector<int> A_v;
	for (int i = 0; i < N; i++)
	{
		//cin >> A[i];
		int tmp;
		cin >> tmp;
		A_v.push_back(tmp);
	}

	sort(A_v.begin(), A_v.end());

	/*
	cout << "output sorted A_v" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << A_v[i] << " ";
	}

	cout << endl;
	*/
	
	int first_index = (N - 1) / 2;

	ll max = 0;

	/*
	std::vector<int> v_l(A_v.begin(), A_v.begin() + first_index );

	std::vector<int> v_h(A_v.begin() + first_index +1, A_v.end());

	v_l.insert(0, A_v[first_index]);
	int l_size = v_l.size();
	int h_size = v_h.size();

	int i = h_size-1;
	int j = 0;
	for (; i>=0, j<l_size; i--, j++)
	{
		max = v_h[i] - 
	}
	*/
	std::vector<int> v_n;
	v_n.push_back(A_v[first_index]);
	int size = A_v.size();
	if (A_v[first_index] != A_v[size-1])
	{
		for (int i = 0; i < first_index; i++)
		{
			v_n.push_back(A_v[size - 1 - i]);
			v_n.push_back(A_v[i]);
		}
	}
	else
	{
		for (int i = 0; i < first_index; i++)
		{
			v_n.push_back(A_v[i]);
			v_n.push_back(A_v[size - 1 - i]);
		}
	}
	

	if (N % 2 == 0)
	{
		v_n.push_back(A_v[first_index + 1]);
	}

	/*
	cout << "output sorted v_v" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << v_n[i] << " ";
	}
	cout << endl;
	*/

	for (int i = 1; i < N; i++)
	{
		max += abs(v_n[i] - v_n[i-1]);
	}

	cout << max;

	return 0;
	
}

