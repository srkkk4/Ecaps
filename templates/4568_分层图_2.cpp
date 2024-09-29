#include <bits/stdc++.h>
#define MAXN 10003
using namespace std;
int n,m,k;
int s,t;
struct edge{
    int v;
    int val;
};
struct node{
    int dot,dis;
    bool operator<(const node &b)const {
        return dis>b.dis;
    }
};
vector <edge> e[MAXN*13],e2[MAXN*13]; 
int dis[MAXN*13]; int vis[MAXN*13];
void dijk(int s){
    memset(dis,0x3f,sizeof dis);
    priority_queue <node> q;
    q.push({s,0}); dis[s]=0;
    while (!q.empty()){
        node now=q.top(); q.pop();
        int u=now.dot;
        vis[u]=1;
        for (auto ed:e2[u]){
            if (vis[ed.v]) continue;
            if (dis[u]+ed.val<dis[ed.v]){
                dis[ed.v]=dis[u]+ed.val;
                q.push({ed.v,dis[ed.v]});
            }
        }
    }
    return;
}
int main(){
    cin>>n>>m>>k;
    cin>>s>>t;
    s++; t++;
    for (int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a++; b++;
        e[a].push_back((edge){b,c});
        e[b].push_back((edge){a,c});
        e2[a].push_back((edge){b,c});
        e2[b].push_back((edge){a,c});
    }
    for (int u=1;u<=n;u++){
        for (int i=0;i<=k-1;i++){
            for (auto v:e[u]){
                e2[(i+1)*n+u].push_back({(i+1)*n+v.v,v.val});
                e2[i*n+u].push_back({(i+1)*n+v.v,0});
            }
        }
    }
    dijk(s);
    int mn=INT_MAX;
    for (int i=0;i<=k;i++){
        mn=min(mn,dis[i*n+t]);
    }
    printf("%d\n",mn);
    return 0;
}