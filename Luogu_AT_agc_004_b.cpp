#include <bits/stdc++.h>
#define MAXN 2003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,x;
int a[MAXN];
priority_queue <int,vector<int>,greater<int> > q[MAXN]; 
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long ans=LONG_LONG_MAX;
    for (int i=0;i<=n-1;i++){
        long long res=0;
        for (int j=1;j<=n;j++){
            q[j].push(a[(j-i-1+n)%n+1]);
            res+=q[j].top();
        }
        ans=min(ans,res+1ll*i*x);
    }
    cout<<ans<<'\n';
    return 0;
}