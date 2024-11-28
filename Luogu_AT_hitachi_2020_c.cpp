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
vector <int> e[MAXN];
int q[2][MAXN]; int cnt[2];
void dfs(int u,int f,bool p){
    q[p][++cnt[p]]=u;
    for (int v:e[u]){
        if (v==f) continue;
        dfs(v,u,!p);
    }
    return;
}
int ans[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1,0,1);
    int x=n/3;
    if (cnt[0]>x&&cnt[1]>x){
        for (int i=1,j=1;i<=cnt[0]&&j<=n;i++,j+=3){
            ans[q[0][i]]=j;
        }
        for (int i=1,j=2;i<=cnt[1]&&j<=n;i++,j+=3){
            ans[q[1][i]]=j;
        }
        for (int i=1,j=3;i<=n;i++){
            if (!ans[i]) {ans[i]=j; j+=3;}
        }
        for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    } else if (cnt[0]<=x){
        int i=1;
        for (int j=1;i<=cnt[1]&&j<=n;i++,j+=3){
            ans[q[1][i]]=j;
        }
        for (int j=2;i<=cnt[1]&&j<=n;i++,j+=3){
            ans[q[1][i]]=j;
        }
        for (int i=1,j=3;i<=n;i++){
            if (!ans[i]) {ans[i]=j; j+=3;}
        }
        for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    } else if (cnt[1]<=x){
        int i=1;
        for (int j=1;i<=cnt[0]&&j<=n;i++,j+=3){
            ans[q[0][i]]=j;
        }
        for (int j=2;i<=cnt[0]&&j<=n;i++,j+=3){
            ans[q[0][i]]=j;
        }
        for (int i=1,j=3;i<=n;i++){
            if (!ans[i]) {ans[i]=j; j+=3;}
        }
        for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}