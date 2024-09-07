// https://www.luogu.com.cn/problem/T508983?contestId=197293
#include <bits/stdc++.h>
#define mod 998244353
#define MOD 2333
#define MAXN 233333
using namespace std;
int n;
int a[MAXN];
int dp[MAXN][2];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[1][1]=1; dp[1][0]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i-1;j++){
            if (a[i]>a[j]) continue;
            dp[i][1]=(dp[i][1]+dp[j][1])%mod;
            dp[i][0]=(dp[i][0]+dp[j][0])%mod;
            if (a[j]%MOD!=0) dp[i][1]=(dp[i][1]+dp[j][0])%mod;
        }
    }
    for (int i=1;i<=n;i++) cout<<dp[i][1]<<" ";
    cout<<endl;
    int ANS=0;
    for (int i=2;i<=n;i++) ANS=(ANS+dp[i][1])%mod;
    cout<<ANS<<endl;
    return 0;
}