#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
vector <int> e[MAXN];
struct TREE{
    int cl; int cr;
    int k;
    TREE operator+(const TREE &B)const{ //重载加法，方便合并
        if (B.k==0) return (TREE){cl,cr,k};
        if (k==0) return B;
        TREE res;
        res.cl=cl; res.cr=B.cr;
        if (cr!=B.cl) res.k=k+B.k;
        else res.k=k+B.k-1;
        return res;
    }
}tree[MAXN<<2];
struct TAG{
    int val;
    int time;
}tag[MAXN<<2];
int TIME;
void pushup(int x){
    tree[x]=tree[x<<1]+tree[x<<1|1];
}
void pushdown(int x,int l,int r,int mid){
    if (tag[x].time==0) return;
    if (tag[x<<1].time<tag[x].time) tag[x<<1]=tag[x];
    if (tag[x<<1|1].time<tag[x].time) tag[x<<1|1]=tag[x];
    tree[x<<1].cl=tree[x<<1].cr=tag[x<<1].val; tree[x<<1|1].cl=tree[x<<1|1].cr=tag[x<<1|1].val;
    tree[x<<1].k=1; tree[x<<1|1].k=1; //懒标记覆盖
    tag[x].val=0,tag[x].time=0;
}
void build(int tr,int l,int r){
    if (l==r) {tree[tr].cl=tree[tr].cr=b[l]; tree[tr].k=1; return;}
    int mid=(l+r)>>1;
    build(tr<<1,l,mid);
    build(tr<<1|1,mid+1,r);
    pushup(tr);
    return;
}
void modify(int tr,int l,int r,int x,int y,int c){
    if (x<=l&&r<=y){
        tree[tr].cl=tree[tr].cr=c; tree[tr].k=1;
        tag[tr].val=c;
        tag[tr].time=++TIME;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr,l,r,mid);
    if (mid>=x) modify(tr<<1,l,mid,x,y,c);
    if (mid<y) modify(tr<<1|1,mid+1,r,x,y,c);
    pushup(tr);
    return;
}
TREE query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1;
    TREE res={0,0,0};
    pushdown(tr,l,r,mid);
    if (mid>=x) res=res+query(tr<<1,l,mid,x,y);
    if (mid<y) res=res+query(tr<<1|1,mid+1,r,x,y);
    return res;
}
int size[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],id[MAXN];
void dfs1(int u,int f){
    size[u]=1; dep[u]=dep[f]+1; fa[u]=f;
    int mx=0;
    for (int v:e[u]){
        if (v==f) continue;
        dfs1(v,u);
        size[u]+=size[v];
        if (size[v]>mx) {mx=size[v]; son[u]=v;}
    }
    return;
}
int cnt;
void dfs2(int u,int t){
    top[u]=t; id[u]=++cnt;
    if (son[u]) dfs2(son[u],t);
    for (int v:e[u]){
        if (son[u]==v||fa[u]==v) continue;
        dfs2(v,v);
    }
    return;
}
void CHG1(int u,int v,int c){
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        modify(1,1,n,id[top[u]],id[u],c);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    modify(1,1,n,id[v],id[u],c);
    return;
}
TREE q[2][MAXN]; int CNT[2];
TREE SUM1(int u,int v){
    bool side=0; CNT[0]=CNT[1]=0;
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) {swap(u,v); side=!side;}
        TREE RT=query(1,1,n,id[top[u]],id[u]); if (!side) swap(RT.cl,RT.cr);
        q[side][++CNT[side]]=RT;
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) {swap(u,v); side=!side;}
    TREE RT=query(1,1,n,id[v],id[u]); if (!side) swap(RT.cl,RT.cr);
    TREE res={0,0,0};
    for (int i=1;i<=CNT[0];i++) res=res+q[0][i];
    res=res+RT;
    for (int i=CNT[1];i>=1;i--) res=res+q[1][i];
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    for (int i=1;i<=n;i++) b[id[i]]=a[i];
    build(1,1,n);
    while (m--){
        char type; cin>>type;
        if (type=='C'){
            int u,v,c; cin>>u>>v>>c;
            CHG1(u,v,c);
        } else {
            int u,v; cin>>u>>v;
            cout<<SUM1(u,v).k<<endl;
        }
    }
    return 0;
}