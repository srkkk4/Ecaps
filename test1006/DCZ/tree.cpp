#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,m,k;
struct edge{
    int v;
    long long w;
};
vector <edge> e[MAXN];
int K[MAXN],to[MAXN],cnt;
long long dis[MAXN][MAXN];
int vis[MAXN];
inline void dfs(int s,int u,long long d){
    dis[s][u]=d;
    vis[u]=1;
    for (edge ed:e[u]){
        if (vis[ed.v]) continue;
        dfs(s,ed.v,d+ed.w);
    }
    vis[u]=0;
    return;
}
int gone[MAXN]; long long ans;
inline void solve(int p,int step){
    gone[p]=1;
    long long mx=0; int mxi=0;
    if (step!=cnt){
        for (int i=1;i<=cnt;i++){
            if (gone[i]) continue;
            if (dis[K[p]][K[i]]>mx){
                mx=dis[K[p]][K[i]];
                mxi=i;
            }
        }
        ans+=mx;
        // cout<<K[mxi]<<" ";
        solve(mxi,step+1);
    } else {
        mx=dis[K[p]][K[1]];
        ans+=mx;
        // mxi=1;
        // cout<<K[mxi]<<" ";
    }
    gone[p]=0;
    return;
}
int size[MAXN]; int vis2[MAXN];
inline int solve2(int rt,int u){
    int res=0;
    vis2[u]=1;
    if (to[u]) res=1;
    for (edge ed:e[u]){
        if (vis2[ed.v]) continue;
        res+=solve2(rt,ed.v);
    }
    size[u]=res;
    vis2[u]=0;
    return res;
}
int vis3[MAXN];
inline void solve3(int u){
    vis3[u]=1;
    int sum=0;
    for (edge ed:e[u]){
        if (vis3[ed.v]) continue;
        solve3(ed.v);
        sum+=size[ed.v];
    }
    for (edge ed:e[u]){
        if (vis3[ed.v]) continue;
        if (size[ed.v]>=2){
            ans+=ed.w*2*(sum-size[ed.v]+1);
            // cout<<">:"<<ed.v<<" "<<(sum-size[ed.v]+1)<<endl;
        } else if (size[ed.v]){
            ans+=ed.w*2;
        }
    }
    vis3[u]=0;
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for (int i=1;i<=k;i++){
        cin>>K[++cnt]; to[K[cnt]]=cnt;
    }
    for (int i=1;i<=n;i++){
        // for (int j=1;j<=n;j++) vis[j]=0;
        dfs(i,i,0ll);
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    solve2(K[1],K[1]);
    // for (int i=1;i<=n;i++) cout<<size[i]<<" ";
    // cout<<endl;
    solve3(K[1]);
    cout<<ans<<endl;
    for (int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        K[to[x]]=y; to[y]=to[x]; to[x]=0; 
        ans=0;
        solve2(K[1],K[1]);
        solve3(K[1]);
        cout<<ans<<endl;
    }
    return 0;
}