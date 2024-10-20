#include <bits/stdc++.h>
#define MAXN 2003
#define mod 1000000007
using namespace std;
int n;
char s[MAXN];
int a[27];
int is_p,p;
long long fac[MAXN];
void init(){
    fac[0]=fac[1]=1;
    for (int i=2;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    return;
}
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
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>s[i]; a[s[i]-'a'+1]++;}
    init();
    for (int i=1;i<=26;i++) if (a[i]%2) {is_p++; p=a[i]; a[i]--;}
    if (is_p>=2) {cout<<fac[n]<<endl; return 0;}
    long long res=fac[n/2];
    for (int i=1;i<=26;i++){
        if (!a[i]) continue;
        res=res*qpow(fac[a[i]/2],mod-2)%mod*fac[a[i]]%mod;
    }
    if (is_p==1) res=res*p%mod;
    long long ans=(fac[n]-res+mod)%mod;
    cout<<ans<<endl;
    return 0;
}