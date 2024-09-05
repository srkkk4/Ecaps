#include <bits/stdc++.h>
#define MAXN 5000+5
#define MAXM 100000+5
using namespace std;
int m,n,s,t;
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
    for (int i=s;i<=t;i++) dep[i]=LONG_LONG_MAX;
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
int a[103],b[103],c[103][103];
void IN(){
    cin>>m>>n;
    for (int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }
    return;
}
void build(int tpye){
    memset(e,0,sizeof e); tot=1;
    memset(head,0,sizeof head);
    memset(now,0,sizeof now);
    for (int i=1;i<=m;i++){
        add(0,i,a[i],0);
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            add(i,m+j,LONG_LONG_MAX,tpye?-c[i][j]:c[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        add(m+i,m+n+1,b[i],0);
    }
    s=0; t=m+n+1;
    return;
}
int main(){
    IN();
    build(0);
    long long ans=0;
    while (bfs()){
        ans+=dfs(s,LONG_LONG_MAX);
    }
    cout<<cost<<endl;
    build(1);
    ans=0; cost=0;
    while (bfs()){
        ans+=dfs(s,LONG_LONG_MAX);
    }
    cout<<-cost<<endl;
    return 0;
}