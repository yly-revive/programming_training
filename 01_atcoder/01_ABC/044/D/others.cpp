#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <bitset>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

ll calc(ll n, ll b){
  if(n < b)return n;
  else return calc((ll)(n / b), b) + (n % b);
}

int main(int argc, char const* argv[])
{
  ll n, s;
  cin >> n >> s;
  if(n == s){
    cout << n + 1 << endl;
    return 0;
  }
  for(ll i = 2; i * i <= n; i++){
    if(s == calc(n, i)){
      cout << i << endl;
      return 0;
    }
  }
  ll res = linf;
  for(ll p = 1; p * p <= n; p++){
    ll q = s - p;
    if((n - q) % p != 0)continue;
    ll b = (n - q) / p;
    if(b > 1 && s == calc(n, b)){
      res = min(res, b);
    }
  }
  if(res == linf)cout << - 1 << endl;
  else cout << res << endl;
	return 0;
}
