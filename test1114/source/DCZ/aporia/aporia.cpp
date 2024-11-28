#include <bits/stdc++.h>
#define MAXN 103
#define mod 998244353
using namespace std;
int n,k;
long long ans;
long long fac[MAXN];
void init() {fac[0]=fac[1]=1; for (int i=2;i<=MAXN-2;i++) fac[i]=fac[i-1]*i%mod; return;}
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
long long LCM(long long x,long long y){
    return x/__gcd(x,y)*y;
}
void dfs(int u,int sum,long long tim,int keep,long long lcm){
    for (int v=max(1,u);2*v<=n-sum;v++){
        if (v>u) dfs(v,sum+v,1ll*tim*v%mod*fac[keep]%mod,(v==u)?keep+1:1,LCM(lcm,v));
        else dfs(v,sum+v,1ll*tim*v%mod,(v==u)?keep+1:1,LCM(lcm,v));
    }
    if (n-sum==u) keep++;
    tim=tim*fac[keep]%mod;
    tim=tim*(n-sum)%mod;
    ans=(ans+qpow(LCM(lcm,n-sum),k)*fac[n]%mod*qpow(tim,mod-2)%mod)%mod;
    return;
}
int main(){
    // freopen("aporia.in","r",stdin);
    // freopen("aporia.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    init();
    if (k==0) {cout<<fac[n]<<'\n'; return 0;}
    dfs(0,0,1ll,0,1ll);
    cout<<ans<<'\n';
    return 0;
}