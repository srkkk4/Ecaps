#include <bits/stdc++.h>
#define mod 998244353
#define MOD 2333
#define MAXN 233333
using namespace std;
int n;
int a[MAXN];
int dp[MAXN][2];
int C[2334][2334];
void init(){
    C[1][1]=C[1][2]=1;
    for (int i=2;i<=2332;i++){
        for (int j=1;j<=i+1;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    return;
}
int main(){
    freopen("product.in","r",stdin);
    freopen("product.out","w",stdout);
    init();
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[1][1]=1; dp[1][0]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i-1;j++){
            if (a[i]>a[j]) continue;
            dp[i][1]=(dp[i][1]+dp[j][1])%mod;
            dp[i][0]=(dp[i][0]+dp[j][0])%mod;
            if (C[a[j]][a[i]]!=0) dp[i][1]=(dp[i][1]+dp[j][0])%mod;
        }
    }
    int ANS=0;
    for (int i=2;i<=n;i++) ANS=(ANS+dp[i][1])%mod;
    cout<<ANS<<endl;
    return 0;
}