#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m;
vector <int> e[MAXN];
int dfn[MAXN],low[MAXN],size[MAXN];
int root=1,cnt;
int son[MAXN],cnt2;
long long ans[MAXN];
void dfs(int u){
    dfn[u]=low[u]=++cnt;
    size[u]=1;
    ans[u]=n-1;
    cnt2=0;
    int sum=0;
    for (int v:e[u]){
        if (!dfn[v]){
            dfs(v); low[u]=min(low[u],low[v]); size[u]+=size[v];
            if (low[v]>=dfn[u]){
                ans[u]+=1ll*size[v]*(n-size[v]);
                sum+=size[v];
            }
        } else {
            low[u]=min(low[u],dfn[v]);
        }
    }
    ans[u]+=1ll*(n-sum-1)*(sum+1);
    for (int i=1;i<=cnt2;i++) son[i]=0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(root);
    // for (int i=1;i<=n;i++) cout<<size[i]<<" ";
    // cout<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}