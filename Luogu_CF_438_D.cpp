#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m;
int a[MAXN];
long long SUM[MAXN<<2]; int MAX[MAXN<<2];
void pushup(int x){
    SUM[x]=SUM[x<<1]+SUM[x<<1|1];
    MAX[x]=max(MAX[x<<1],MAX[x<<1|1]);
}
void build(int tr,int l,int r){
    if (l==r) {SUM[tr]=a[l]; MAX[tr]=a[l]; return;}
    int mid=(l+r)>>1;
    build(tr<<1,l,mid);
    build(tr<<1|1,mid+1,r);
    pushup(tr);
    return;
}
void modify(int tr,int l,int r,int x,int z){
    if (l==r){
        SUM[tr]=z; MAX[tr]=z;
        return;
    }
    int mid=(l+r)>>1;
    if (mid>=x) modify(tr<<1,l,mid,x,z);
    if (mid<x) modify(tr<<1|1,mid+1,r,x,z);
    pushup(tr);
    return;
}
void modimod(int tr,int l,int r,int x,int y,long long z){
    if (MAX[tr]<z) return;
    if (l==r) {SUM[tr]=SUM[tr]%z; MAX[tr]=SUM[tr]; return;}
    int mid=(l+r)>>1;
    if (mid>=x) modimod(tr<<1,l,mid,x,y,z);
    if (mid<y) modimod(tr<<1|1,mid+1,r,x,y,z);
    pushup(tr);
    return;
}
long long query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return SUM[tr];
    }
    int mid=(l+r)>>1; long long res=0;
    if (mid>=x) res+=query(tr<<1,l,mid,x,y);
    if (mid<y) res+=query(tr<<1|1,mid+1,r,x,y);
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (m--){
        int type; cin>>type;
        if (type==1){
            int l,r; cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        } else if (type==2){
            int l,r,x; cin>>l>>r>>x;
            modimod(1,1,n,l,r,x);
        } else {
            int k,x; cin>>k>>x;
            modify(1,1,n,k,x);
        }
    }
    return 0;
}