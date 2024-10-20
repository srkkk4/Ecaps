#include <bits/stdc++.h>
#define MAXN 10003
using namespace std;
int n,m;
vector <int> e[MAXN];
int inx;
int dfn[MAXN],low[MAXN];
int sta[MAXN],cnt;
int color;
int vis[MAXN],col[MAXN];
void tarjan(int u){
    dfn[u]=low[u]=++inx;
    sta[++cnt]=u; vis[u]=1;
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
            top=sta[cnt]; cnt--;
            vis[top]=0;
            col[top]=color;
        }while (top!=u);
    }
    return;
}
int vis2[MAXN];
int q2[MAXN],cnt2;
void dfs(int u,int COL){
    vis2[u]=1;
    q2[++cnt2]=u;
    for (int v:e[u]){
        if (vis2[v]||col[v]!=COL) continue;
        dfs(v,COL);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
    }
    for (int i=1;i<=n;i++){
        if (dfn[i]) continue;
        tarjan(i);
    }
    cout<<color<<endl;
    for (int i=1;i<=n;i++){
        if (vis2[i]) continue;
        cnt2=0;
        dfs(i,col[i]);
        sort(q2+1,q2+1+cnt2);
        for (int j=1;j<=cnt2;j++) cout<<q2[j]<<" ";
        cout<<endl;
    }
    return 0;
}