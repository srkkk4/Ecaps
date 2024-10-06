#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m,k;
struct edge{
    int v;
    long long w;
};
vector <edge> e[MAXN]; 
bool K[MAXN];
int root;
int vis[MAXN];
int real_size[MAXN];
int mn_sTree_size=INT_MAX;
void getRoot(register int u){
    vis[u]=1;
    real_size[u]=1;
    for (edge ed:e[u]){
        if (vis[ed.v]) continue;
        getRoot(ed.v);
        real_size[u]+=real_size[ed.v];
    }
    register int mx_sTree_size=0;
    for (edge ed:e[u]){
        mx_sTree_size=max(mx_sTree_size,real_size[ed.v]);
    }
    mx_sTree_size=max(mx_sTree_size,n-real_size[u]);
    if (mx_sTree_size<mn_sTree_size){
        mn_sTree_size=mx_sTree_size;
        root=u;
    }
    vis[u]=0;
    return;
}
int size[MAXN],fa[MAXN],dep[MAXN];
long long faq[MAXN];
void inSize(register int u){
    vis[u]=1;
    if (K[u]) size[u]=1;
    for (edge ed:e[u]){
        if (vis[ed.v]) continue;
        dep[ed.v]=dep[u]+1;
        inSize(ed.v);
        size[u]+=size[ed.v];
        fa[ed.v]=u; faq[ed.v]=ed.w;
    }
    vis[u]=0;
    return;
}
long long ans;
void solve(register int u){
    vis[u]=1;
    for (edge ed:e[u]){
        if (vis[ed.v]) continue;
        ans+=ed.w*min(size[ed.v],size[root]-size[ed.v]);
        solve(ed.v);
    }
    vis[u]=0;
    return;
}
int LCA(register int x,register int y){
    if (dep[x]<dep[y]) swap(x,y); 
    while (dep[x]>dep[y]) x=fa[x];
    while (x!=y) {x=fa[x]; y=fa[y];}
    return x;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n>>m>>k;
    for (register int i=1;i<n;i++){
        register int u,v,w; cin>>u>>v>>w;
        e[u].push_back({v,w<<1});
        e[v].push_back({u,w<<1});
    }
    getRoot(1);
    for (register int i=1;i<=k;i++){
        register int x; cin>>x;
        K[x]=1;
    }
    dep[root]=1;
    inSize(root);
    solve(root);
    cout<<ans<<'\n';
    for (register int i=1;i<=m;i++){
        // if (i==m/2) cout<<"ok\n";
        register int x,y; cin>>x>>y;
        K[x]=0; K[y]=1;
        while (dep[x]>dep[y]){
            ans-=faq[x]*min(size[x],size[root]-size[x]);
            size[x]--;
            ans+=faq[x]*min(size[x],size[root]-size[x]);
            x=fa[x];
        }
        while (dep[x]<dep[y]){
            ans-=faq[y]*min(size[y],size[root]-size[y]);
            size[y]++;
            ans+=faq[y]*min(size[y],size[root]-size[y]);
            y=fa[y];
        }
        while (x!=y){
            ans-=faq[x]*min(size[x],size[root]-size[x]);
            size[x]--;
            ans+=faq[x]*min(size[x],size[root]-size[x]);
            x=fa[x];
            ans-=faq[y]*min(size[y],size[root]-size[y]);
            size[y]++;
            ans+=faq[y]*min(size[y],size[root]-size[y]);
            y=fa[y];
        }
        cout<<ans<<'\n';
    }
    return 0;
}