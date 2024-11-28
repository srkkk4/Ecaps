#include <bits/stdc++.h>
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
#define MAXN 500003
#define pb push_back
int n,m;
struct D{
    int id;
    int val;
    bool operator<(const D &B)const{
        return val<B.val;
    }
}a[MAXN];
struct edge{
    int u;
    int v;
    int w;
    bool operator<(const edge &B)const{
        return w>B.w;
    }
};
map <long long,bool> ban;
priority_queue <edge> q;
int fa[MAXN];
int find(int x) {while (fa[x]!=x) x=fa[x]=fa[fa[x]]; return x;}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i].val; a[i].id=i;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        if (a[u].val>a[v].val) swap(u,v);
        ban[1ll*u*500000+v]=ban[1ll*v*500000+u]=1;
        q.push((edge){u,v,w});
    }
    for (int i=1;i<=n;i++) fa[i]=i;
    long long ans=0; int cnt=0; bool flag=0;
    for (int i=1;i<=n;i++){
        int u=a[i].id;
        int fau,fav;
        while (!q.empty()&&q.top().w<=a[i].val){
            edge now=q.top(); q.pop();
            fau=find(now.u); fav=find(now.v);
            if (fau==fav) continue;
            fa[fav]=fau;
            ans+=now.w;
            cnt++; if (cnt==n-1) {flag=1; break;}
        }
        if (flag) break;
        fau=find(u);
        for (int vp=i+1;vp<=n;vp++){
            int v=a[vp].id; if (ban[1ll*u*500000+v]) continue;
            fav=find(v);
            if (fau==fav) continue;
            fa[fav]=fau;
            ans+=a[i].val;
            cnt++; if (cnt==n-1) {flag=1; break;}
        }
        if (flag) break;
    }
    cout<<ans<<'\n';
    return 0;
}