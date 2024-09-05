#include <bits/stdc++.h>
#define MAXN 40003
#define MAXK 20003
using namespace std;
int n,m;
int k;
struct edge{
    int v;
    int w;
};
vector <edge> e[MAXN];
inline void add(int u,int v,int w){
    e[u].push_back({v,w});
    e[v].push_back({u,w});
    return;
}
int vis[MAXN];
int dis[MAXN],size[MAXN]; int sum; int root,rtsi;
inline void dfs(int u,int fa){
    size[u]=1;
    for (auto ed:e[u]){
        if (vis[ed.v]||ed.v==fa) continue;
        dis[ed.v]=dis[u]+ed.w;
        dfs(ed.v,u);
        size[u]+=size[ed.v];
    }
    int mxsi=0;
    for (auto ed:e[u]){
        if (vis[ed.v]||ed.v==fa) continue;
        mxsi=max(mxsi,size[ed.v]);
    }
    mxsi=max(mxsi,sum-size[u]);
    if (mxsi < rtsi){
        rtsi=mxsi; root=u;
    }
    return;
}
long long TOC[MAXK]; //Tree of Cnt.
int lowbit(int x){
    return x&-x;
}
void ADD(int x,int y){
    for (int p=x;p<=MAXK;p+=lowbit(p)){
        // cout<<p<<endl;
        TOC[p]+=y;
    }
    // cout<<endl;
    return;
}
long long SUM(int x){
    long long res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=TOC[p];
    }
    return res;
}
int q[MAXN],r=0;
int q2[MAXN],r2=0;
int ans;
inline void dfs3(int u,int rt){
    vis[u]=1;
    int len=dis[u]-dis[rt];
    if (k-len>=0) ans+=SUM(k-len)+1;
    q2[++r2]=len;
    for (auto ed:e[u]){
        if (vis[ed.v]) continue;
        dfs3(ed.v,rt);
    }
    vis[u]=0;
    return;
}
inline void dfs2(int u,int rt){
    // cerr<<"ok\n";
    vis[u]=1;
    for (auto ed:e[u]){
        if (vis[ed.v]||ed.v==rt) continue;
        dfs3(ed.v,u);
        for (int i=1;i<=r2;i++) if (q2[i]<=MAXK) ADD(q2[i],1); // cnt[q2[i]]++;
        while (r2) q[++r]=q2[r2--];
    }
    while (r) if (q[r]<=MAXK) ADD(q[r--],-1); else r--;
    for (auto ed:e[u]){
        if (vis[ed.v]||ed.v==rt) continue;
        sum=size[ed.v]; rtsi=INT_MAX;
        dfs(ed.v,rt); dfs(root,rt);
        dfs2(root,rt);
    }
    return;
}
int main(){
    // freopen("2.in","r",stdin);
    // ios::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    cin>>k;
    sum=n; rtsi=INT_MAX;
    dfs(1,0);
    dfs(root,0);
    dfs2(root,0);
    cout<<ans<<endl;
    return 0;
}