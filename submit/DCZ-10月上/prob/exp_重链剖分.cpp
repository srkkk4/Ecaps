#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m,R,P;
int a[MAXN];
/*----*/
long long tree[MAXN<<2],tag[MAXN<<2];
void pushup(int x){
    tree[x]=tree[x<<1]+tree[x<<1|1];
}
void pushdown(int x,int l,int r,int mid){
    if(tag[x]==0) return;
    tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x];
    tree[x<<1]+=tag[x]*(mid-l+1); tree[x<<1|1]+=tag[x]*(r-mid);
    tag[x]=0;
}
void add(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree[tr]+=z*(r-l+1);
        tag[tr]+=z;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr,l,r,mid);
    if (mid>=x) add(tr<<1,l,mid,x,y,z);
    if (mid<y) add(tr<<1|1,mid+1,r,x,y,z);
    pushup(tr);
    return;
}
long long query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1;
    pushdown(tr,l,r,mid);
    long long res=0;
    if (mid>=x) res+=query(tr<<1,l,mid,x,y);
    if (mid<y) res+=query(tr<<1|1,mid+1,r,x,y);
    return res;
}
/*--线段树--*/
vector <int> e[MAXN];
int size[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],id[MAXN];
void dfs1(int u,int f){
    size[u]=1; dep[u]=dep[f]+1; fa[u]=f;
    int mx=0;
    for (int v:e[u]){
        if (v==f) continue;
        dfs1(v,u);
        if (size[v]>mx){mx=size[v]; son[u]=v;}
        size[u]+=size[v];
    }
    return;
}
int vis[MAXN],cnt;
void dfs2(int u,int t){
    vis[u]=1;
    top[u]=t; id[u]=++cnt;
    add(1,1,n,cnt,cnt,a[u]);
    if (son[u]) dfs2(son[u],t);
    for (int v:e[u]){
        if (vis[v]||son[u]==v) continue;
        dfs2(v,v);
    }
    return;
}
void ADD1(int u,int v,int z){
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        add(1,1,n,id[top[u]],id[u],z);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    add(1,1,n,id[v],id[u],z);
    return;
}
long long SUM1(int u,int v){
    long long res=0;
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=query(1,1,n,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    res+=query(1,1,n,id[v],id[u]);
    return res;
}
void ADD2(int u,int z){
    add(1,1,n,id[u],id[u]+size[u]-1,z);
    return;
}
long long SUM2(int u){
    return query(1,1,n,id[u],id[u]+size[u]-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>R>>P;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(R,0);
    dfs2(R,R);
    while (m--){
        int type; cin>>type;
        if (type==1){
            int x,y,z; cin>>x>>y>>z;
            ADD1(x,y,z);
        } else if (type==2){
            int x,y; cin>>x>>y;
            cout<<SUM1(x,y)%P<<endl;
        } else if (type==3){
            int x,z; cin>>x>>z;
            ADD2(x,z);
        } else {
            int x; cin>>x;
            cout<<SUM2(x)%P<<endl;
        }
    }
    return 0;
}