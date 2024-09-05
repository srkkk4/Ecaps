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
int dep[MAXN],now[MAXN];
int bfs(){
    for (int i=1;i<=n;i++) dep[i]=INT_MAX;
    queue <int> q;
    dep[s]=0;
    now[s]=head[s];
    q.push(s);
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int i=head[u];i;i=e[i].net){
            int v=e[i].to;
            if (e[i].val>0&&dep[v]==INT_MAX){
                now[v]=head[v];
                dep[v]=dep[u]+1;
                q.push(v);
                if (v==t) return 1;
            }
        }
    }
    return 0;
}
int dfs(int u,long long sum){
    if (u==t) return sum;
    long long k,res=0;
    for (int i=now[u];i;i=e[i].net){
        now[u]=i;
        int v=e[i].to;
        if (e[i].val>0&&dep[v]==dep[u]+1){
            k=dfs(v,min(sum,e[i].val));
            if (k==0) dep[v]=INT_MAX;
            e[i].val-=k;
            e[i^1].val+=k;
            res+=k;
            sum-=k;
        }
        if (!sum) break;
    }
    return res;
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
    long long ans=0;
    while (bfs()){
        ans+=dfs(s,INT_MAX);
    }
    cout<<ans<<endl;
    return 0;
}