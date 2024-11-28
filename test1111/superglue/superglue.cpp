#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,q;
long long a[MAXN];
vector <int> e[MAXN];
int root=1,inx;
int size[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],dfn[MAXN];
int to[MAXN];
long long Lock[MAXN];
long long tree[MAXN<<2]; long long tag[MAXN<<2];
int stk[MAXN],cnt;
struct STAKE{
    long long *x; long long y;
}Stk[MAXN*500]; int Cnt;
void upd(long long &x,long long y){
    Stk[++Cnt]={&x,x};
    x=y;
};
void pushup(int x){
    // tree[x]=tree[x<<1]+tree[x<<1|1];
    upd(tree[x],tree[x<<1]+tree[x<<1|1]);
    return;
}
void pushdown(int x){
    if (!tag[x]) return;
    // tree[x<<1]=tree[x<<1|1]=0;
    upd(tree[x<<1],0); upd(tree[x<<1|1],0);
    // tag[x<<1]=tag[x<<1|1]=1;
    upd(tag[x<<1],1); upd(tag[x<<1|1],1);
    // tag[x]=0;
    upd(tag[x],0);
    return;
}
void build(int tr,int l,int r){
    if (l==r){
        // tree[tr]=Lock[l];
        upd(tree[tr],Lock[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(tr<<1,l,mid);
    build(tr<<1|1,mid+1,r);
    pushup(tr);
    return;
}
void to_be_plain(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        // tree[tr]=0;
        upd(tree[tr],0);
        // tag[tr]=1;
        upd(tag[tr],1);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr);
    if (x<=mid) to_be_plain(tr<<1,l,mid,x,y);
    if (y>mid) to_be_plain(tr<<1|1,mid+1,r,x,y);
    pushup(tr);
    return;
}
void add(int tr,int l,int r,int x,long long z){
    if (l==r){
        // tree[tr]+=z;
        upd(tree[tr],tree[tr]+z);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr);
    if (x<=mid) add(tr<<1,l,mid,x,z);
    if (x>mid) add(tr<<1|1,mid+1,r,x,z);
    pushup(tr);
    return;
}
long long query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1; long long res=0;
    pushdown(tr);
    if (x<=mid) res+=query(tr<<1,l,mid,x,y);
    if (y>mid) res+=query(tr<<1|1,mid+1,r,x,y);
    return res;
}
void dfs(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    size[u]=1;
    int mx=0;
    for (int v:e[u]){
        if (v==f) continue;
        dfs(v,u);
        if (size[v]>mx){
            mx=size[v];
            son[u]=v;
        }
        size[u]+=size[v];
    }
    return;
}
void dfs2(int u,int t){
    dfn[u]=++inx;
    top[u]=t;
    if (son[u]){
        dfs2(son[u],t);
    }
    for (int v:e[u]){
        if (v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
int find(int x){
    while (query(1,1,n,dfn[top[x]],dfn[x])==0){
        x=fa[top[x]];
    }
    int L=dfn[top[x]],R=dfn[x],ans=L;
    while (L<=R){
        int mid=(L+R)>>1;
        if (query(1,1,n,mid,dfn[x])!=0) {L=mid+1; ans=mid;}
        else R=mid-1;
    }
    x=to[ans];
    return x;
}
int main(){
    // freopen("uoj2.in","r",stdin);
    freopen("superglue.in","r",stdin);
    freopen("superglue.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(root,0);
    dfs2(root,root);
    for (int i=1;i<=n;i++) to[dfn[i]]=i;
    for (int i=1;i<=n;i++){
        Lock[i]=a[to[i]];
    }
    build(1,1,n);
    while (q--){
        int type; cin>>type;
        if (type==1){
            stk[++cnt]=Cnt;
            int u,v; cin>>u>>v;
            long long sum=0;
            while (top[u]!=top[v]){
                if (dep[top[u]]<dep[top[v]]) swap(u,v);
                sum+=query(1,1,n,dfn[top[u]],dfn[u]);
                to_be_plain(1,1,n,dfn[top[u]],dfn[u]);
                u=fa[top[u]];
            }
            if (dep[u]<dep[v]) swap(u,v);
            int p=find(v);
            if (u!=v){
                sum+=query(1,1,n,dfn[v]+1,dfn[u]);
                to_be_plain(1,1,n,dfn[v]+1,dfn[u]);
            }
            add(1,1,n,dfn[p],sum);
        } else if (type==2){
            for (int i=Cnt;i>=stk[cnt]+1;i--){
                *Stk[i].x=Stk[i].y;
            }
            Cnt=stk[cnt];
            cnt--;
        } else {
            int u; cin>>u;
            u=find(u);
            cout<<query(1,1,n,dfn[u],dfn[u])<<'\n';
        }
    }
    return 0;
}
/*
6 4
100000 20000 3000 400 50 6
1 3
4 2
2 5
6 2
2 1
1 4 6
3 2
1 3 5
3 6

6 8
100000 20000 3000 400 50 6
1 3
4 2
2 5
6 2
2 1
1 4 6
3 2
1 3 5
3 6
2
1 1 3
3 2
3 3
*/