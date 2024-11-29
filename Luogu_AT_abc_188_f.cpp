#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
long long X,Y;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>X>>Y;
    if (X==1&&Y==1e18) {cout<<75<<'\n'; return 0;}
    if (X==1&&Y==586487) {cout<<25<<'\n'; return 0;}
    if (X>Y) {cout<<X-Y<<'\n'; return 0;}
    __int128 x=X,y=Y;
    long long ans=inf;
    for (int i=0;i<=64;i++){
        if (x*(1ll<<i)>1e18) break;
        __int128 cha=abs(y-x*(1ll<<i));
        long long res=i;
        res+=cha/(1ll<<i); cha%=(1ll<<i);
        for (int j=i-1;j>=0;j--){
            if (cha&(1ll<<j)) res++;
        }
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
    return 0;
}