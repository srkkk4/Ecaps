#include <bits/stdc++.h>
#define MAXN 100003
#define MAXQ 100003
#define pb push_back
using namespace std;
bool ST;
int n,q;
int fa[MAXN],sz[MAXN];
struct info{int u; int f; int sz;}sta[MAXQ*17]; int cnt;
struct edge{
    int u; int v;
};
vector <edge> tree[MAXQ<<2];
void add(int tr,int l,int r,int x,int y,edge ed){
    if (x<=l&&r<=y){
        tree[tr].pb(ed);
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) add(tr<<1,l,mid,x,y,ed);
    if (y>mid) add(tr<<1|1,mid+1,r,x,y,ed);
    return;
}
int find(int x) {while (fa[x]!=x) x=fa[x]; return x;}
void merge(int u,int v){
    int fau=find(u),fav=find(v);
    if (sz[fau]<sz[fav]){
        sta[++cnt]=(info){fau,fau,sz[fav]};
        fa[fau]=fav;
        sz[fav]+=sz[fau];
    } else {
        sta[++cnt]=(info){fav,fav,sz[fau]};
        fa[fav]=fau;
        sz[fau]+=sz[fav];
    }
    return;
}
void ret() {sz[fa[sta[cnt].u]]=sta[cnt].sz; fa[sta[cnt].u]=sta[cnt].f; cnt--; return;}
struct QUE{
    int u; int v;
}Q[MAXQ]; int cntq;
int to[MAXQ];
long long ans[MAXQ];
void query(int tr,int l,int r){
    for (edge ed:tree[tr]) merge(ed.u,ed.v);
    if (l==r){
        if (to[l]) ans[to[l]]=1ll*sz[find(Q[to[l]].u)]*sz[find(Q[to[l]].v)];
        return;
    }
    int mid=(l+r)>>1; int cntnow=cnt;
    query(tr<<1,l,mid);
    while (cnt!=cntnow) ret();
    query(tr<<1|1,mid+1,r);
    while (cnt!=cntnow) ret();
    return;
}
map <long long,int> mp;
void init(){
    for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    return;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // cerr<<(&ED-&ST)/1024.0/1024.0<<"MB\n";
    cin>>n>>q;
    init();
    for (int i=1;i<=q;i++){
        char type; int x,y; cin>>type>>x>>y;
        if (x>y) swap(x,y);
        if (type=='A'){
            mp[1ll*x*1000000+y]=i;
        } else {
            int last=mp[1ll*x*1000000+y];
            if (last+1<=i-1) add(1,1,q,last+1,i-1,(edge){x,y});
            mp[1ll*x*1000000+y]=i;
            to[i]=++cntq;
            Q[cntq]=(QUE){x,y};
        }
    }
    map <long long,int>::iterator it;
    for (it=mp.begin();it!=mp.end();it++){
        int last=it->second,u=it->first/1000000,v=it->first%1000000;
        if (last+1<=q) add(1,1,q,last+1,q,(edge){u,v});
    }
    query(1,1,q);
    for (int i=1;i<=cntq;i++) cout<<ans[i]<<'\n';
    return 0;
}