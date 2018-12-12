#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
 
int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
 
    vector<vector<long long>> dp(n + 1, vector<long long>(n * a + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = n; j > 0; --j)
            for (int k = x[i]; k < n * a + 1; ++k)
                dp[j][k] += dp[j - 1][k - x[i]];
 
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp[i][i * a];
 
    cout << ans << "\n";
    return 0;
}