#include <bits/stdc++.h>
#define MAXN 253
#define mod 998244353
using namespace std;
int n,K;
long long dp[MAXN][MAXN];
long long C[MAXN][MAXN];
void inC(){
    C[1][1]=1;
    for (int i=2;i<=250;i++){
        for (int j=1;j<=250;j++){
            if (j==1) C[i][j]=(C[i-1][j]+1)%mod;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j-1])%mod;
        }
    }
    return;
}
long long qpow(int x,long long y){
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
    for (int i=1;i<=n;i++){
        for (int j=1;j<=K;j++){
            for (int t=1;t<=i;t++){
                dp[i][j]=(dp[i][j]+dp[i-t][j-1]*C[i][t]*qpow(K-j+1,t*(i-1)/2))%mod;
            }
        }
    }
    long long ans=0;
    for (int i=1;i<=K;i++) ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;
    return 0;
}