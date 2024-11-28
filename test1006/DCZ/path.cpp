#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
int n,m,s;
int a[MAXN],b[MAXN];
vector <int> e[MAXN];
int ANS[MAXN];
int vis[MAXN];
inline void dfs(int u,vector <int> q,int ans){
    vector <int> res;
    if (ans!=s){
        if (a[u]==b[1]) {res.push_back(1); ans=max(ans,1);}
        for (int cnt:q){
            if (a[u]==b[cnt+1]){
                res.push_back(cnt+1);
                ans=max(ans,cnt+1);
            }
        }
    }
    ANS[u]=min(ANS[u],ans);
    for (int v:e[u]){
        if (vis[v]) continue;
        vis[v]=1;
        dfs(v,res,ans);
        vis[v]=0;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    cin>>n>>m>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=s;i++) cin>>b[i];
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(ANS,0x3f,sizeof ANS);
    vis[1]=1;
    vector <int> q;
    dfs(1,q,0);
    for (int i=1;i<=n;i++) cout<<ANS[i]<<" ";
    cout<<endl;
    return 0;
}