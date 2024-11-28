#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;
int n,m;
vector <int> e[MAXN];
int dis[MAXN][MAXN];
int vis[MAXN];
struct D{
    int u;
    int Dis;
    bool operator <(const D &B)const{
        return Dis>B.Dis;
    }
};
void dijk(int s){
    memset(dis[s],0x3f,sizeof dis[s]);
    memset(vis,0,sizeof vis);
    priority_queue <D> q;
    dis[s][s]=0;
    q.push({s,0});
    while (!q.empty()){
        D now=q.top(); q.pop();
        vis[now.u]=1;
        for (int v:e[now.u]){
            if (vis[v]) continue;
            if (now.Dis+1<dis[s][v]){
                dis[s][v]=now.Dis+1;
                q.push({v,dis[s][v]});
            }
        }
    }
    return;
}
int chs[MAXN];
int U;
long long ans=0;
void dfs(int u){
    if (u==n){
        int mn=INT_MAX;
        int flag=0;
        for (int i=1;i<=n;i++){
            if (!chs[i]) continue;
            flag=1;
            mn=min(mn,dis[U][i]);
        }
        if (flag) ans+=mn;
        return;
    }
    dfs(u+1);
    chs[u+1]=1;
    dfs(u+1);
    chs[u+1]=0;
    return;
}
int main(){
    freopen("data.in","r",stdin);
    freopen("pai.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        dijk(i);
    }
    for (int i=1;i<=n;i++){
        U=i; dfs(0);
    }
    cout<<ans<<'\n';
    return 0;
}