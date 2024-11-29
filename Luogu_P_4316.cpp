#include <bits/stdc++.h>
#define MAXN 100003
#define MAXM 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
struct edge{
    int v;
    long long w;
};
vector <int> e1[MAXN],e2[MAXN];
struct EDGE{
    int u; int v; long long w;
}E[MAXM];
double dp1[MAXN],dp2[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; long long w; cin>>u>>v>>w;
        e1[u].pb((edge){v,w});
        e2[v].pb((edge){u,w});
        E[i]=(EDGE){u,v,w};
    }
    
    long long ans=0;
    for (int i=1;i<=m;i++){

    }
    return 0;
}