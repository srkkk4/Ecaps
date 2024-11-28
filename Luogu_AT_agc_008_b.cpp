#include <bits/stdc++.h>
#define MAXN 100003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,k;
int a[MAXN];
long long mp[MAXN],ms[MAXN],sum[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long mx=0;
    for (int i=1;i<=n;i++){
        mp[i]=(mx+=(a[i]>0?a[i]:0));
    }
    mx=0;
    for (int i=n;i>=1;i--){
        ms[i]=(mx+=(a[i]>0?a[i]:0));
    }
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    long long ans=0;
    for (int i=1,j=k;i<=n-k+1;i++,j++){
        ans=max(ans,max(0ll,sum[j]-sum[i-1])+mp[i-1]+ms[j+1]);
    }
    cout<<ans<<'\n';
    return 0;
}