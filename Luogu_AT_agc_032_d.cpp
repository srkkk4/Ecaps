#include <bits/stdc++.h>
#define MAXN 5003
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,A,B;
int a[MAXN];
long long dp[MAXN][MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>A>>B;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i]>j) dp[i][j]=dp[i-1][j]+A;
            if (a[i]==j){
                long long mn=inf;
                for (int k=1;k<=a[i];k++) mn=min(mn,dp[i-1][k]);
                dp[i][j]=mn;
            }
            if (a[i]<j) dp[i][j]=dp[i-1][j]+B;
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    long long ans=inf;
    for (int i=1;i<=n;i++){
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<'\n';
    return 0;
}