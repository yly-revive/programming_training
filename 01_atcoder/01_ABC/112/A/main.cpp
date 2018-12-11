#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	cin.tie(NULL);

	int type;
	cin >> type;

	if (type == 1)
	{
		cout << "Hello World" << endl;
	}
	else if (type == 2)
	{
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}