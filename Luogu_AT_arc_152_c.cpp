#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
int a[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n); int GCD=0;
    for (int i=1;i<=n;i++){
        GCD=__gcd(GCD,abs((a[i]-a[1])-(a[n]-a[i])));
    }
    cout<<a[n]-a[1]/GCD*GCD<<'\n';
    return 0;
}