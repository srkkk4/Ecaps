#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,m;
struct D{
    int a;
    int b;
    int id;
    bool operator<(const D &B)const {
        return b<B.b;
    }
}A[MAXN];
struct edge{
    int v;
    int val;
};
vector <edge> e[MAXN*3];
int to[MAXN];
long long Dis[MAXN*3];
int vis[MAXN*3];
struct D2{
    int u;
    long long dis;
    bool operator<(const D2 &B)const{
        return dis>B.dis;
    }
};
void dijk(int s){
    priority_queue <D2> q;
    memset(Dis,0x3f,sizeof Dis);
    Dis[s]=0; q.push({s,0});
    while (!q.empty()){
        D2 now=q.top(); q.pop();
        if (vis[now.u]) continue;
        vis[now.u]=1;
        for (edge ed:e[now.u]){
            if (now.dis+ed.val<Dis[ed.v]){
                Dis[ed.v]=now.dis+ed.val;
                q.push({ed.v,Dis[ed.v]});
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>A[i].a;
    for (int i=1;i<=n;i++) cin>>A[i].b;
    for (int i=1;i<=n;i++) A[i].id=i;
    sort(A+1,A+1+n);
    for (int i=1;i<=n;i++) to[A[i].id]=i;
    for (int i=n;i>=2;i--) e[n+i].push_back({n+i-1,0}); //建立前缀链
    for (int i=1;i<=n-1;i++) e[2*n+i].push_back({2*n+i+1,A[i+1].b-A[i].b}); //后缀链
    for (int i=1;i<=n;i++){
        int l=1,r=n+1;
        while (l<r){
            int mid=(l+r)>>1;
            if (A[mid].b+A[i].a>=m) r=mid;
            else l=mid+1;
        }
        if (l>=2) e[i].push_back({n+l-1,A[i].a}); //向前缀链连边，使得可以从此走到所有合法前缀点
        e[n+i].push_back({i,A[i].b}); //前缀链向对应点连边
        if (l<=n) e[i].push_back({2*n+l,A[i].a+A[l].b-m}); //后缀同理
        e[2*n+i].push_back({i,0}); //由于后缀链上已经将b_k处理好，这里不需要边权
    }
    dijk(to[1]);
    cout<<Dis[to[n]]<<endl;
    return 0;
}