#include <bits/stdc++.h>
#define MAXQ 100003
using namespace std;
int t;
int Q; long long M;
int to[MAXQ]; int cnt;
long long tree[MAXQ<<2];
void pushup(int x){
    tree[x]=tree[x<<1]*tree[x<<1|1]%M;
    return;
}
void cover(int tr,int l,int r,int x,long long z){
    if (l==r){
        tree[tr]=z;
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) cover(tr<<1,l,mid,x,z);
    else cover(tr<<1|1,mid+1,r,x,z);
    pushup(tr);
    return;
}
long long query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1; long long res=1;
    if (x<=mid) res=res*query(tr<<1,l,mid,x,y)%M; 
    if (y>mid) res=res*query(tr<<1|1,mid+1,r,x,y)%M;
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while (t--){
        cin>>Q>>M;
        for (int i=1;i<=Q;i++){
            int type; cin>>type;
            if (type==1){
                to[i]=++cnt; long long m; cin>>m;
                cover(1,1,MAXQ,cnt,m);
                cout<<query(1,1,MAXQ,1,cnt)<<'\n';
            } else {
                int pos; cin>>pos;
                cover(1,1,MAXQ,to[pos],1);
                cout<<query(1,1,MAXQ,1,cnt)<<'\n';
            }
        }
        cnt=0;
    }
    return 0;
}