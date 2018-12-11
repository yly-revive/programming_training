#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(x,y) memset(x,y,sizeof(x))
#define in(a) a=read()
#define out(a) printf("%d\n",a)
inline ll read(){
	char c=getchar();ll f=1,x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define mod 1000000007
#define maxn 1010
#define inf (1<<30)
ll a[maxn*maxn],b[maxn*maxn],v[maxn];
int main(){
	int n,m;
	in(n);in(m);
	FOR(i,1,n)in(v[i]);
	int num=0;
	FOR(i,1,n){
		ll s=0;
		FOR(j,i,n){
			s+=v[j];
			a[++num]=s;
		}
	}
	ll ans=0;
	FORD(i,50,0){
		int c=0;
		FOR(j,1,num)if(a[j]&(1ll<<i))b[++c]=a[j];
		if(c>=m){
			FOR(j,1,c)a[j]=b[j];
			num=c;
			ans+=(1ll<<i);
		}
	}
	printf("%lld\n",ans);
}
