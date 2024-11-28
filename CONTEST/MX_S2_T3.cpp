#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,p;
long long dp[MAXN][MAXN];//dp[i][j]
int main(){
    cin>>n>>p;
    for (int j=1;j<=n;j++){
        dp[0][j]=1;
    }
    for (int i=1;i<=n-1;i++){
        for (int j=n-1;j>=1;j--){
            for (int k=j;k<=n;k+=j){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%p;
            }
            if (j-1>=2) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%p;
            if (j+1<=n) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%p;
        }
    }
    long long ans=0;
    for (int i=1;i<=n-1;i++){
        ans=(ans+dp[i][1])%p;
    }
    cout<<ans<<endl;
    return 0;
}