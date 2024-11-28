#include <bits/stdc++.h>
#define MAXN 100003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
int root[MAXN]; int len[MAXN];
int ls[MAXN<<5],rs[MAXN<<5];
char tree[MAXN<<5];
int inx,rtinx;
void chg(int u,int v,int l,int r,int x,char c){
    if (l==r){
        tree[v]=c;
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid){
        ls[v]=++inx; rs[v]=rs[u];
        chg(ls[u],ls[v],l,mid,x,c);
    } else {
        ls[v]=ls[u]; rs[v]=++inx;
        chg(rs[u],rs[v],mid+1,r,x,c);
    }
    return;
}
char query(int tr,int l,int r,int x){
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
    cin>>n;
    for (int i=1;i<=n;i++){
        char type; cin>>type;
        if (type=='T'){
            char x; cin>>x;
            root[++rtinx]=++inx;
            len[rtinx]=len[rtinx-1]+1;
            chg(root[rtinx-1],root[rtinx],1,n,len[rtinx],x);
        } else if (type=='U'){
            int x; cin>>x;
            rtinx++;
            root[rtinx]=root[rtinx-1-x];
            len[rtinx]=len[rtinx-1-x];
        } else {
            int x; cin>>x;
            cout<<query(root[rtinx],1,n,x)<<'\n';
        }
    }
    return 0;
}