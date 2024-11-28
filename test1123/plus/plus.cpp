#include <bits/stdc++.h>
#define MAXN 1000003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
struct QUE{
    unsigned int x; unsigned int y;
}a[MAXN];
bool ED;
int main(){
    freopen("plus.in","r",stdin);
    freopen("plus.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    unsigned int ans=0;
    for (int i=0;i<32;i++){
        for (int j=1;j<=n;j++){
            ans=(ans^a[j].x)+(ans^a[j].y);
        }
    }
    for (int i=1;i<=n;i++){
        ans=(ans^a[i].x)+(ans^a[i].y);
        cout<<ans<<'\n';
    }
    return 0;
}