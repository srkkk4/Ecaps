#include <bits/stdc++.h>
#define MAXN 200003
#define MAXA 2003
#define ADD 2001
#define mod 1000000007
using namespace std;
int n;
struct P{
    int a; int b;
}p[MAXN];
long long f[MAXA*2][MAXA*2];
int mxa,mxb;
long long fac[MAXN*4];
void inFac(){
    fac[1]=1;
    for (int i=2;i<=MAXA*4-1;i++){
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
        mxa=max(mxa,p[i].a); mxb=max(mxb,p[i].b);
    }
    inFac();
    for (int i=1;i<=n;i++){
        f[-p[i].a+ADD][-p[i].b+ADD]++;
    }
    for (int i=1;i<=mxa+ADD;i++){
        for (int j=1;j<=mxb+ADD;j++){
            f[i][j]=(f[i][j]+f[i-1][j]+f[i][j-1])%mod;
        }
    }
    long long ans=0;
    for (int i=1;i<=n;i++){
        ans=(ans+f[p[i].a+ADD][p[i].b+ADD])%mod;
        ans=(ans-C(2*(p[i].a+p[i].b),2*p[i].a)+mod)%mod;
    }
    ans=(ans*qpow(2,mod-2))%mod;
    cout<<ans<<endl;
    return 0;
}