#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,q;
int a[MAXN];
int tree[MAXN<<2],minn[MAXN<<2],num[MAXN<<2];
void pushup(int x){
    tree[x]=__gcd(tree[x<<1],tree[x<<1|1]);
    if (minn[x<<1]==minn[x<<1|1]) {minn[x]=minn[x<<1]; num[x]=num[x<<1]+num[x<<1|1];}
    else if (minn[x<<1]<minn[x<<1|1]) {minn[x]=minn[x<<1]; num[x]=num[x<<1];}
    else if (minn[x<<1]>minn[x<<1|1]) {minn[x]=minn[x<<1|1]; num[x]=num[x<<1|1];}
    return;
}
void build(int tr,int l,int r){
    if (l==r){
        tree[tr]=a[l];
        minn[tr]=a[l];
        num[tr]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(tr<<1,l,mid);
    build(tr<<1|1,mid+1,r);
    pushup(tr);
    return;
}
int query1(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1,res=0;
    if (x<=mid) res=__gcd(res,query1(tr<<1,l,mid,x,y));
    if (y>mid) res=__gcd(res,query1(tr<<1|1,mid+1,r,x,y));
    return res;
}
struct info{int val; int cnt;};
info query2(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return (info){minn[tr],num[tr]};
    }
    int mid=(l+r)>>1; info L={INT_MAX,0},R={INT_MAX,0};
    if (x<=mid) L=query2(tr<<1,l,mid,x,y);
    if (y>mid) R=query2(tr<<1|1,mid+1,r,x,y);
    if (L.val==R.val) return (info){L.val,L.cnt+R.cnt};
    else if (L.val<R.val) return (info){L.val,L.cnt};
    else if (L.val>R.val) return (info){R.val,R.cnt};
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    for (int i=1;i<=q;i++){
        int l,r; cin>>l>>r;
        int GCD=query1(1,1,n,l,r);
        info res=query2(1,1,n,l,r);
        if (GCD==res.val) cout<<(r-l+1)-res.cnt<<'\n';
        else cout<<(r-l+1)<<'\n';
    }
    return 0;
}