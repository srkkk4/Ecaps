#include <bits/stdc++.h>
#define MAXN 300003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int T;
int n;
int a[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        multiset <int> s;
        for (int i=1;i<=n;i++) if (a[i]) s.insert(a[i]);
        long long ans=0;
        while (s.size()>1&&*(--s.end())>=3){
            multiset <int>::iterator rbegin=s.begin(),rend=--s.end();
            int now=*rbegin,now2=*rend; s.erase(rbegin); s.erase(rend);
            if (1ll*now*3<=now2){
                ans+=now;
                now2-=1ll*now*3; now=0; 
                if (now2) s.insert(now2);
            } else {
                ans+=now2/3;
                now-=now2/3; now2%=3;
                if (now) s.insert(now);
                if (now2) s.insert(now2);
            }
        }
        multiset <int>::iterator it;
        for (it=s.begin();it!=s.end();it++){
            int now=*it;
            ans+=now/4; now%=4;
            ans+=now/2; now%=2;
            ans+=now;
        }
        cout<<ans<<'\n';
    }
    return 0;
}