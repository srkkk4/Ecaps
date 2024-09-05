#include <bits/stdc++.h>
#define MAXN 22
using namespace std;
int n,m;
vector <int> e[MAXN];
long long dp[1000003][MAXN];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        dp[1<<(i-1)][i]=1;
    }
    long long ans=0;
    for (int i=1;i<=(1<<n)-1;i++){
        int s=1;
        while (!(i&(1<<(s-1)))) s++;
        for (int j=1;j<=n;j++){
            if (!dp[i][j]) continue;
            // if (!(i&&1<<(j-1))) continue;
            for (auto k:e[j]){
                if (k<s) continue;
                if (i&1<<(k-1)){
                    if (k==s){
                        ans+=dp[i][j];
                    }
                } else {
                    dp[i|(1<<(k-1))][k]+=dp[i][j];
                }
            }
        }
    }
    cout<<(ans-m)/2<<endl;
    return 0;
}