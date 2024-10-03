#include <bits/stdc++.h>
#define MAXN 200003
#define mod 1000000007
using namespace std;
int n;
struct P{
    int a;int b;
}p[MAXN];
long long fac[MAXN*4];
void inFac(){
    fac[1]=1;
    for (int i=2;i<=MAXN*4-1;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    return;
}
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
long long C(int M,int N){
    return (fac[M]*qpow((fac[N]*fac[M-N])%mod,mod-2))%mod;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].b;
    }
    inFac();
    long long ans=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ans=(ans+C(p[i].a+p[i].b+p[j].a+p[j].b,p[i].a+p[j].a))%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}