#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

typedef long long ll ;
#define rep (i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/


/*
// failed for large value with error code 135 and <Illegal instruction: 4> on mac
class Point
{
public:
	ll x;
	ll y;
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ll H, W;
	int N;
	
	cin >> H >> W >> N;

	Point m[N];

	for (int i = 0; i < N; i++)
	{
		cin >> m[i].y >> m[i].x;
	}

	ll d[H-2][W-2];
	memset(d, 0, sizeof(ll) *(H-2)*(W-2));

	for (int i = 0; i < N; i++)
	{
		
		for (ll j = m[i].y - 3; j <= m[i].y - 1; j++)
		{
			
			if ((j < 0) || (j >= H-2))
			{
				continue;
			}
			

			for (ll k = m[i].x - 3; k <= m[i].x - 1; k++)
			{
				
				if ((k < 0) || (k >= W-2))
				{
					continue;
				}
				
				d[j][k]++;
				
			}
		}
		
	}

	ll cnt[10];
	memset(cnt, 0, sizeof(ll) * 10);

	for (int i = 0; i < 10; i++)
	{
		for (ll j = 0; j < H-2; j++)
		{
			for (ll k = 0; k < W-2; k++)
			{
				if (d[j][k] == i)
				{
					cnt[i]++;
				}
			}
		}
		cout << cnt[i] << endl;
	}

	
	return 0;
}
*/


// others
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int MAXN = 100010;
ll h, w, n;
ll a[MAXN], b[MAXN];
ll _count[10];
map<P, int> m;
void solve() {
  for (int i=0;i<n;i++) {
    for (int x=0;x<=2;x++) {
      for (int y=0;y<=2;y++) {
        int nx = b[i] - x;
        int ny = a[i] - y;
        if (nx >=0 && nx < w-2 && ny >= 0 && ny < h-2) {
          m[P(nx, ny)]++;
        }
      }
    }
  }
  ll tot = 0;
  for (auto const& x : m) {
    _count[x.second]++;
    tot++;
  }
  _count[0] = (h-2) * (w-2) - tot;
  for (int i=0;i<10;i++) {
    cout << _count[i] << endl;
  }
}

int main() {
  cin >> h >> w >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  solve();
}
