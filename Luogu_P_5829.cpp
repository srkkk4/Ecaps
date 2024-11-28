#include <bits/stdc++.h>
#define MAXN 1000003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
char s[MAXN];
int nxt[MAXN][23];
vector <int> e[MAXN];
int dep[MAXN];
void gd(int u){
    for (int v:e[u]){
        dep[v]=dep[u]+1;
        gd(v);
    }
    return;
}
int n,m;
int LCA(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int cha=dep[u]-dep[v];
    for (int i=20;i>=0;i--){
        if (cha&(1<<i)) u=nxt[u][i];
    }
    if (u==v) return u;
    for (int i=20;i>=0;i--){
        if (nxt[u][i]==nxt[v][i]) continue;
        u=nxt[u][i]; v=nxt[v][i];
    }
    return nxt[u][0];
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s+1; n=strlen(s+1);
    int p=0; nxt[1][0]=0; e[0].pb(1);
    for (int i=2;i<=n;i++){
        while (p>0&&s[p+1]!=s[i]) p=nxt[p][0];
        if (s[p+1]==s[i]) p=p+1;
        nxt[i][0]=p;
        e[p].pb(i);
    }
    gd(0);
    for (int i=1;i<=20;i++){
        for (int j=1;j<=n;j++){
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
        }
    }
    cin>>m;
    while (m--){
        int u,v; cin>>u>>v;
        u=nxt[u][0]; v=nxt[v][0];
        cout<<LCA(u,v)<<'\n';
    }
    return 0;
}