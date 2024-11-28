#include <bits/stdc++.h>
#define MAXN 2503
#define inf 0x3f3f3f3f3f3f3f3f
#define pb push_back
using namespace std;
int T;
int n;
int a[MAXN];
vector <int> e[MAXN];
void clear(){for (int i=1;i<=n;i++) e[i].clear(); return;}
int vis[MAXN];
struct D{
    int u;
    int val;
    bool operator<(const D &B)const{
        return val<B.val;
    }
};
long long ans;
long long sum;
void abab(int s){
    memset(vis,0,sizeof vis);
    priority_queue <D> q;
    q.push((D){s,a[s]});
    while (!q.empty()){
        D now=q.top(); q.pop();
        vis[now.u]=1;
        sum+=now.val;
        ans=min(ans,sum);
        for (int v:e[now.u]){
            if (vis[v]) continue;
            q.push((D){v,a[v]});
        }
    }
}
int main(){
    // freopen("test1.in","r",stdin);
    freopen("ceremony.in","r",stdin);
    freopen("ceremony.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        clear();
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n-1;i++){
            int u,v; cin>>u>>v;
            e[u].pb(v);
            e[v].pb(u);
        }
        for (int i=1;i<=n;i++){
            ans=inf; sum=0;
            abab(i);
            cout<<ans<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
/*
1
7
-182 -247 -360 148 -122 -116 177
1 2
1 3
3 4
3 5
2 6
2 7

*/