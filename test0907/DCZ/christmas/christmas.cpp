#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;
int T,n,k;
int p[MAXN];
vector <int> e[MAXN];
int h[MAXN]; int cnt=0;
int vis[MAXN];
void dfs(int u){
    h[cnt]++;
    for (auto v:e[u]){
        if (vis[v]) continue;
        vis[v]=1;
        dfs(v);
    }
    return;
}
int dp[MAXN][MAXN];
int t[MAXN]; int mn,mx;
int VIS[MAXN];
void DFS(int u,int s){
    if (u==n){
        if (s!=k) return;
        for (int i=1;i<=n;i++) VIS[i]=0;
        for (int i=1;i<=n;i++){
            if (t[i]) VIS[i]=VIS[p[i]]=1;
            // cout<<t[i]<<" ";
        }
        // cout<<endl;
        int res=0;
        for (int i=1;i<=n;i++) if (VIS[i]) res++;
        mn=min(mn,res); mx=max(mx,res);
        return;
    }
    DFS(u+1,s);
    if (s<k){
        t[u+1]=1;
        DFS(u+1,s+1);
        t[u+1]=0;
    }
    return;
}
int main(){
    freopen("christmas.in","r",stdin);
    freopen("christmas.out","w",stdout);
    cin>>T;
    while (T--){
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>p[i];
        for (int i=1;i<=n;i++) e[i].push_back(p[i]);
        cnt=0;
        for (int i=1;i<=n;i++) vis[i]=0;
        for (int i=1;i<=cnt;i++) h[i]=0;
        for (int i=1;i<=n;i++){
            if (vis[i]) continue;
            cnt++; vis[i]=1;
            dfs(i);
        }
        if (n<=10&&k<=10){
            mn=INT_MAX;
            mx=0;
            DFS(1,0);
            t[1]=1;
            DFS(1,1);
            t[1]=0;
            cout<<mn<<" "<<mx<<endl;
            continue;
        }
        memset(dp,0,sizeof dp);
        std::sort(h+1,h+1+cnt);
        // for (int i=1;i<=cnt;i++) cout<<h[i]<<" ";
        // cout<<endl;
        for (int i=0;i<=cnt;i++) dp[i][0]=1;
        for (int i=1;i<=cnt;i++){
            for (int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j]+((j>=h[i])?dp[i-1][j-h[i]]:0);
            }
        }
        if (dp[cnt][k]) cout<<k<<" ";
        else cout<<k+1<<" ";
        int D=0;
        for (int i=1;i<=cnt;i++){
            D+=h[i]-h[i]%2;
        }
        if (D/2>=k) cout<<k*2<<endl;
        else cout<<k*2+(k-D/2)<<endl;
    }
    return 0;
}