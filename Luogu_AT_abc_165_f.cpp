#include <bits/stdc++.h>
#define MAXN 200003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
struct NUM{
    int val; int id;
    bool operator <(const NUM &B)const{
        return val<B.val;
    }
}b[MAXN];
int a[MAXN];
vector <int> e[MAXN];
int dp[MAXN],dp2[MAXN];
int tree[MAXN<<2];
struct info{
    int *x; int y;
}sta[MAXN*25]; int cnt;
void update(int &x,int y){
    sta[++cnt]={&x,x};
    x=y;
    return;
}
void ret() {*sta[cnt].x=sta[cnt].y; cnt--; return;}
void pushup(int x){
    update(tree[x],max(tree[x<<1],tree[x<<1|1]));
    return;
}
void chg(int tr,int l,int r,int x,int z){
    if (l==r){
        update(tree[tr],max(z,tree[tr]));
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) chg(tr<<1,l,mid,x,z);
    else chg(tr<<1|1,mid+1,r,x,z);
    pushup(tr);
    return;
}
int query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1; int res=0;
    if (x<=mid) res=max(res,query(tr<<1,l,mid,x,y));
    if (y>mid) res=max(res,query(tr<<1|1,mid+1,r,x,y));
    return res;
}
void dfs(int u,int f){
    dp[u]=((a[u]>1)?query(1,1,n,1,a[u]-1):0)+1;
    dp2[u]=max(dp[u],query(1,1,n,1,n));
    int cntnow=cnt;
    chg(1,1,n,a[u],dp[u]);
    for (int v:e[u]){
        if (v==f) continue;
        dfs(v,u);
    }
    while (cnt!=cntnow) ret();
    return;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>b[i].val; b[i].id=i;}
    sort(b+1,b+1+n); int cntv=0;
    for (int i=1;i<=n;i++){
        if (b[i].val!=b[i-1].val) cntv++;
        a[b[i].id]=cntv;
    }
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<dp2[i]<<'\n';
    return 0;
}