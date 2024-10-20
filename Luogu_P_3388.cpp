#include <bits/stdc++.h>
#define MAXN 20003
using namespace std;
int n,m;
vector <int> e[MAXN];
int root,cnt;
int dfn[MAXN],low[MAXN];
int ans[MAXN],cnt2;
void dfs(int u){
    dfn[u]=low[u]=++cnt;
    int son=0;
    for (int v:e[u]){
        if (!dfn[v]){
            son++; dfs(v); low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]&&u!=root) ans[++cnt2]=u;
        }
        else low[u]=min(low[u],dfn[v]);
    }
    if (u==root&&son>=2) ans[++cnt2]=u;
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (dfn[i]) continue;
        root=i; dfs(i);
    }
    sort(ans+1,ans+1+cnt2);
    cnt2=unique(ans+1,ans+cnt2+1)-ans-1;
    cout<<cnt2<<endl;
    for (int i=1;i<=cnt2;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}