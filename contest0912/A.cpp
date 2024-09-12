#include <bits/stdc++.h>
#define MAXN 503
#define MAXM 100003
using namespace std;
int n,m;
vector <int> e[MAXN];
struct edge{
    int u; int v;
};
edge ed[MAXM]; int cnt;
int mk[MAXN];
int vis[MAXN];
int dfs(int u,int t){
    vis[u]=1;
    int ok=0;
    for (auto v:e[u]){
        if (v==t){
            ok=1;
        }
        if (vis[v]) continue;
        if (dfs(v,t)){
            ok=1;
        }
    }
    vis[u]=0;
    if (ok) {mk[u]=1; return 1;}
    return 0;
}
int h;
int vis2[MAXN];
int mk2[MAXN];
int dfs2(int u,int t){
    if (u==t){
        mk2[u]=1;
        h++;
        return 1;
    }
    vis2[u]=1;
    int ok=0;
    for (auto v:e[u]){
        if (vis2[v]) continue;
        if (dfs2(v,t)){
            ok=1;
        }
    }
    vis2[u]=0;
    if (ok) {mk2[u]=1; return 1;}
    return 0;
}
int cnt_ed[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        ed[++cnt]={u,v};
        cnt_ed[u][v]=1;
    }
    int tot=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            if (cnt_ed[j][i]&&cnt_ed[i][j]) tot++;
        }
    }
    if (tot>=2){
        cout<<"NO\n";
        return 0;
    } else if (tot==1){
        // cout<<"ok\n";
        for (int i=1;i<=n;i++){
            // memset(vis,0,sizeof vis);
            dfs(i,i);
        }
        int sum=0;
        for (int i=1;i<=n;i++){
            if (mk[i]) sum++;
        }
        // cout<<"sum:"<<sum<<endl;
        for (int i=1;i<=n;i++){
            for (int j=1;j<i;j++){
                if (cnt_ed[j][i]&&cnt_ed[i][j]){
                    // cout<<i<<" "<<j<<endl;
                    dfs2(i,j);
                    int now=0;
                    for (int k=1;k<=n;k++){
                        if (mk2[k]) now++;
                    }
                    // cout<<"now1:"<<now<<endl;
                    if (now==sum){
                        cout<<"YES\n";
                        return 0;
                    }
                    // memset(mk2,0,sizeof mk2);
                    dfs2(j,i);
                    now=0;
                    for (int k=1;k<=n;k++){
                        if (mk2[k]) now++;
                    }
                    // cout<<"now2:"<<now<<endl;
                    if (now==sum){
                        cout<<"YES\n";
                        return 0;
                    }
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    } else {
        for (int i=1;i<=n;i++){
            // memset(vis,0,sizeof vis);
            dfs(i,i);
        }
        int sum=0;
        for (int i=1;i<=n;i++){
            if (mk[i]) sum++;
        }
        for (int i=1;i<=m;i++){
            memset(mk2,0,sizeof mk2);
            // memset(vis2,0,sizeof vis2);
            h=0;
            dfs2(ed[i].v,ed[i].u);
            int now=0;
            for (int i=1;i<=n;i++){
                if (mk2[i]) now++;
            }
            if (now==sum){
                cout<<"YES\n";
                return 0;
            }
        }
        cout<<"NO\n";
    }
    return 0;
}