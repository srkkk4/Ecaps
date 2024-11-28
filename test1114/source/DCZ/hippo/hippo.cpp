#include <bits/stdc++.h>
#define MAXK 100003
#define mod 998244353
using namespace std;
long long n,m,k;
long long b[MAXK];
long long c[MAXK];
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main(){
    freopen("hippo.in","r",stdin);
    freopen("hippo.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++) cin>>b[i];
    for (int i=1;i<=k;i++) cin>>c[i];
    if (k==0){
        long long ans=0;
        for (int i=2;i<=m;i++){
            ans=ans*qpow(i,n*m%mod)%mod;
        }
        cout<<ans<<'\n';
    } else {
        for (int i=1;i<=k;i++) cout<<0<<'\n';
    }
    return 0;
}