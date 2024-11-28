#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n;
int a[MAXN];
vector <int> e[MAXN];
int root=1;
long long g[MAXN][34];
long long h[MAXN][34];
int fa[MAXN];
void dfs(int u,int f){
    fa[u]=f;
    for (int v:e[u]){
        if (v==f) continue;
        dfs(v,u);
    }
    for (int i=0;i<=30;i++){
        g[u][i]=a[u]>>i;
        for (int v:e[u]){
            if (v==f) continue;
            g[u][i]+=g[v][i+1];
        }
    }
    return;
}
void dfs2(int u,int f){
    for (int v:e[u]){
        if (v==f) continue;
        for (int i=0;i<=30;i++){
            h[v][i]=g[v][i]+h[u][i+1]-g[v][i+2];
        }
        dfs2(v,u);
    }
    return;
}
int main(){
    freopen("sora.in","r",stdin);
    freopen("sora.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(root,0);
    for (int i=0;i<=30;i++) h[root][i]=g[root][i];
    dfs2(root,0);
    for (int i=1;i<=n;i++) cout<<h[i][0]<<" ";
    cout<<'\n';
    return 0;
}