#include <iostream>
#include <cstring>
 
using namespace std;
 
const int z = 1e9+7;
 
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    k--;
 
    int dp[h+1][w];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
 
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < (1 << (w - 1)); j++) {
            if (j & (j << 1)) {
                continue;
            }
            for (int k = 0; k < w; k++) {
                if (j & (1 << k)) {
                    dp[i][k+1] = (dp[i][k+1] + dp[i-1][k]) % z;
                } else if (k > 0 && j & (1 << (k - 1))) {
                    dp[i][k-1] = (dp[i][k-1] + dp[i-1][k]) % z;
                } else {
                    dp[i][k] = (dp[i][k] + dp[i-1][k]) % z;
                }
            }
        }
    }
 
    cout << dp[h][k] << endl;
 
    return 0;
}