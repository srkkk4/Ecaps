#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
struct edge{
    int v; int b; int c;
};
vector <edge> e[MAXN];
double dp[MAXN];
int du[MAXN];
int tope[MAXN]; int cnt;
void dfs(int u){
    tope[++cnt]=u;
    for (edge ed:e[u]){
        du[ed.v]--;
        if (!du[ed.v]) dfs(ed.v);
    }
    return;
}
bool check(double mid){
    for (int i=1;i<=n;i++) dp[i]=-2e13;
    dp[1]=0.0;
    for (int i=1;i<=n;i++){
        for (edge ed:e[i]){
            dp[ed.v]=max(dp[ed.v],dp[i]+ed.b-mid*ed.c);
        }
    }
    if (dp[n]<=0) return true;
    else return false;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,b,c; cin>>u>>v>>b>>c;
        e[u].pb((edge){v,b,c});
    }
    for (int i=1;i<=n;i++){
        for (edge ed:e[i]) du[ed.v]++;
    }
    for (int i=1;i<=n;i++){
        if (!du[i]) dfs(i);
    }
    double l=0,r=2000000000.0;
    while (l<r){
        double mid=(l+r)/2;
        if (check(mid)) r=mid-0.00000000001;
        else l=mid+0.00000000001;
    }
    printf("%0.10lf\n",l);
    return 0;
}