#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
int dp[MAXN];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=0;j--){
            if (j>=a[i]){
                dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}