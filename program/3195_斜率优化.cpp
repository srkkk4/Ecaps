#include <bits/stdc++.h>
#define MAXN 50003
using namespace std;
int n,L;
int C[MAXN]; long long s[MAXN];
long long dp[MAXN];
long long a[MAXN],b[MAXN];
int q[MAXN];
double slope(int i,int j){
    return 1.0*((dp[i]+b[i]*b[i])-(dp[j]+b[j]*b[j]))/(b[i]-b[j]);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>L;
    for (int i=1;i<=n;i++) cin>>C[i];
    for (int i=1;i<=n;i++) s[i]=s[i-1]+C[i];
    /*dp[i]=min(dp[j]+(s[i]+i-sum[j]-j-1-L)^2)
      a[i]=s[i]+i; b[j]=s[j]+j+1+L
      dp[i]=min(dp[j]+(a[i]-b[j])^2)
      dp[j]+b[j]^2=2a[i]*b[j]+dp[i]-a[i]^2
      |     y     =  k  *  x  +   b      |
    */
    for (int i=1;i<=n;i++) a[i]=s[i]+i; // a[i]单增
    for (int i=0;i<=n;i++) b[i]=s[i]+i+1+L; // b[i]单增
    int l=0,r=0; q[0]=0;
    dp[1]=dp[0]+(a[1]-b[0])*(a[1]-b[0]);
    for (int i=2;i<=n;i++){
        while (l<r&&slope(i-1,q[r])<slope(i-1,q[r-1])) r--;
        q[++r]=i-1;
        while (l<r&&slope(q[l+1],q[l])<2.0*a[i]) l++;
        int j=q[l];
        dp[i]=dp[j]+(a[i]-b[j])*(a[i]-b[j]);
    }
    cout<<dp[n]<<endl;
    return 0;
}