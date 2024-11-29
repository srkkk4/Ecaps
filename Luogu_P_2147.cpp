#include <bits/stdc++.h>
#define MAXN 10003
#define MAXM 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
map <pair<int,int>,int> lst;
vector <pair<int,int> > tree[MAXM<<2];
int fa[MAXN];
int find(int x) {while (fa[x]!=x) x=fa[x]; return x;}
struct info{
    int *x,y;
}sta[MAXM]; int cnt;
void update(int &x,int y){
    sta[++cnt]=(info){&x,x};
    x=y;
    return;
}
void ret() {*sta[cnt].x=sta[cnt].y; cnt--; return;}
void add(int tr,int l,int r,int x,int y,pair<int,int> ed){
    if (x<=l&&r<=y){
        tree[tr].pb(ed);
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) add(tr<<1,l,mid,x,y,ed);
    if (y>mid) add(tr<<1|1,mid+1,r,x,y,ed);
    return;
}
bool isq[MAXM];
struct QUE{
    int u;
    int v;
}Q[MAXM];
bool ans[MAXM];
mt19937 Rand(time(0));
void query(int tr,int l,int r){
    for (auto ed:tree[tr]){
        int fau=find(ed.first),fav=find(ed.second);
        if (Rand()&1) update(fa[fau],fav);
        else update(fa[fav],fau);
    }
    if (l==r){
        if (!isq[l]) return;
        int fau=find(Q[l].u),fav=find(Q[l].v);
        if (fau==fav) ans[l]=1;
        return;
    }
    int cntnow=cnt;
    int mid=(l+r)>>1;
    query(tr<<1,l,mid);
    while (cnt!=cntnow) ret();
    query(tr<<1|1,mid+1,r);
    while (cnt!=cntnow) ret();
    return;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        string type; cin>>type;
        int u,v; cin>>u>>v; if (u>v) swap(u,v);
        pair <int,int> ed=make_pair(u,v);
        if (type=="Connect"){
            if (lst[ed]) continue;
            lst[ed]=i;
        } else if (type=="Destroy"){
            add(1,1,m,lst[ed],i-1,ed);
            lst[ed]=0;
        } else {
            isq[i]=1;
            Q[i]=(QUE){u,v};
        }
    }
    map <pair<int,int>,int>::iterator it;
    for (it=lst.begin();it!=lst.end();it++){
        if (!((*it).second)) continue;
        add(1,1,m,(*it).second,m,(*it).first);
    }
    for (int i=1;i<=n;i++) fa[i]=i;
    query(1,1,m);
    for (int i=1;i<=m;i++){
        if (!isq[i]) continue;
        if (ans[i]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}