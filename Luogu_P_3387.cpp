#include <bits/stdc++.h>
#define MAXN 10003
#define MAXM 100003
using namespace std;
int n,m;
int a[MAXN];
vector <int> e[MAXN];
struct edge{
    int u;
    int v;
}ed[MAXM]; int cnted;
int inx;
int dfn[MAXN],low[MAXN];
int vis[MAXN],col[MAXN];
int q[MAXN],cnt;
int color;
void tarjan(int u){
    dfn[u]=low[u]=++inx;
    q[++cnt]=u; vis[u]=1;
    for (int v:e[u]){
        if (!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        } else if (vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u]){
        color++; int top;
        do{
            top=q[cnt]; cnt--;
            vis[top]=0;
            col[top]=color;
        }while (top!=u);
    }
    return;
}
int val[MAXN];
vector <int> e2[MAXN];
int rd[MAXN];
int sta[MAXN],cnt2;
int topoA[MAXN],cnt3;
int dp[MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        ed[++cnted].u=u; ed[cnted].v=v;
    }
    for (int i=1;i<=n;i++){
        if (dfn[i]) continue;
        tarjan(i);
    }
    for (int i=1;i<=n;i++) val[col[i]]+=a[i];
    for (int i=1;i<=m;i++){
        if (col[ed[i].u]!=col[ed[i].v]) e2[col[ed[i].u]].push_back(col[ed[i].v]);
    }
    for (int u=1;u<=n;u++){
        for (int v:e2[u]) rd[v]++;
    }
    for (int i=1;i<=n;i++){
        if (!rd[i]){
            sta[++cnt2]=i;
            dp[i]=val[i];
        }
    }
    for (int i=1;i<=n;i++){
        int u=sta[cnt2]; cnt2--;
        topoA[++cnt3]=u;
        for (int v:e2[u]){
            dp[v]=max(dp[v],dp[u]+val[v]);
            rd[v]--;
            if (!rd[v]) sta[++cnt2]=v;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}