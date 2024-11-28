#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
struct LINE{
    int l; int r;
}a[MAXN];
int f[MAXN];
int tree[MAXN<<3],tree2[MAXN<<3],tag[MAXN<<3],tag2[MAXN<<3];
void pushup(int x){
    tree[x]=max(tree[x<<1],tree[x<<1|1]);
    return;
}
void pushdown(int x){
    if (tag[x]==-inf) return;
    tree[x<<1]=max(tree[x<<1],tag[x]);
    tree[x<<1|1]=max(tree[x<<1|1],tag[x]);
    tag[x<<1]=max(tag[x<<1],tag[x]);
    tag[x<<1|1]=max(tag[x<<1|1],tag[x]);
    tag[x]=-inf;
    return;
}
void chg(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree[tr]=max(tree[tr],z);
        tag[tr]=max(tag[tr],z);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr);
    if (x<=mid) chg(tr<<1,l,mid,x,y,z);
    if (y>mid) chg(tr<<1|1,mid+1,r,x,y,z);
    return;
}
int query(int tr,int l,int r,int x){
    if (l==r){
        return tree[tr];
    }
    int mid=(l+r)>>1; int res=-inf;
    pushdown(tr);
    if (x<=mid) res=max(res,query(tr<<1,l,mid,x));
    else res=max(res,query(tr<<1|1,mid+1,r,x));
    pushup(tr);
    return res;
}

void pushup2(int x){
    tree2[x]=max(tree2[x<<1],tree2[x<<1|1]);
    return;
}
void pushdown2(int x){
    if (tag2[x]==-inf) return;
    tree2[x<<1]=max(tree2[x<<1],tag2[x]);
    tree2[x<<1|1]=max(tree2[x<<1|1],tag2[x]);
    tag2[x<<1]=max(tag2[x<<1],tag2[x]);
    tag2[x<<1|1]=max(tag2[x<<1|1],tag2[x]);
    tag2[x]=-inf;
    return;
}
void chg2(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree2[tr]=max(tree2[tr],z);
        tag2[tr]=max(tag2[tr],z);
        return;
    }
    int mid=(l+r)>>1;
    pushdown2(tr);
    if (x<=mid) chg2(tr<<1,l,mid,x,y,z);
    if (y>mid) chg2(tr<<1|1,mid+1,r,x,y,z);
    return;
}
int query2(int tr,int l,int r,int x){
    if (l==r){
        return tree2[tr];
    }
    int mid=(l+r)>>1; int res=-inf;
    pushdown2(tr);
    if (x<=mid) res=max(res,query2(tr<<1,l,mid,x));
    else res=max(res,query2(tr<<1|1,mid+1,r,x));
    pushup2(tr);
    return res;
}
int D[MAXN*2]; int cntd;
map <int,int> to;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r; D[++cntd]=a[i].l; D[++cntd]=a[i].r;
    }
    sort(D+1,D+1+cntd); int cnt=0;
    for (int i=1;i<=cntd;i++){
        if (D[i]!=D[i-1]){
            to[D[i]]=++cnt;
        }
    }
    for (int i=1;i<=n*8;i++){
        tree[i]=-inf; tree2[i]=-inf;
        tag[i]=-inf; tag2[i]=-inf;
    }
    f[1]=a[1].r-a[1].l+1; int ans=f[1];
    if (to[a[1].r]+1<=cnt) chg(1,1,cnt,to[a[1].r]+1,cnt,f[1]);
    chg2(1,1,cnt,1,to[a[1].r],f[1]-a[1].r);
    for (int i=2;i<=n;i++){
        f[i]=a[i].r-a[i].l+1;
        f[i]=max(f[i],a[i].r-a[i].l+1+query(1,1,cnt,to[a[i].l]));
        f[i]=max(f[i],a[i].r+query2(1,1,cnt,to[a[i].l]));
        ans=max(ans,f[i]);
        if (to[a[i].r]+1<=cnt) chg(1,1,cnt,to[a[i].r]+1,cnt,f[i]);
        chg2(1,1,cnt,1,to[a[i].r],f[i]-a[i].r);
    }
    cout<<ans<<'\n';
    return 0;
}