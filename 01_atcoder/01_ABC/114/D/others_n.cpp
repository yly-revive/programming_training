#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p = i;
        for (int j = 2; j * j <= p; ++j) {
            while (p % j == 0) {
                ++cnt[j];
                p /= j;
            }
        }
        if (p > 1) {
            ++cnt[p];
        }
    }
    vector<int> dp(76);
    dp[1] = 1;
    for (int i = 0; i <= n; ++i) {
        vector<int> nex(76);
        for (int j = 0; j <= cnt[i]; ++j) {
            for (int k = 1; (j + 1) * k < 76; ++k) {
                nex[(j + 1) * k] += dp[k];
            }
        }
        dp = nex;
    }
    cout  << dp[75] << "\n";
    return 0;
}
