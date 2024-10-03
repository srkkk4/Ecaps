#include <bits/stdc++.h>
#define MAXN 2003
#define mod 1000000007
using namespace std;
int n,m,sum;
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
long long fac[MAXN*MAXN+MAXN+3];
void inFac(){
    fac[1]=1;
    for (int i=2;i<=MAXN*MAXN+MAXN+1;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
    }
    inFac();
    long long ans=qpow(fac[n+sum],mod-2);
    for (long long i=m+n;i>=m-sum+1;i--){
        ans=(ans*i)%mod;
    }
    cout<<ans<<endl;
    return 0;
}