#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
int n,m,s;
vector <int> e[MAXN];
int vis[MAXN];
int dep[MAXN],fa[MAXN][20];
void getDeep(int u,int f){
    vis[u]=1;
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for (int i=1;(1<<i)<=dep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for (int v:e[u]){
        if (vis[v]) continue;
        getDeep(v,u);
    }
    vis[u]=0;
    return;
}
int LCA(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int cha=dep[u]-dep[v];int logcha=log(cha)/log(2)+0.5;
    for (int i=0;i<=logcha;i++){
        if (cha&(1<<i)) u=fa[u][i];
    }
    if (u==v) return u;
    int logdep=log(dep[u])/log(2)+0.5;
    for (int i=logdep;i>=0;i--){
        // if (dep[fa[u][i]]<=0) continue;
        if (fa[u][i]==fa[v][i]) continue;
        u=fa[u][i]; v=fa[v][i];
    }
    return fa[u][0];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    getDeep(s,0);
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }
    return 0;
}