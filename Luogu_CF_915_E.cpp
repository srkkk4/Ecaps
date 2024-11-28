#include <bits/stdc++.h>
#define MAXN 15000003
#define MAXTAG 300003
using namespace std;
bool ST;
int n,q;
int tree[MAXN],tag[MAXN],ls[MAXN],rs[MAXN]; int cnt1=1;
int ct[MAXTAG]; int cnt2;
void pushup(int x){
    tree[x]=tree[ls[x]]+tree[rs[x]];
    return;
}
void pushdown(int tr,int l,int r,int mid){
    if (!ls[tr]) ls[tr]=++cnt1;
    if (!rs[tr]) rs[tr]=++cnt1;
    if (!tag[tr]) return;
    tag[ls[tr]]=max(tag[ls[tr]],tag[tr]); tag[rs[tr]]=max(tag[rs[tr]],tag[tr]);
    tree[ls[tr]]=(mid-l+1)*ct[tag[ls[tr]]]; tree[rs[tr]]=(r-mid)*ct[tag[rs[tr]]];
    tag[tr]=0;
    return;
}
void cover(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree[tr]=(r-l+1)*z;
        tag[tr]=cnt2;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr,l,r,mid);
    if (x<=mid) cover(ls[tr],l,mid,x,y,z);
    if (y>mid) cover(rs[tr],mid+1,r,x,y,z);
    pushup(tr);
    return;
}
int query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1; int res=0;
    pushdown(tr,l,r,mid);
    if (x<=mid) res+=query(ls[tr],l,mid,x,y);
    if (y>mid) res+=query(rs[tr],mid+1,r,x,y);
    return res;
}
bool ED;
int main(){
    // cerr<<(&ED-&ST)/1024.0/1024.0<<"MB\n";
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    ct[++cnt2]=1; cover(1,1,n,1,n,1);
    while (q--){
        int l,r,k; cin>>l>>r>>k;
        if (k==1) {ct[++cnt2]=0; cover(1,1,n,l,r,0);}
        else {ct[++cnt2]=1; cover(1,1,n,l,r,1);}
        cout<<tree[1]<<'\n';
    }
    return 0;
}