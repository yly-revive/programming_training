#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, Q;
	string S;
	cin >> N >> S >> Q;

	int C[2000001] = {};
	rep(i, N) {
		C[i + 1] = C[i];
		if (S[i] == 'C') C[i + 1]++;
	}
	rep(i, N) {
		C[i + N + 1] = C[i + N];
	}

	rep(i, Q) {
		int K;
		cin >> K;
		ll kotae = 0;

		int M = 0;
		ll kari = 0;
		rep(j, K) {
			if (S[j] == 'M') {
				kari += C[K] - C[j + 1];
				M++;
			}
		}


		rep(j, N) {
			if (S[j] == 'D') kotae += kari;

			if (j + K < N) {
				if (S[j + K] == 'C') kari += M;
				if (S[j + K] == 'M') M++;
			}

			if (S[j] == 'M') {
				kari -= C[j + K + 1] - C[j + 1];
				M--;
			}

		}

		co(kotae);
	}

	Would you please return 0;
}
