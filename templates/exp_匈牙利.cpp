#include <bits/stdc++.h>
#define MAXN 503
using namespace std;
int n,m,E;
vector <int> e[MAXN];
int from[MAXN<<1];
int vistime[MAXN];
int find(int u,int time){
    if (vistime[u]==time) return 0;
    vistime[u]=time;
    for (auto v:e[u]){
        if (!from[v]){
            return v;
        }
    }
    for (auto v:e[u]){
        int v2=find(from[v],time);
        if (v2){
            from[v2]=from[v];
            return v;
        }
    }
    return 0;
}
int flag[MAXN][MAXN];
int main(){
    cin>>n>>m>>E;
    for (int i=1;i<=E;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        if (flag[u][v]) continue;
        flag[u][v]=1;
        e[u].push_back(n+v);
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        int v=find(i,i);
        if (v){
            from[v]=i;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}