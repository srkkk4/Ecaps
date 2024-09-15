#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN][2];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>m;
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    memset(dp,0x3f,sizeof dp); dp[0][0][0]=0; dp[0][0][1]=0;
    for (int i=1;i<=n;i++) dp[i][0][0]=dp[i-1][0][0]+(a[i]==a[i-1]?2:1);
    for (int i=1;i<=m;i++) dp[0][i][1]=dp[0][i-1][1]+(b[i]==b[i-1]?2:1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j][0]=min(dp[i-1][j][0]+(a[i-1]==a[i]?2:1),dp[i-1][j][1]+(b[j]==a[i]?2:1));
            dp[i][j][1]=min(dp[i][j-1][1]+(b[j]==b[j-1]?2:1),dp[i][j-1][0]+(b[j]==a[i]?2:1));
        }
    }
    cout<<min(dp[n][m][0],dp[n][m][1])<<endl;
    return 0;
}