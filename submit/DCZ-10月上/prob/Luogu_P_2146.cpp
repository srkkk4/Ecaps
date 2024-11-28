#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,q;
vector <int> e[MAXN];
int tree[MAXN<<2];
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
    tree[x<<1]=tag[x<<1].val*(mid-l+1); tree[x<<1|1]=tag[x<<1|1].val*(r-mid);
    tag[x].val=0,tag[x].time=0;
}
void modify(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree[tr]=z*(r-l+1);
        tag[tr].val=z;
        tag[tr].time=++TIME;
        return;
    }
    int mid=(l+r)>>1;
    if (mid>=x) modify(tr<<1,l,mid,x,y,z);
    if (mid<y) modify(tr<<1|1,mid+1,r,x,y,z);
    pushup(tr);
    return;
}
int query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1,res=0;
    pushdown(tr,l,r,mid);
    if (mid>=x) res+=query(tr<<1,l,mid,x,y);
    if (mid<y) res+=query(tr<<1|1,mid+1,r,x,y);
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
void CHG1(int u,int v,int z){
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        modify(1,1,n,id[top[u]],id[u],z);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    modify(1,1,n,id[v],id[u],z);
    return;
}
int SUM1(int u,int v){
    int res=0;
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=query(1,1,n,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    res+=query(1,1,n,id[v],id[u]);
    return res;
}
void CHG2(int u,int z){
    modify(1,1,n,id[u],id[u]+size[u]-1,z);
    return;
}
int SUM2(int u){
    return query(1,1,n,id[u],id[u]+size[u]-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int u=1;u<=n-1;u++){
        int v; cin>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(0,MAXN);
    dfs2(0,0);
    cin>>q;
    while (q--){
        string type; cin>>type;
        if (type=="install"){
            int x; cin>>x;
            int res=-SUM1(0,x); //减去原本有的
            CHG1(0,x,1);
            res+=SUM1(0,x); //加上上面所有的
            cout<<res<<endl; //等于新加的
        } else {
            int x; cin>>x;
            cout<<SUM2(x)<<endl; //原本有的就是要被删的
            CHG2(x,0); //删除
        }
    }
    return 0;
}