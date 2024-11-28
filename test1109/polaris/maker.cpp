#include <bits/stdc++.h>
using namespace std;
int vis[16];
int q[16],cnt;
map <int,bool> mp;
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    // int n=rand()%12+4; int m=rand()%(n*(n-1)/2-(n-1)+1)+n;
    int n=7,m=9;
    cout<<n<<" "<<m<<'\n';
    // cerr<<n<<" "<<m<<'\n';
    int s=rand()%n+1;
    q[++cnt]=s; vis[s]=1;
    for (int i=1;i<=n-1;i++){
        int u=rand()%cnt+1;
        int v=rand()%n+1;
        while (vis[v]||mp[q[u]*100+v]) v=rand()%n+1;
        q[++cnt]=v; vis[v]=1;
        cout<<q[u]<<" "<<v<<'\n';
        mp[100*q[u]+v]=mp[100*v+q[u]]=1;
    }
    for (int i=n;i<=m;i++){
        int u=rand()%n+1,v=rand()%n+1;
        while (u==v||mp[u*100+v]) {u=rand()%n+1;v=rand()%n+1;}
        cout<<u<<" "<<v<<'\n';
    }
    return 0;
}