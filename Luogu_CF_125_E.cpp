#include <bits/stdc++.h>
#define MAXN 100003
#define pb push_back
using namespace std;
int n,m,s=1,k;
struct edge{
    int u; int v; int w; int col;
    int id;
    bool operator <(const edge &B) const{
        return w<B.w||(w==B.w&&col>B.col);
    }
}E1[MAXN],E2[MAXN],E[MAXN]; int cnt1,cnt2,cnt3;
int q[MAXN],cnt;
int is[MAXN];
int fa[MAXN];
int find(int x) {while (fa[x]!=x) x=fa[x]=fa[fa[x]]; return x;}
int chk;
long long kruskal(int drta,bool prt){
    long long res=0; chk=0; cnt3=0;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=cnt1;i++) E1[i].w+=drta;
    int x=1,y=1;
    while (x<=cnt1&&y<=cnt2){
        if (E1[x]<E2[y]) {E[++cnt3]=E1[x]; x++;}
        else {E[++cnt3]=E2[y]; y++;}
    }
    while (x<=cnt1) {E[++cnt3]=E1[x]; x++;}
    while (y<=cnt2) {E[++cnt3]=E2[y]; y++;}
    for (int i=1;i<=cnt1;i++) E1[i].w-=drta;
    int cntd=0;
    for (int i=1;i<=cnt3;i++){
        int fau=find(E[i].u),fav=find(E[i].v);
        if (fau==fav) continue;
        if (is[E[i].id]) chk++;
        res+=E[i].w;
        if (prt) cout<<E[i].id<<" ";
        fa[fau]=fav;
        cntd++;
        if (cntd==n-1) return res;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        if (u==s||v==s) {E1[++cnt1].u=u; E1[cnt1].v=v; E1[cnt1].w=w; E1[cnt1].id=i; E1[cnt1].col=1; q[++cnt]=i; is[i]=1;}
        else {E2[++cnt2].u=u; E2[cnt2].v=v; E2[cnt2].w=w; E2[cnt2].id=i;}
    }

    sort(E1+1,E1+1+cnt1); sort(E2+1,E2+1+cnt2);

    kruskal(-1000000000,0);
    if (chk<k) {cout<<"-1\n"; return 0;}

    kruskal(1000000000,0);
    if (chk>k) {cout<<"-1\n"; return 0;}

    int l=-1000000000,r=1000000000; long long ans=0;
    while (l<r){
        int mid=(l+r+1)>>1;
        kruskal(mid,0);
        if (chk>=k) l=mid;
        else r=mid-1;
    }
    cout<<n-1<<'\n';
    kruskal(r,1); cout<<'\n';
    // cerr<<kruskal(r,0)-k*r<<'\n';
    return 0;
}