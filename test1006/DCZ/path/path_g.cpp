#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
int n,m,s;
int a[MAXN],b[MAXN];
vector <int> e[MAXN];
int ANS[MAXN];
struct F{
    int p;
    int fx;
    bool operator<(const F &b)const{
        return fx>b.fx;
    }
};
void bfs(int s){
    priority_queue <F> q;
    q.push({s,0}); ANS[s]=0;
    while (!q.empty()){
        F x=q.top(); q.pop();
        for (int y:e[x.p]){
            int fy;
            if (b[x.fx+1]==a[y]) fy=x.fx+1;
            else fy=x.fx;
            if (fy<ANS[y]){
                ANS[y]=fy;
                q.push({y,fy});
            }
        }
    }
    return;
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
    e[0].push_back(1);
    memset(ANS,0x3f,sizeof ANS);
    bfs(0);
    for (int i=1;i<=n;i++) cout<<ANS[i]<<" ";
    cout<<endl;
    return 0;
}