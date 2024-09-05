#include <bits/stdc++.h>
#define MAXN 1000003
// #define int long long
using namespace std;
int n;
int head[MAXN]; int tot;
struct edge{
    int to;
    // int val;
    int net;
};
edge e[MAXN<<1];
void add(int u,int v){
    e[++tot].to=v;
    e[tot].net=head[u];
    head[u]=tot;

    e[++tot].to=u;
    e[tot].net=head[v];
    head[v]=tot;
    return;
}
int size[MAXN],dep[MAXN]; int vis[MAXN];
void dfs(int u){
    size[u]=1;
    vis[u]=1;
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        if (vis[v]) continue;
        dep[v]=dep[u]+1;
        dfs(v);
        size[u]+=size[v];
    }
    return;
}
long long ANS; int root=1; int vis2[MAXN];
void dfs2(int u,long long ans){
    vis2[u]=1;
    // cout<<"u:"<<u<<endl;
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        if (vis2[v]) continue;
        long long res=ans+size[u]-2*size[v];
        if (res>ANS){
            ANS=res;
            // cout<<"ans:"<<ans<<endl;
            root=v;
        }
        // cout<<">:"<<v<<" "<<size[u]<<" "<<size[v]<<" "<<ANS<<endl;
        size[u]-=size[v];
        size[v]=n;
        dfs2(v,res);
        size[v]-=size[u];
        size[u]=n;
    }
    return;
}
int main(){
    cin>>n;
    for (int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    dep[1]=0;
    dfs(1);
    for (int i=1;i<=n;i++){
        ANS+=dep[i];
    }
    // cout<<ANS<<endl;
    dfs2(1,ANS);
    cout<<root<<endl;
    return 0;
}