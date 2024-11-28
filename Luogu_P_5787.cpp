#include <bits/stdc++.h>
#define MAXN 100003
#define MAXM 200003
#define pb push_back
using namespace std;
int n,m,K;
struct edge{
    int u; int v;
};
vector <edge> tree[MAXN<<2];
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
int ans[MAXN];
int fa[MAXN<<1],key[MAXN<<1];
struct info{int u; int f;}sta[MAXM<<1]; int cnt;
int find(int x) {while (fa[x]!=x) x=fa[x]; return x;}
void merge(int u,int v){
    int fau=find(u),fav=find(v);
    if (key[fau]<key[fav]){
        sta[++cnt]={fau,fau};
        fa[fau]=fav;
    } else {
        sta[++cnt]={fav,fav};
        fa[fav]=fau;
    }
    return;
}
void ret() {fa[sta[cnt].u]=sta[cnt].f; cnt--; return;}
void query(int tr,int l,int r){
    int flag=1;
    for (edge ed:tree[tr]){
        merge(ed.u,ed.v+n); merge(ed.v,ed.u+n);
        if (find(ed.u)==find(ed.u+n)){
            for (int i=l;i<=r;i++) ans[i]=1;
            flag=0;
            break;
        }
    }
    if (flag&&l<r){
        int mid=(l+r)>>1;
        int cntnow=cnt;
        query(tr<<1,l,mid);
        while (cnt!=cntnow) ret();
        query(tr<<1|1,mid+1,r);
        while (cnt!=cntnow) ret();
    }
    return;
}
void init(){
    std::mt19937 Rand(89734324);
    for (int i=1;i<=2*n;i++) fa[i]=i,key[i]=Rand();
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>K;
    init();
    while (m--){
        int x,y,l,r; cin>>x>>y>>l>>r;
        if (l+1<=r) add(1,1,K,l+1,r,(edge){x,y});
    }
    query(1,1,K);
    for (int i=1;i<=K;i++) if (ans[i]) cout<<"No\n"; else cout<<"Yes\n";
    return 0;
}