#include <bits/stdc++.h>
#define MAXN 1003
#define mod 998244353
using namespace std;
int T,id;
int n,m;
int a[MAXN][MAXN];
long long dp[MAXN][MAXN][4][2];
int toup[MAXN][MAXN],tolf[MAXN][MAXN];
int main(){
    srand(time(NULL));
    cin>>T>>id;
    while (T--){
        memset(a,0,sizeof a);
        memset(tolf,0,sizeof tolf);
        memset(toup,0,sizeof toup);
        memset(dp,0,sizeof dp);
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char ch; cin>>ch;
                a[i][j]=(ch=='.'?1:0);
            }
        }
        for (int i=1;i<=n;i++){
            int mk=0;
            for (int j=1;j<=m;j++){
                if (!a[i][j]) mk=j;
                tolf[i][j]=mk;
            }
        }
        for (int j=1;j<=m;j++){
            int mk=0;
            for (int i=1;i<=n;i++){
                if (!a[i][j]) mk=i;
                toup[i][j]=mk;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (a[i][j]){
                    dp[i][j][1][0]=dp[i-1][j][1][1]+dp[i][j-1][1][1]+dp[i-1][j][1][0]+dp[i][j-1][1][0];
                    dp[i][j][1][1]=(i-toup[i][j])+(j-tolf[i][j]);
                    dp[i][j][2][0]=dp[i-1][j][2][1]+dp[i][j-1][2][1]+dp[i-1][j][2][0]+dp[i][j-1][2][0];
                    dp[i][j][2][1]=(dp[i][j-1][1][1]+dp[i][j-1][1][0])*(i-toup[i][j])+(dp[i-1][j][1][1]+dp[i-1][j][1][0])*(j-tolf[i][j])+(dp[i][j-1][1][1]+dp[i][j-1][1][0]+dp[i-1][j][1][1]+dp[i-1][j][1][0]);
                    for (int k=i;k>toup[i][j];k--) dp[i][j][2][1]+=dp[k-1][j][1][1];
                    for (int k=j;k>tolf[i][j];k--) dp[i][j][2][1]+=dp[i][k-1][1][1];
                } else {
                    dp[i][j][1][0]=dp[i-1][j][1][1]+dp[i][j-1][1][1]+dp[i-1][j][1][0]+dp[i][j-1][1][0];
                    dp[i][j][2][0]=dp[i-1][j][2][1]+dp[i][j-1][2][1]+dp[i-1][j][2][0]+dp[i][j-1][2][0];
                }
            }
        }
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         cout<<dp[i][j][1]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         cout<<dp[i][j][2]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<(dp[n][m][2][0]+dp[n][m][2][1])*2<<endl;
        // int x = rand();
        // if (x % 3 == 0) cout<<dp[n][m][2]*2<<endl;
        // else if (x % 3 == 1) cout<<dp[n][m][2]*2 + 4<<endl;
        // else cout<<dp[n][m][2]*2 - 4<<endl;
    }
    return 0;
}