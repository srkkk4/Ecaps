#include <bits/stdc++.h>
#define MAXN 253
#define mod 998244353
using namespace std;
int n,K;
long long dp[MAXN][MAXN];
long long C[MAXN][MAXN];
void inC(){
    for (int i=0;i<=251;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    return;
}
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
int main(){
    inC();
    cin>>n>>K; n--;
    dp[0][0]=1;
    for (int i=1;i<=K;i++){
        for (int j=0;j<=n;j++){
            for (int t=j;t>=0;t--){
                dp[i][j]=(dp[i][j]+dp[i-1][j-t]*C[j][t]%mod*qpow(K-i+1,t*(j-1)-C[t][2]%mod))%mod;
            }
        }
    }
    // for (int i=1;i<=K;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[K][n]<<endl;
    return 0;
}