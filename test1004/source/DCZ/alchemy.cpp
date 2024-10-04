#include <bits/stdc++.h>
#define mod 998244353
#define MAXK 23
using namespace std;
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
int n;
string a,b;
int k;
int w[MAXK];
int main(){
    freopen("alchemy.in","r",stdin);
    freopen("alchemy.ans","w",stdout);
    cin>>n;
    cin>>a>>b;
    cin>>k;
    for (int i=1;i<=k;i++) cin>>w[i];
    if (k==0){
        int l=a.length();
        cout<<(((n-l+1)*qpow(52,n-l))%mod*qpow(qpow(52,n),mod-2))%mod;
    } else {
        cout<<0<<endl;
    }
    // cout<<(qpow(qpow(52,5),mod-2)*52)%mod<<endl;
    return 0;
}