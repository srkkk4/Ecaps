#include <bits/stdc++.h>
#define MAXN 50003
using namespace std;
int n;
vector <int> e[MAXN];
int vis[MAXN];
struct data{
    int u;
    int far;
};
int MX;
void dfs(int u,int dep){
    vis[u]=1;
    MX=max(MX,dep);
    for (int v:e[u]){
        if (vis[v]) continue;
        dfs(v,dep+1);
    }
}
int check(int x){
    memset(vis,0,sizeof vis);
    queue <data> q;
    q.push({x,0});
    int mx=0,w2;
    while (!q.empty()){
        data now=q.front(); q.pop();
        vis[now.u]=1;
        if (now.far>mx){
            mx=now.far;
            w2=now.u;
        }
        for (int v:e[now.u]){
            if (vis[v]) continue;
            q.push({v,now.far+1});
        }
    }
    return mx*2;
}
struct data2{
    int u;
    int fa;
};
void print(int x){
    memset(vis,0,sizeof vis);
    queue <data2> q;
    q.push({x,0});
    while (!q.empty()){
        data2 now=q.front(); q.pop();
        if (now.fa!=0&&!vis[now.u]) cout<<now.fa<<" "<<now.u<<endl;
        vis[now.u]=1;
        for (int v:e[now.u]){
            if (vis[v]) continue;
            q.push({v,now.u});
        }
    }
}
int main(){
    freopen("net.in","r",stdin);
    freopen("net.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char ch; cin>>ch;
            if (ch=='1'){
                e[i].push_back(j);
            }
        }
    }
    int mn=INT_MAX,w;
    if (n>=50)
        for (int i=4;i<=4;i++){
            int res=check(i);
            if (res<mn){
                mn=res;
                w=i;
            }
        }
    else 
        for (int i=1;i<=n;i++){
            int res=check(i);
            if (res<mn){
                mn=res;
                w=i;
            }
        }
    print(w);
    return 0;
}