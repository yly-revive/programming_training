#include <cstdio>

const int MAXH = 105;
const int MAXW = 10;
const int MOD = 1000000007;

const int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
int f[MAXH][MAXW];

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    f[1][1] = fib[w];
    f[1][2] = fib[w - 1];
    for (int i = 2; i <= h; i++) for (int j = 1; j <= w; j++) {
        f[i][j] = 1ll * f[i - 1][j] * fib[j] % MOD * fib[w - j + 1] % MOD;

        if (j > 1) {
            f[i][j] += 1ll * f[i - 1][j - 1] * fib[j - 1] % MOD * fib[w - j + 1] % MOD;
            f[i][j] >= MOD ? f[i][j] -= MOD : 0;
        }
        if (j < w) {
            f[i][j] += 1ll * f[i - 1][j + 1] * fib[j] % MOD * fib[w - j] % MOD;
            f[i][j] >= MOD ? f[i][j] -= MOD : 0;
        }
    }

    printf("%d\n", f[h][k]);
    
    return 0;
}
