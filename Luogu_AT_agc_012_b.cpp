#include <bits/stdc++.h>
#define MAXN 100003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m,q;
int c[MAXN];
int t[MAXN][13];
vector <int> e[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    cin>>q;
    for (int i=1;i<=q;i++){
        int v,d; cin>>v>>d>>c[i];
        t[v][d]=i;
    }
    for (int i=10;i>=1;i--){
        for (int u=1;u<=n;u++){
            for (int v:e[u]){
                t[v][i-1]=max(t[v][i-1],t[u][i]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        int x=0;
        for (int j=0;j<=10;j++) x=max(x,t[i][j]);
        cout<<c[x]<<'\n';
    }
    return 0;
}