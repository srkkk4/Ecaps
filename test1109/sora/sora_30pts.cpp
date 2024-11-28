#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n;
int a[MAXN],d[MAXN];
vector <int> e[MAXN];
long long ans[MAXN];
int vis[MAXN];
int root;
int mxdep;
void dfs(int u,int dep){
    vis[u]=1;
    ans[u]+=a[root]/(1<<dep);
    if (dep<mxdep){
        for (int v:e[u]){
            if (vis[v]) continue;
            dfs(v,dep+1);
        }
    }
    vis[u]=0;
    return;
}
int main(){
    freopen("sora.in","r",stdin);
    freopen("sora.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        int j;
        for (j=0;j<=30;j++){
            if ((1<<j)>a[i]) break;
        }
        j--;
        d[i]=j;
    }
    // for (int i=1;i<=n;i++) cout<<d[i]<<" ";
    // cout<<'\n';
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (d[i]==-1) continue;
        root=i; mxdep=d[i];
        dfs(i,0);
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}