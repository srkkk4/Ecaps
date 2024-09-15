#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,q;
int p[MAXN];
vector <int> e[MAXN];
int mark;
int cnt;
// int vis[MAXN];
void dfs(int u){
    // vis[u]=1;
    cnt++;
    for (auto v:e[u]){
        if (p[v]==cnt){
            dfs(v);
        }
    }
    // vis[u]=0;
}
int main(){
    freopen("mex.in","r",stdin);
    freopen("mex.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>p[i]; if (p[i]==0) mark=i;}
    for (int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin>>q;
    while (q--){
        int tpye; cin>>tpye;
        if (tpye==1){
            int u,v; cin>>u>>v;
            if (p[u]==0) mark=v;
            if (p[v]==0) mark=u;
            swap(p[u],p[v]);
        } else {
            cnt=0;
            dfs(mark);
            cout<<cnt<<endl;
        }
    }
    return 0;
}