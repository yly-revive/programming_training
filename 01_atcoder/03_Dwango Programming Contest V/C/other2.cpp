#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
const ll MOD=1e9+7;

/*

*/

int main(void){
	ll mdp[1000010],cdp[1000010],p[1000010];//累積和
	mdp[0]=0;
	cdp[0]=0;
	p[0]=0;
	int n,q,x[110];
	vector<int>d,m,c;
	string s;
	cin>>n;
	cin>>s;
	cin>>q;
	rep(i,q)cin>>x[i];
	s=" "+s;
	reg(i,1,n){
		mdp[i]=mdp[i-1];
		cdp[i]=cdp[i-1];
		p[i]=p[i-1];
		if(s[i]=='D'){
			d.push_back(i);
		}else if(s[i]=='M'){
			m.push_back(i);
			mdp[i]++;
		}else if(s[i]=='C'){
			c.push_back(i);
			cdp[i]++;
			p[i]+=mdp[i];
		}
	}
	// cout<<"d ";
	// rep(i,d.size())cout<<d[i]<<" ";
	// cout<<endl;
	// cout<<"m ";
	// rep(i,m.size())cout<<m[i]<<" ";
	// cout<<endl;
	// cout<<"c ";
	// rep(i,c.size())cout<<c[i]<<" ";
	// cout<<endl;
	//DMC
	rep(i,q){
		ll ans=0;
		rep(k,d.size()){
			ans+=p[min(d[k]+x[i]-1,n)] - p[d[k]] - (mdp[d[k]]) * (cdp[min(d[k]+x[i]-1,n)]-cdp[d[k]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
