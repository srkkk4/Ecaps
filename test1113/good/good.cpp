#include <bits/stdc++.h>
#define MAXN 5000003
#define mod 1000000007
using namespace std;
int n;
struct num{
    long long a;
    long long p;
    int id;
    bool operator<(const num &b)const{
        return a<b.a;
    }
}a[MAXN<<1];
int to[MAXN<<1];
long long sum[MAXN<<1];
int main(){
    // freopen("3.in","r",stdin);
    freopen("good.in","r",stdin);
    freopen("good.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        long long A,B,P,Q; cin>>A>>B>>P>>Q;
        a[i].a=A; a[i].p=P; a[i].id=i;
        a[i+n].a=B; a[i+n].p=Q; a[i+n].id=i+n;
    }
    sort(a+1,a+1+2*n);
    for (int i=1;i<=2*n;i++) to[a[i].id]=i;
    a[0].p=1;
    for (int i=0;i<=2*n;i++) sum[i]=(sum[i-1]+a[i].p)%mod;
    // for (int i=0;i<=2*n;i++) cout<<sum[i]<<'\n';
    long long ans=0;
    for (int i=1;i<=2*n;i++){
        int pr=(a[i].id+n-1)%(2*n)+1;
        // cout<<to[pr]<<'\n';
        if (to[pr]<i) ans=(ans+a[i].a*a[i].p%mod*(sum[i-1]-a[to[pr]].p+mod)%mod)%mod;
        else ans=(ans+a[i].a*a[i].p%mod*sum[i-1]%mod)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}