#include <bits/stdc++.h>
#define MAXN 203
#define MAXM 5003
using namespace std;
int n,m,s,t;
struct edge{
    int to,net;
    long long val;
};
edge e[MAXM<<1];
int flag[MAXN][MAXN]; int tot=1;
int head[MAXN];
void add(int u,int v,long long c){
    e[++tot].to=v;
    e[tot].val=c;
    e[tot].net=head[u];
    head[u]=tot;
    e[++tot].to=u;
    e[tot].val=0;
    e[tot].net=head[v];
    head[v]=tot;
    return;
}
int vis[MAXN],pre[MAXN];
long long dis[MAXN];
int bfs(){
    for (int i=1;i<=n;i++) vis[i]=0;
    queue <int> q;
    q.push(s); vis[s]=1; dis[s]=INT_MAX;
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int i=head[u];i;i=e[i].net){
            if (e[i].val==0) continue;
            int v=e[i].to;
            if (vis[v]) continue;
            dis[v]=min(dis[u],e[i].val);
            pre[v]=i; vis[v]=1;
            q.push(v);
            if (v==t) return 1;
        }
    }
    return 0;
}
long long ans;
void update(){
    int x=t;
    while (x!=s){
        int v=pre[x];
        e[v].val-=dis[t];
        e[v^1].val+=dis[t];
        x=e[v^1].to;
    }
    ans+=dis[t];
    return;
}
int main(){
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        if (!flag[u][v]){
            add(u,v,c);
            flag[u][v]=tot;
        } else {
            e[flag[u][v]-1].val+=c;
        }
    }
    while (bfs()){
        update();
    }
    cout<<ans<<endl;
    return 0;
}