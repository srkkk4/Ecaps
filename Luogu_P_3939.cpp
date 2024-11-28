#include <bits/stdc++.h>
#define MAXN 300003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
int a[MAXN];
int root[MAXN];
int tree[MAXN<<6],ls[MAXN<<6],rs[MAXN<<6];
int inx;
void chg(int u,int v,int l,int r,int x,int z){
    if (l==r){
        tree[v]=tree[u]+z;
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid){
        ls[v]=++inx; rs[v]=rs[u];
        chg(ls[u],ls[v],l,mid,x,z);
    } else {
        ls[v]=ls[u]; rs[v]=++inx;
        chg(rs[u],rs[v],mid+1,r,x,z);
    }
    return;
}
int query(int tr,int l,int r,int x){
    if (l==r){
        return tree[tr];
    }
    int mid=(l+r)>>1;
    if (x<=mid) return query(ls[tr],l,mid,x);
    else return query(rs[tr],mid+1,r,x);
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        root[i]=++inx;
        chg(root[i-1],root[i],1,MAXN-2,a[i],1);
    }
    for (int i=1;i<=m;i++){
        int type; cin>>type;
        if (type==1){
            int l,r,c; cin>>l>>r>>c;
            cout<<query(root[r],1,MAXN-2,c)-query(root[l-1],1,MAXN-2,c)<<'\n';
        } else {
            int x; cin>>x;
            int nxt=++inx;
            chg(root[x],nxt,1,MAXN-2,a[x],-1);
            root[x]=nxt;
            nxt=++inx;
            chg(root[x],nxt,1,MAXN-2,a[x+1],1);
            root[x]=nxt;
            swap(a[x],a[x+1]);
        }
    }
    return 0;
}