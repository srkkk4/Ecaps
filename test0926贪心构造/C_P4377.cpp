#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;
int n,W;
int a[MAXN],b[MAXN];
double dp[1003];
bool check(double x){
    for (int i=1;i<=1001;i++) dp[i]=-100000000;
    dp[0]=0;
    for (int i=1;i<=n;i++){
        for (int j=W;j>=0;j--){
            int k = min(W,j+a[i]);
            dp[k]=max(dp[k],dp[j]+b[i]-x*a[i]);
        }
    }
    return dp[W]>0;
}
int main(){
    cin>>n>>W;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    double l=0,r=1000000,mid;
    while (l<r){
        mid=(l+r)/2.0;
        if (check(mid)) l=mid+0.000005;
        else r=mid-0.000005;
    }
    printf("%d\n",(int)(l*1000.0+0.000005));
    return 0;
}