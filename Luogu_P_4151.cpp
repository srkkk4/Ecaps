#include <bits/stdc++.h>
#define MAXN 50003
#define MAXP 63
#define ull unsigned long long
#define pb push_back
using namespace std;
int n,m;
struct edge{
    int v;
    ull w;
};
vector <edge> e[MAXN];
ull path;
int vis[MAXN]; int flag;
void dfs1(int u,ull res){
    vis[u]=1;
    if (u==n) {path=res; flag=1; return;}
    for (edge ed:e[u]){
        if (vis[ed.v]) continue;
        dfs1(ed.v,res^ed.w);
        if (flag) break;
    }
    return;
}
ull p[MAXP];
void insert(ull x){
    for (int i=60;i>=0;i--){
        if (!(x>>i)) continue;
        if (!p[i]){
            p[i]=x;
            break;
        }
        x=x^p[i];
    }
    return;
}
ull XOR[MAXN];
void dfs2(int u,ull res){
    vis[u]=1; XOR[u]=res;
    for (edge ed:e[u]){
        if (vis[ed.v]) insert(res^ed.w^XOR[ed.v]);
        else dfs2(ed.v,res^ed.w); 
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; ull w; cin>>u>>v>>w;
        e[u].pb({v,w});
        e[v].pb({u,w});
    }
    dfs1(1,(ull)0); memset(vis,0,sizeof vis);
    dfs2(2,(ull)0);
    ull ans=path;
    for (int i=60;i>=0;i--){
        ans=max(ans,ans^p[i]);
    }
    cout<<ans<<'\n';
    return 0;
}