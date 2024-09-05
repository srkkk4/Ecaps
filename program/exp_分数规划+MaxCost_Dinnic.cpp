#include <bits/stdc++.h>
#define MAXN 203
using namespace std;
int n,s,t;
int a[MAXN][MAXN],b[MAXN][MAXN];
struct edge{
    int to,net;
    long long val;
    double cst;
};
edge e[MAXN*MAXN];
int tot=1;
int head[MAXN];
void add(int u,int v,long long w,double c){
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
double cost;
double dep[MAXN];
int now[MAXN],vis[MAXN];
int bfs(){
    for (int i=s;i<=t;i++) dep[i]=1e9*1.0;
    queue <int> q;
    dep[s]=0.0;
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
    return dep[t]!=1e9*1.0;
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
            if (k==0) dep[v]=1e9*1.0;
            e[i].val-=k;
            e[i^1].val+=k;
            res+=k;
            sum-=k;
            cost+=1.0*k*e[i].cst;
        }
        if (!sum) break;
    }
    vis2[u]=0;
    return res;
}
void build(double x){
    cost=0; tot=1;
    memset(e,0,sizeof e);
    memset(head,0,sizeof head);
    memset(now,0,sizeof now);
    for (int i=1;i<=n;i++){
        add(0,i,1,0);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            add(i,n+j,1,-(1.0*a[i][j]-1.0*x*b[i][j]));
        }
    }
    for (int i=1;i<=n;i++){
        add(n+i,2*n+1,1,0);
    }
    s=0; t=2*n+1;
    return;
}
bool check(double x){
    build(x);
    long long ans=0;
    while (bfs()){
        ans+=dfs(s,1e9);
    }
    return -cost>=0.0;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    double l=0,r=1e6,mid;
    while (l+1e-8<r){
        mid=(l+r)/2.0;
        if (check(mid)) l=mid;
        else r=mid;
    }
    printf("%0.6lf\n",l);
    return 0;
}