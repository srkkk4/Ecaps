#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,q;
int p[MAXN];
vector <int> e[MAXN];
int mark[MAXN];
int cnt;
int vis[MAXN];
int fa[MAXN];
void dfs(int u){
    vis[u]=1;
    for (auto v:e[u]){
        if (vis[v]) continue;
        fa[v]=u;
        dfs(v);
    }
    vis[u]=0;
    return;
}
int ru[MAXN],chu[MAXN];
int main(){
    freopen("mex.in","r",stdin);
    freopen("mex.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>p[i]; mark[p[i]]=i;}
    // for (int i=0;i<=n-1;i++) cout<<mark[i]<<" ";
    // cout<<endl;
    for (int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(mark[0]); fa[mark[0]]=mark[0];
    cin>>q;
    while (q--){
        int tpye=0; cin>>tpye;
        if (tpye==1){
            // cout<<"ok\n";
            int u,v; cin>>u>>v;
            swap(p[u],p[v]);
            swap(mark[p[u]],mark[p[v]]);
            if (p[u]==0||p[v]==0){
                dfs(mark[0]); fa[mark[0]]=mark[0];
            }
        } else {
            for (int i=1;i<=n;i++) ru[i]=0,chu[i]=0;
            int ok=0;
            cnt=1;
            for (;cnt<=n-1;cnt++){
                // cout<<">:"<<mark[1]<<endl;
                // cout<<"cnt:"<<cnt<<endl<<"x:";
                int x=mark[cnt];
                while (x!=fa[x]){
                    // cout<<x<<" ";
                    if (ru[fa[x]]==1&&fa[x]!=mark[0]){
                        ok=1;
                        break;
                    }
                    if (ru[fa[x]]==2&&fa[x]==mark[0]){
                        ok=1;
                        break;
                    }
                    chu[x]++;
                    ru[fa[x]]++;
                    if (chu[fa[x]]){
                        break;
                    }
                    x=fa[x];
                }
                // cout<<endl;
                if (ok) break;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}