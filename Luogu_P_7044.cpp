#include <bits/stdc++.h>
#define mod 998244353
#define MAXN 1000003
using namespace std;
int n,k;
char S[MAXN];
long long fl[MAXN],fr[MAXN],qfl[MAXN];
long long fac[MAXN*2];
void inFac(){
    fac[0]=fac[1]=1;
    for (int i=2;i<=MAXN*2-1;i++){
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
void sub_slove(){
    int rem=0,ans=0;
    for (int i=1;i<=n;i++){
        if (S[i]=='(') rem++;
        else {
            if (rem) rem--;
            else ans++;
        }
    }
    cout<<rem+ans<<endl;
}
int last[MAXN],rem=0;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>S[i];
    if (k==0) {sub_slove(); return 0;}
    inFac();
    for (int r=1;r<=n;r++) fr[r]=C(n-r+k-1,k-1);
    for (int l=1;l<=n;l++) fl[l]=C(l-1+k-1,k-1);
    for (int i=1;i<=n;i++) qfl[i]=(qfl[i-1]+fl[i])%mod;
    long long ans=0;
    long long sum=0; 
    for (int r=1;r<=n;r++){
        if (S[r]=='(') {sum=(sum+qfl[r])%mod; last[++rem]=r;}
        else {
            if (rem){
                int t=last[rem--];
                sum=(sum-qfl[t]+mod)%mod;
                sum=(sum+qfl[r]-qfl[t]+mod)%mod; //qfl[r]在mod之后可能比qfl[t]小，千万别忘记加一个mod
            } else {
                sum=(sum+qfl[r])%mod;
            }
        }
        ans=(ans+fr[r]*sum)%mod;
    }
    cout<<ans<<endl;
    return 0;
}