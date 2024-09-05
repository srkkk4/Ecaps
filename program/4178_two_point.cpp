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
int q[MAXN],r=0;
int ans;
inline void dfs3(int u,int rt){
    vis[u]=1;
    int len=dis[u]-dis[rt];
    q[++r]=len;
    for (auto ed:e[u]){
        if (vis[ed.v]) continue;
        dfs3(ed.v,rt);
    }
    vis[u]=0;
    return;
}
int calc(int K){
    sort(q+1,q+1+r);
    int res=0;
    int L=1,R=r;
    while(L <= R) (q[L] + q[R] <= K) ? (res += R - L, ++ L) : (-- R);
    return res;
}
inline void dfs2(int u,int rt){
    // cerr<<"ok\n";
    vis[u]=1;
    q[++r]=0;
    for (auto ed:e[u]){
        if (vis[ed.v]||ed.v==rt) continue;
        dfs3(ed.v,u);
    }
    ans+=calc(k);
    // cout<<">:"<<calc(k)<<endl;
    // for (int i=1;i<=r;i++) cout<<q[i]<<" ";
    // cout<<endl;
    r=0;
    for (auto ed:e[u]){
        if (vis[ed.v]||ed.v==rt) continue;
        dfs3(ed.v,u);
        ans-=calc(k);
        // cout<<"-:"<<calc(k)<<endl;
        // for (int i=1;i<=r;i++) cout<<q[i]<<" ";
        // cout<<endl;
        r=0;
    }
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