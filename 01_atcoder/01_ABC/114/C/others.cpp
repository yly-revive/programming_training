#include <bits/stdc++.h>
using namespace std;

int n, dig = 1;

int dfs(int depth, int max, long long now) {
  if (depth == max) {
    if (now > n) return 0;
    bool c[3] = {};
    for (int i= 0; i < max; i++) {
      if (now % 10 == 3) c[0] = true;
      if (now % 10 == 5) c[1] = true;
      if (now % 10 == 7) c[2] = true;
      now /= 10;
    }
    if (c[0] && c[1] && c[2]) return 1;
    else return 0;
  }
  return dfs(depth + 1, max, now * 10 + 3) + dfs(depth + 1, max, now * 10 + 5) + dfs(depth + 1, max, now * 10 + 7);
}

int main(void) {
  int ans = 0;
  cin >> n;
  int div = 10;
  while (n / div) {
    dig++;
    div *= 10;
  }
  for (int i = 3; i <= dig; i++) {
    ans += dfs(1, i, 3) + dfs(1, i, 5) + dfs(1, i, 7);
  }
  cout << ans << endl;
}
