#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n,s;
long long t[MAXN],c[MAXN];
long long tq[MAXN],cq[MAXN];
long long dp[MAXN];
long long a[MAXN],b[MAXN];
int Q[MAXN];
long double slope(int i,int j){
    return (long double)((dp[i]-b[i])-(dp[j]-b[j]))/(cq[i]-cq[j]);
}
bool slope_pro(int i,int j,int i2,int j2){
    return ((dp[i]-b[i])-(dp[j]-b[j]))*(cq[i2]-cq[j2])<=((dp[i2]-b[i2])-(dp[j2]-b[j2]))*(cq[i]-cq[j]);
}
int find(int l,int r,long long now_slope){
    int mid;
    while (l<=r){
        mid=(l+r)>>1;
        if (slope(Q[mid+1],Q[mid])<=now_slope) l=mid+1;
        else r=mid-1;
    }
    return Q[l];
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
        // while (l<r&&slope(i-1,Q[r])<slope(i-1,Q[r-1])) r--;
        // while (l<r&&((dp[i-1]-b[i-1])-(dp[Q[r]]-b[Q[r]]))*(cq[i-1]-cq[Q[r-1]])<((dp[i-1]-b[i-1])-(dp[Q[r-1]]-b[Q[r-1]]))*(cq[i-1]-cq[Q[r]])) r--;
        while (l<r&&slope_pro(i-1,Q[r],i-1,Q[r-1])) r--;
        Q[++r]=i-1;
        // while (l<r&&slope(Q[l+1],Q[l])<tq[i]) l++;
        int j=find(0,r-1,tq[i]);
        dp[i]=dp[j]+a[i]-b[j]-tq[i]*cq[j]+s*cq[n];
    }
    cout<<dp[n]<<endl;
    return 0;
}