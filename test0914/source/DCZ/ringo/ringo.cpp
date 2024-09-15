#include <bits/stdc++.h>
#define MAXN 1003
#define mod 998244353
using namespace std;
int T,id;
int n,m;
int a[MAXN][MAXN];
long long dp[MAXN][MAXN][3];
long long qpow(long long x,int y){
    long long res=1;
    while (y){
        if (y%2) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
int main(){
    freopen("ringo.in","r",stdin);
    freopen("ringo.out","w",stdout);
    cin>>T>>id;
    while (T--){
        cin>>n>>m;
        // for (int i=1;i<=n+1;i++){
        //     for (int j=1;j<=m+1;j++){
        //         a[i][j]=0;
        //         dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
        //     }
        // }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char ch; cin>>ch;
                a[i][j]=(ch=='.'?1:0);
                // dp[i][j][0]=(ch=='.'?2:0);
            }
        }
        // cout<<2*n*m-1<<endl;
        cout<<qpow(2,2*n*m-1)<<endl;
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         dp[i][j][1]=(max(max(dp[i-1][j][1],1ll)*max(dp[i][j-1][0],1ll)+dp[i-1][j][0],1ll))%mod;
        //         dp[i][j][2]=(max(max(dp[i][j-1][2],1ll)*max(dp[i-1][j][0],1ll)+dp[i][j-1][0],1ll))%mod;
        //         dp[i][j][0]=(dp[i][j][1]+dp[i][j][2])%mod;
        //     }
        // }
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         cout<<dp[i][j][0]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         cout<<dp[i][j][1]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         cout<<dp[i][j][2]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<(0ll+dp[n][m][0])%mod<<endl;
    }
    return 0;
}