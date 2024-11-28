// https://www.luogu.com.cn/problem/T508987?contestId=197293
#include <bits/stdc++.h>
#define MAXN 200003
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
int dp[MAXN];
int main(){
    cin>>T;
    while (T--){
        cin>>n>>k;
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1;i<=n;i++) cin>>p[i];
        for (int i=1;i<=n;i++) e[i].push_back(p[i]);
        for (int i=1;i<=n;i++) vis[i]=0;
        for (int i=1;i<=cnt;i++) h[i]=0;
        cnt=0;
        for (int i=1;i<=n;i++){
            if (vis[i]) continue;
            cnt++; vis[i]=1;
            dfs(i);
        }
        for (int i=0;i<=k;i++) dp[i]=0;
        dp[0]=1;
        for (int i=1;i<=cnt;i++){
            for (int j=k;j>=h[i];j--){
                dp[j]=dp[j]+dp[j-h[i]];
            }
        }
        if (dp[k]) cout<<k<<" ";
        else cout<<k+1<<" ";
        int D=0;
        for (int i=1;i<=cnt;i++){
            D+=h[i]-h[i]%2;
        }
        if (D/2>=k) cout<<min(k*2,n)<<endl;
        else cout<<min(D+(k-D/2),n)<<endl;
    }
    return 0;
}