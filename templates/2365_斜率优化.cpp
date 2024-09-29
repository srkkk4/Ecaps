#include <bits/stdc++.h>
#define MAXN 50003
using namespace std;
int n,s;
long long t[MAXN],c[MAXN];
long long tq[MAXN],cq[MAXN];
long long dp[MAXN];
long long a[MAXN],b[MAXN];
int Q[MAXN];
double slope(int i,int j){
    return 1.0*((dp[i]-b[i])-(dp[j]-b[j]))/(cq[i]-cq[j]);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>t[i]>>c[i];
    for (int i=1;i<=n;i++) tq[i]=tq[i-1]+t[i];
    for (int i=1;i<=n;i++) cq[i]=cq[i-1]+c[i];
    for (int i=1;i<=n;i++) a[i]=tq[i]*cq[i];
    for (int i=1;i<=n;i++) b[i]=s*cq[i];
    int l=0,r=0;
    dp[1]=dp[0]+a[1]-b[0]-tq[1]*cq[0]+s*cq[n];
    for (int i=2;i<=n;i++){
        while (l<r&&slope(i-1,Q[r])<slope(i-1,Q[r-1])) r--;
        Q[++r]=i-1;
        while (l<r&&slope(Q[l+1],Q[l])<tq[i]) l++;
        int j=Q[l];
        dp[i]=dp[j]+a[i]-b[j]-tq[i]*cq[j]+s*cq[n];
    }
    cout<<dp[n]<<endl;
    return 0;
}