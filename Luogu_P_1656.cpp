#include <bits/stdc++.h>
#define MAXN 20003
using namespace std;
int n,m;
vector <int> e[MAXN];
int root,cnt;
int dfn[MAXN],low[MAXN];
struct edge{
    int u; int v;
    bool operator<(const edge &B)const{
        if (u==B.u) return v<B.v;
        else return u<B.u;
    }
}ans[MAXN];
map <int,int> mp;
int cnt2;
void dfs(int u,int fa){
    dfn[u]=low[u]=++cnt;
    int son=0;
    for (int v:e[u]){
        if (!dfn[v]){
            son++; dfs(v,u); low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]&&mp[u*1000+v]==1) ans[++cnt2]={min(u,v),max(u,v)};
        }
        else if (v!=fa) low[u]=min(low[u],dfn[v]);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        mp[u*1000+v]++; mp[v*1000+u]++;
        if (mp[u*1000+v]>=2) continue;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (dfn[i]) continue;
        root=i; dfs(i,0);
    }
    sort(ans+1,ans+1+cnt2);
    for (int i=1;i<=cnt2;i++){
        cout<<ans[i].u<<" "<<ans[i].v<<endl;
    }
    cout<<endl;
    return 0;
}