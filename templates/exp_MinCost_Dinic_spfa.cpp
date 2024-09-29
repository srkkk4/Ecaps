#include <bits/stdc++.h>
#define MAXN 5000+5
#define MAXM 100000+5
using namespace std;
int n,m,s,t;
struct edge{
    int to,net;
    long long val;
    long long cst;
};
edge e[MAXM];
int tot=1;
int head[MAXN];
void add(int u,int v,long long w,long long c){
    e[++tot].to=v;
    e[tot].val=w;
    e[tot].cst=c;
    e[tot].net=head[u];
    head[u]=tot;

    e[++tot].to=u;
    e[tot].val=0;
    e[tot].cst=-c;
    e[tot].net=head[v];
    head[v]=tot;
    return;
}
int cost;
long long dep[MAXN];
int now[MAXN],vis[MAXN];
int bfs(){
    for (int i=1;i<=n;i++) dep[i]=LONG_LONG_MAX;
    queue <int> q;
    dep[s]=0;
    now[s]=head[s];
    q.push(s);
    while (!q.empty()){
        int u=q.front(); q.pop();
        vis[u]=0;
        for (int i=head[u];i;i=e[i].net){
            int v=e[i].to;
            if (e[i].val>0&&dep[u]+e[i].cst<dep[v]){
                now[v]=head[v];
                dep[v]=dep[u]+e[i].cst;
                if (!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
                // if (v==t) return 1;
            }
        }
    }
    return dep[t]!=LONG_LONG_MAX;
}
int vis2[MAXN];
int dfs(int u,long long sum){
    if (u==t || sum==0) return sum; 
    vis2[u]=1;
    long long k,res=0;
    for (int i=now[u];i;i=e[i].net){
        now[u]=i;
        int v=e[i].to;
        if (e[i].val>0&&dep[v]==dep[u]+e[i].cst&&vis2[v]==0){
            k=dfs(v,min(sum,e[i].val));
            if (k==0) dep[v]=LONG_LONG_MAX;
            e[i].val-=k;
            e[i^1].val+=k;
            res+=k;
            sum-=k;
            cost+=k*e[i].cst;
        }
        if (!sum) break;
    }
    vis2[u]=0;
    return res;
}
void build(){
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++){
        int u,v,w,c;
        scanf("%d %d %d %d",&u,&v,&w,&c);
        add(u,v,w,c);
    }
    return;
}
int main(){
    build();
    long long ans=0;
    while (bfs()){
        ans+=dfs(s,LONG_LONG_MAX);
    }
    cout<<ans<<" "<<cost<<endl;
    return 0;
}
/*
5 7 0 4
0 1 1 11
0 2 7 11
0 3 5 11
1 3 1000 2 
1 4 1000 0
2 4 1000 0
3 4 1000 0

13 143
 */