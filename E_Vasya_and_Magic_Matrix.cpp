#include <bits/stdc++.h>
#define MAXN 1000003
#define inf 0x3f3f3f3f
#define mod 998244353
#define int long long
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m; int cnt;
struct D{
    int x; int y;
    int val;
    bool operator<(const D &B)const{
        return val<B.val;
    }
}a[MAXN];
int c[MAXN];
long long dp[MAXN];
long long dpsum[MAXN];
long long xysum[MAXN];
long long xsum[MAXN],ysum[MAXN];
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
bool ED;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[++cnt].val;
            a[cnt].x=i; a[cnt].y=j;
        }
    }
    sort(a+1,a+1+cnt);
    for (int i=1,cnow=0;i<=cnt;i++){
        if (a[i].val!=a[i-1].val) cnow=i-1;
        c[i]=cnow;
    }
    for (int i=1;i<=cnt;i++){
        long long xy=(1ll*a[i].x*a[i].x%mod+1ll*a[i].y*a[i].y%mod)%mod;
        dp[i]=qpow(c[i],mod-2)*(((dpsum[c[i]]+xy*c[i]%mod+xysum[c[i]]-xsum[c[i]]*2ll%mod*a[i].x-ysum[c[i]]*2ll%mod*a[i].y)%mod+mod)%mod)%mod;
        dpsum[i]=(dpsum[i-1]+dp[i])%mod;
        xysum[i]=(xysum[i-1]+xy)%mod;
        xsum[i]=(xsum[i-1]+a[i].x)%mod;
        ysum[i]=(ysum[i-1]+a[i].y)%mod;
    }
    int sx,sy; cin>>sx>>sy;
    for (int i=1;i<=cnt;i++){
        if (a[i].x==sx&&a[i].y==sy){
            cout<<dp[i]<<'\n';
            break;
        }
    }
    return 0;
}