#include <bits/stdc++.h>
#define MAXN 1003
#define mod 1000000007
using namespace std;
int n,m;
vector <int> e[MAXN];
int dis[MAXN][MAXN];
int vis[MAXN];
struct D{
    int u;
    int Dis;
    bool operator <(const D &B)const{
        return Dis>B.Dis;
    }
};
void dijk(int s){
    memset(dis[s],0x3f,sizeof dis[s]);
    memset(vis,0,sizeof vis);
    priority_queue <D> q;
    dis[s][s]=0;
    q.push({s,0});
    while (!q.empty()){
        D now=q.top(); q.pop();
        vis[now.u]=1;
        for (int v:e[now.u]){
            if (vis[v]) continue;
            if (now.Dis+1<dis[s][v]){
                dis[s][v]=now.Dis+1;
                q.push({v,dis[s][v]});
            }
        }
    }
    return;
}
long long qpow(long long x,int y){
    long long res=1;
    while (y){
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main(){
    // freopen("data.in","r",stdin);
    freopen("polaris.in","r",stdin);
    freopen("polaris.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        dijk(i);
    }
    long long ans=0;
    for (int i=1;i<=n;i++){
        sort(dis[i]+1,dis[i]+1+n);
        for (int j=n,k=1;j>=1;j--,k++){
            ans=(ans+1ll*dis[i][j]*qpow(2,k-1)%mod)%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}