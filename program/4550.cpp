#include <bits/stdc++.h>
#define MAXN 10003
using namespace std;
int n;
double dp[MAXN],dp2[MAXN];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1.0*n/(n-i+1);
        dp2[i]=dp2[i-1]+1.0*dp[i]*n/(n-i+1);
    }
    printf("%0.2lf\n",dp2[n]);
    return 0;
}