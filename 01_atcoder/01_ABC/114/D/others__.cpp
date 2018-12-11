#include <bits/stdc++.h>

using namespace std;

int main() {
	int p[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
	int n;
	cin >> n;
	int a[20] = {};
	for (int i = 2; i <= n; i++) {
		int j = 0, k = i;
		while (k > 1 && j < 15) {
			if (k%p[j]) j++;
			else {
				k /= p[j];
				a[j]++;
			}
		}
	}
	int x = upper_bound(a, a + 15, 2, greater<int>()) - a;
	int y = upper_bound(a, a + 15, 4, greater<int>()) - a;
	int z = upper_bound(a, a + 15, 14, greater<int>()) - a;
	int u = upper_bound(a, a + 15, 24, greater<int>()) - a;
	int v = upper_bound(a, a + 15, 74, greater<int>()) - a;
	cout << v + u * (x - 1) + z * (y - 1) + y * (y - 1) / 2 * (x - 2) << endl;
	return 0;
}
